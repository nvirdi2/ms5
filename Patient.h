// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H

#include <iostream>

#include "IOAble.h"
#include "Ticket.h"

namespace sdds 
{
    class Patient: public IOAble 
    {
            Ticket object;

            char* m_name = nullptr;
            int o_num;
            bool flag;

        public:
            Patient(int NUM = 0, bool check = false);
            ~Patient();
            Patient(const Patient&) = delete;

            void operator=(const Patient&) = delete;
            void getSpecs(std::istream&);
            void fileIO(bool);
            void setArrivalTime();

            bool operator ==(char) const;
            bool operator ==(const Patient&) const;
            bool fileIO() const;

            std::istream& read(std::istream& is);
            std::istream& csvRead(std::istream& is);
            std::ostream& write(std::ostream& os) const;
            std::ostream& csvWrite(std::ostream& os) const;

            virtual char type() const = 0;
            
            int number() const;

            operator Time() const;
    };
}
#endif //!SDDS_PATIENT_H
