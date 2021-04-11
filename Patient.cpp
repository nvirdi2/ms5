#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "utils.h"
#include <cstring>
#include <string>
namespace sdds {
    Patient::Patient(int number, bool flag):obj(number)
    {
        io_flag = flag;
    }
    Patient::~Patient()
    {
        delete[] m_pname;
    }
    bool Patient::fileIO() const
    {
        return io_flag;
    }
    void Patient::fileIO(bool flag)
    {
        io_flag = flag;
    }
    bool Patient::operator ==(char ch) const
    {
        return ch == type();
    }
    bool Patient::operator ==(const Patient& other) const
    {
        return type() == other.type();
    }
    void Patient::setArrivalTime()
    {
        obj.resetTime();
    }
    Patient::operator Time() const
    {
        return Time(obj);
    }
    int Patient::number() const
    {
        return obj.number();
    }
    std::ostream& Patient::csvWrite(std::ostream& ostr) const
    {
        ostr << type() << ',';
        ostr <<m_pname << ',';
        ostr << ohip_no << ',';
        return obj.csvWrite(ostr);
    }
    std::istream& Patient::csvRead(std::istream& istr)
    {
        std::string name = "";
        istr.ignore();
        getline(istr, name, ',');
        int len = name.length();
        delete[] m_pname;
        m_pname = new char[len + 1];
        strcpy(m_pname, name.c_str());
        m_pname[len] = '\0';
        
        istr >> ohip_no;
        istr.ignore();
        return obj.csvRead(istr);
    }
    std::ostream& Patient::write(std::ostream& ostr) const
    {
        ostr << obj << '\n';
        for(int i = 0; i<25 && m_pname[i]; i++)
        {
            ostr << m_pname[i];
        }
        ostr << ", OHIP: ";
        ostr << ohip_no;
        return ostr;
    }
    std::istream& Patient::read(std::istream& istr)
    {
        std::cout << "Name: ";
        
        std::string name;
        std::getline(istr, name);
        int len = name.length();
        delete[] m_pname;
        m_pname = new char[len + 1];
        strcpy(m_pname, name.c_str());
        m_pname[len] = '\0';

        std::cout << "OHIP: ";
        ohip_no = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");
        return istr;
    }
}
