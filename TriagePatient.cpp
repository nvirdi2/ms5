// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

#include "TriagePatient.h"

namespace sdds 
{
    TriagePatient::~TriagePatient() 
    {
        delete[] symptoms;
    }
    
    char TriagePatient::type() const 
    {
        return 'T';
    }

    std::istream& TriagePatient::read(std::istream& is) 
    {
        if (!(fileIO()))
        {
            delete[] symptoms;

            Patient::read(is);
            std::cout << "Symptoms: ";

            std::string str;
            std::getline(is, str);

            int lenght;

            lenght = str.length();
            symptoms = new char[lenght + 1];

            strcpy(symptoms, str.c_str());

            symptoms[lenght] = '\0';
        } 
        
        else
        {
            csvRead(is);
        } return is;
    }

    std::ostream& TriagePatient::write(std::ostream& os) const 
    {
        if (!(fileIO()))
        {
            os << "TRIAGE" << std::endl;

            Patient::write(os);

            os << std::endl;

            os << "Symptoms: " << symptoms << std::endl;
        }
        
        else
        {
            csvWrite(os);
        } return os;
    }

    std::ostream& TriagePatient::csvWrite(std::ostream& os) const 
    {
        Patient::csvWrite(os);
            return os << ',' << symptoms;
    }
    
    int T_Ticket = 1;
    
    TriagePatient::TriagePatient() :Patient(T_Ticket) 
    {
        symptoms = nullptr;
            T_Ticket++;
    }

    std::istream& TriagePatient::csvRead(std::istream& is) 
    {
        delete[] symptoms;

        Patient::csvRead(is);
        is.ignore();

        std::string str;

        std::getline(is, str, '\n');

        int lenght;

        lenght = str.length();

        symptoms = new char[lenght + 1];
        strcpy(symptoms, str.c_str());
        
        symptoms[lenght] = '\0';
        T_Ticket = Patient::number() + 1;

            return is;
    }
}
