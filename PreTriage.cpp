// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include <cstring>
#include <string>

#include "PreTriage.h"

using namespace std;

namespace sdds 
{
    PreTriage::PreTriage(const char* dataFilename):
    m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit",2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage",2)
    {
        int lenght;

        lenght = strlen(dataFilename);
            m_dataFilename = new char[lenght + 1];

        strcpy(m_dataFilename, dataFilename);
            m_dataFilename[lenght] = '\0';

        m_averCovidWait = 15;
            m_averTriageWait = 5;

        load();
    }

    PreTriage::~PreTriage()
    {
        ofstream fout(m_dataFilename);
        int x;

        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;

        fout << m_averCovidWait << "," << m_averTriageWait << endl;

        cout << "Saving m_lineup..." << endl;

        for(x = 0; x < m_lineupSize; x++)
        {
            cout << x+1 << "- "; 

            m_lineup[x]->csvWrite(cout) << endl; 
            m_lineup[x]->csvWrite(fout) << endl;
        }

        for(x = 0; x<m_lineupSize; x++)
        {
            delete m_lineup[x];
        }

        delete[] m_dataFilename;

        cout << "done!" << endl;
            fout.close();
    }




    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement
            (m_lineup, index, m_lineupSize);
    }


    void PreTriage::run(void)
    {
        while(true)
        {
            int UserInput;
            m_appMenu >> UserInput;

            if(UserInput == 0)
            {
                return;
            }

                if(UserInput == 1)
                {
                    reg();
                }

                    if(UserInput == 2)
                    {
                        admit();
                    }
        }
    }

    void PreTriage::admit()
    {
        int UserInput;
        int indx;
        char TypeIs = '\0';

        m_pMenu >> UserInput;

        if(UserInput == 0)
        {
            return;
        }

            if(UserInput == 1)
            {
                TypeIs = 'C';   
            }

                if(UserInput == 2)
                {
                    TypeIs = 'T';
                }

        indx = indexOfFirstInLine(TypeIs);

            if(indx == -1)
            {
                return;
            }

        cout << endl << "******************************************" << endl;

            m_lineup[indx]->fileIO(false);
        
        cout << "Calling for ";
        
            cout << *m_lineup[indx];

        cout << "******************************************" << endl << endl;
        
            setAverageWaitTime(*m_lineup[indx]);
            removePatientFromLineup(indx);
    }

    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        unsigned int PTN;

        Time CT = Time(getTime());    //CT: Current Time
        Time PTT = Time(p);    //PTT: Patient's Ticket Time
        Time AWT = p.type() == 'C' ? m_averCovidWait : m_averTriageWait; //AWT: Average Wait Time (Covid or Triage)

        PTN =  p.number();    //PTN: Patient's Ticket Number
        AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;  //AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN

        if(p.type() == 'C')
        {
            m_averCovidWait = AWT;
        }

        else
        {
            m_averTriageWait = AWT;
        }
    }

    void PreTriage::reg()
    {
        int UserInput;

        if(m_lineupSize == maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            return;
        }

        m_pMenu >> UserInput;

        if(UserInput == 0)
        {
            return;
        }

            if(UserInput == 1)
            {
                m_lineup[m_lineupSize] = new CovidPatient();
            }

                if(UserInput == 2)
                {
                    m_lineup[m_lineupSize] = new TriagePatient();
                }

            m_lineup[m_lineupSize]->setArrivalTime();

        cout << "Please enter patient information: " << endl;
        
            m_lineup[m_lineupSize]->fileIO(false);
            m_lineup[m_lineupSize]->read(cin);
        
        cout << endl << "******************************************" << endl;
        
            cout << *m_lineup[m_lineupSize];
        
        cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);
        cout << endl << "******************************************" << endl << endl;
        
            m_lineupSize++;
    }

    void PreTriage::load()
    {
        int x;

        cout << "Loading data..." << endl;

        ifstream fin(m_dataFilename);
        fin >> m_averCovidWait;

        fin.ignore();

        fin >> m_averTriageWait;

        fin.ignore();

        Patient *ptr = NULL;

        for(x = 0; x < maxNoOfPatients && fin.peek() != EOF; x++)
        {
            char Character;

            fin >> Character;

            if(Character == 'T')
            {
                ptr = new TriagePatient();
            }

            if(Character == 'C')
            {
                ptr = new CovidPatient();
            }

            if(ptr != NULL)
            {
                ptr->fileIO(true);

                    fin >> *ptr;

                ptr->fileIO(false);

                m_lineup[x] = ptr;
                m_lineupSize++;
            }
        }

        if(fin.peek() != EOF)
        {
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        }

        else if(m_lineupSize == 0)
        {
            cout << "No data or bad data file!" << endl;
        }

        if(m_lineupSize > 0)
        {
            cout << m_lineupSize << " Records imported..." << endl;
        }

            cout << endl;
    }




    int PreTriage::indexOfFirstInLine(char type) const
    {
        int x;

        for(x = 0; x<m_lineupSize; x++)
        {
            if(type == m_lineup[x]->type())
            {
                return x;
            }
        } return -1;
    }




    const Time PreTriage::getWaitTime(const Patient& p)const
    {
        unsigned int count = 0;
        int x;

        Time result;

        for(x = 0; x < m_lineupSize; x++)
        {
            if(p.type() == m_lineup[x]->type())
            {
                count++;
            }
        }

        if(p.type() != 'C')
        {
            result = m_averTriageWait * count;
        }

        else
        {
            result = m_averCovidWait * count;
        } return result;
    }
}
