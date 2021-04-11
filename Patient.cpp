// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string>

#include "utils.h"
#include "Patient.h"

namespace sdds 
{
    Patient::Patient(int NUM, bool check):object(NUM) 
    {
        flag = check;
    }
    Patient::~Patient() 
    {
        delete[] m_name;
    }



    void Patient::fileIO(bool check) 
    {
        flag = check;
    }
    void Patient::setArrivalTime() 
    {
        object.resetTime();
    }


    bool Patient::operator ==(char x) const 
    {
            return x == type();
    }
    bool Patient::operator ==(const Patient& any) const 
    {
            return type() == any.type();
    }
    bool Patient::fileIO() const 
    {
            return flag;
    }



    std::istream& Patient::read(std::istream& is) 
    {
        std::cout << "Name: ";
        std::string Name;
        std::getline(is, Name);

        int lenght = Name.length();

        delete[] m_name;
        m_name = new char[lenght + 1];
        strcpy(m_name, Name.c_str());

        m_name[lenght] = '\0';

        std::cout << "OHIP: ";
        o_num = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");
        
            return is;
    }



    std::istream& Patient::csvRead(std::istream& is) 
    {
        int lenght;

        std::string Name;
        is.ignore();
        getline(is, Name, ',');

        
        lenght = Name.length();

        delete[] m_name;

        m_name = new char[lenght + 1];
        strcpy(m_name, Name.c_str());

        m_name[lenght] = '\0';
        
        is >> o_num;
        is.ignore();

            return object.csvRead(is);
    }



    std::ostream& Patient::write(std::ostream& os) const
    {
        int i;

        os << object << '\n';

        for(i = 0; i < 25 && m_name[i]; i++)
        {
            os << m_name[i];
        }

        os << ", OHIP: ";
        os << o_num;

            return os;
    }
    std::ostream& Patient::csvWrite(std::ostream& os) const 
    {
        os << type() << ',';
        os <<m_name << ',';
        os << o_num << ',';

            return object.csvWrite(os);
    }



    int Patient::number() const 
    {
            return object.number();
    }



    Patient::operator Time() const 
    {
            return Time(object);
    }
}
