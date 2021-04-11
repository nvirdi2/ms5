// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds 
{
    class TriagePatient : public Patient 
    {
    private:
        char* symptoms;

    public:
       ~TriagePatient();
        TriagePatient();

        char type() const;

        std::istream& read(std::istream& is);
        std::istream& csvRead(std::istream& is);

        std::ostream& write(std::ostream& os) const;
        std::ostream& csvWrite(std::ostream& os) const;
    };
}
#endif //!SDDS_TRIAGEPATIENT_H


