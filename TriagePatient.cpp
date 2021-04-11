#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <iostream>
#include <string>
#include <cstring>

namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient():Patient(nextTriageTicket)
   {
      m_symptoms = nullptr;
      nextTriageTicket++;
   }
   TriagePatient::~TriagePatient()
   {
      delete[] m_symptoms;
   }
   char TriagePatient::type() const
   {
      return 'T';
   }
   std::istream& TriagePatient::read(std::istream& istr)
   {
      if(fileIO())
      {
         csvRead(istr);
      }
      else 
      {
         delete[] m_symptoms;
         Patient::read(istr);
         std::cout << "Symptoms: ";
         std::string str;
         std::getline(istr, str);
         int len = str.length();
         m_symptoms = new char[len + 1];
         strcpy(m_symptoms, str.c_str());
         m_symptoms[len] = '\0';
      }
      return istr;
   }
   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
      if(fileIO())
      {
         csvWrite(ostr);
      }
      else
      {
         ostr << "TRIAGE" << std::endl;
         Patient::write(ostr);
         ostr << std::endl;
         ostr << "Symptoms: " << m_symptoms << std::endl;
      }
      return ostr;
   }
   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
      delete[] m_symptoms;
      Patient::csvRead(istr);
      istr.ignore();
      std::string str;
      std::getline(istr,str,'\n');
      int len = str.length();
      m_symptoms = new char[len + 1];
      strcpy(m_symptoms, str.c_str());
      m_symptoms[len] = '\0';
      nextTriageTicket = Patient::number() + 1;
      return istr;
   }
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
   {
      Patient::csvWrite(ostr);
      return ostr << ',' << m_symptoms;
   }
}
