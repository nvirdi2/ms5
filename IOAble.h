// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

namespace sdds 
{
    class IOAble 
    {
    public:
        virtual std::istream& csvRead(std::istream&) = 0;
        virtual std::ostream& csvWrite(std::ostream&) const = 0;

        virtual std::istream& read(std::istream&) = 0;
        virtual std::ostream& write(std::ostream&) const = 0;
        
        virtual ~IOAble() {};
    };
    std::istream& operator>>(std::istream& L, IOAble& Object);
    std::ostream& operator<<(std::ostream& L, const IOAble& Object);
}
#endif //!SDDS_IOABLE_H
