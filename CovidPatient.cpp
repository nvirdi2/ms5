// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "CovidPatient.h"

namespace sdds 
{
    char CovidPatient::type() const
    {
        return 'C';
    }
    
    std::istream& CovidPatient::read(std::istream& is) 
    {
        return fileIO() ? csvRead(is) : Patient::read(is);
    }

    std::ostream& CovidPatient::write(std::ostream& os) const 
    {
        if (!(fileIO())) 
        {
            os << "COVID TEST" << std::endl;
            Patient::write(os);
            os << std::endl;
        }
        
        else 
        {
            csvWrite(os);
        } return os;
    }
    
    int C_Ticket = 1;
    
    CovidPatient::CovidPatient() :Patient(C_Ticket) 
    {
            C_Ticket++;
    }

    std::istream& CovidPatient::csvRead(std::istream& is) 
    {      
        Patient::csvRead(is);
        C_Ticket = Patient::number() + 1;
            return is;
    }

}
