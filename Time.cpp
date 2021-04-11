#include "Time.h"
#include "utils.h"
#include <string>
using namespace std;
namespace sdds {
    Time& Time::setToNow()
    {
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min)
    {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const
    {
        unsigned int hours = m_min / 60;
        unsigned int mins = m_min - hours * 60;
        if(hours < 10)
            ostr << "0";
        ostr << hours << ":";
        if(mins < 10)
            ostr << "0";
        ostr << mins;
        return ostr;
    }
    std::istream& Time::read(std::istream& istr)
    {
        int hours = 0;
        int minutes = 0;
        char ch = '\0';

        istr >> hours;
        if(hours < 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        istr >> ch;
        if(ch != ':')
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        istr >> minutes;
        if(minutes < 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        // if(input_time.length() == 0)
        // {
        //     istr.setstate(ios::failbit);
        //     return istr;
        // }
        // for(int i = 0; input_time[i] != '\0'; i++)
        // {
        //     if((input_time[i] < '0' || input_time[i] > '9') && input_time[i] != ':')
        //     {
        //         istr.setstate(ios::failbit);
        //         return istr;
        //     }
        // }

        // hours = stoi(input_time.substr(0,input_time.find(':')));
        // minutes = stoi(input_time.substr(input_time.find(':') + 1));
        
        // if(hours < 0 || minutes < 0)
        //     istr.setstate(ios::failbit);
        // else 
        m_min = hours * 60 + minutes;
        return istr;
    }
    Time& Time::operator-= (const Time& D)
    {
        int mins_in_day = 24 * 60;
        int min_a = (int)(*this);
        int min_b = (int)(D);
        int diff = (((min_a - min_b) % mins_in_day ) + mins_in_day) % mins_in_day;
        m_min = diff;

        return *this;
    }
    Time Time::operator-(const Time& D)const
    {
        int mins_in_day = 24 * 60;
        
        Time ret;
        int min_a = (int)(*this);
        int min_b = (int)(D);
        int diff = (((min_a - min_b) % mins_in_day ) + mins_in_day) % mins_in_day;
        ret.m_min = diff;

        return ret;
    }
    Time& Time::operator+=(const Time& D)
    {
        m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const
    {
        Time ret;
        ret.m_min = m_min + D.m_min;
        return ret;
    }
    Time& Time::operator=(unsigned int val)
    {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val)
    {
        m_min *= val;
        return *this;
    }
    Time Time::operator *(unsigned int val) const
    {
        Time ret;
        ret.m_min = m_min * val;
        return ret;
    }
    Time& Time::operator /= (unsigned int val)
    {
        m_min /= val;
        return *this;
    }
    Time Time::operator /(unsigned int val)const
    {
        Time ret;
        ret.m_min = m_min / val;
        return ret;
    }
    Time::operator int()const
    {
        return (int)m_min;
    }
    Time::operator unsigned int()const
    {
        return m_min;
    }
    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        D.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Time& D)
    {
        D.read(istr);
        return istr;
    }
}
