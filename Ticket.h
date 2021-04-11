// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_

#include "IOAble.h"
#include "Time.h"

namespace sdds 
{
   class Ticket:public IOAble 
   {
      Time time;
      int num;
   public:
      Ticket(int NUM = 0);

      void resetTime();

      std::istream& read(std::istream& is);
      std::istream& csvRead(std::istream& is);

      std::ostream& csvWrite(std::ostream& os)const;
      std::ostream& write(std::ostream& os )const;

      operator Time()const;

      int number()const;
   };
}
#endif //!SDDS_TICKET_H_
