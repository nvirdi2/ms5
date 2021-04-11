// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds 
{
    class CovidPatient : public Patient 
    {
    public:
        CovidPatient();

        char type() const;

        std::istream& read(std::istream& is);
        std::istream& csvRead(std::istream& is);
        
        std::ostream& write(std::ostream& os) const;
    };
}
#endif //!SDDS_COVIDPATIENT_H_
