// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>

#include "Ticket.h"

namespace sdds 
{
   Ticket::Ticket(int NUM) 
   {
      num = NUM;
   }



   void Ticket::resetTime() 
   {
      time.setToNow();
   }



   std::istream& Ticket::read(std::istream& is) 
   {
         return csvRead(is);
   }
   std::istream& Ticket::csvRead(std::istream& is) 
   {
      is >> num;
      is.ignore();
         return is >> time;
   }



   std::ostream& Ticket::write(std::ostream& os) const 
   {
         return os << "Ticket No: " << num << ", Issued at: " << time ;
   }
   std::ostream& Ticket::csvWrite(std::ostream& os) const 
   {
         return os << num << "," << time;
   }



   Ticket::operator Time() const 
   {
         return time;
   }



   int Ticket::number() const 
   {
         return num;
   }
}
