#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
#include <iostream>
namespace sdds {
    class Patient: public IOAble{
            char* m_pname = nullptr;
            int ohip_no;
            Ticket obj;
            bool io_flag;
        public:
            Patient(int number = 0, bool flag = false);
            ~Patient();
            Patient(const Patient&) = delete;
            void operator=(const Patient&) = delete;
            void getSpecs(std::istream&);
            virtual char type() const = 0;
            bool fileIO() const;
            void fileIO(bool);
            bool operator ==(char) const;
            bool operator ==(const Patient&) const;
            void setArrivalTime();
            operator Time() const;
            int number() const;
            std::istream& read(std::istream& istr);
            std::ostream& write(std::ostream& ostr) const;
            std::istream& csvRead(std::istream& istr);
            std::ostream& csvWrite(std::ostream& ostr) const;
    };
}
#endif
