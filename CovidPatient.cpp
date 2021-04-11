#define _CRT_SECURE_NO_WARNINGS
#include "CovidPatient.h"
#include <iostream>

namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient():Patient(nextCovidTicket)
   {
      nextCovidTicket++;
   }
   char CovidPatient::type() const
   {
      return 'C';
   }
   std::istream& CovidPatient::read(std::istream& istr)
   {
      return fileIO() ? csvRead(istr) : Patient::read(istr);
   }
   std::ostream& CovidPatient::write(std::ostream& ostr) const
   {
      if(fileIO())
      {
         csvWrite(ostr);
      }
      else
      {
         ostr << "COVID TEST" << std::endl;
         Patient::write(ostr);
         ostr << std::endl;
      }
      return ostr;
   }
   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
      Patient::csvRead(istr);
      nextCovidTicket = Patient::number() + 1;
      return istr;
   }
}
