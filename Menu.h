// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>

namespace sdds {
    class Menu
    {
      char* m_text; // holds the menu content dynamically
      int m_noOfSel;  // holds the number of options displayed in menu content
      void display()const;
        
      void setText(const char*);
   public:
      Menu(const char* MenuContent, int NoOfSelections);
      virtual ~Menu();
      int& operator>>(int& Selection);
      Menu(const Menu&);// add safe copying logic
    };
}
#endif // !SDDS_MENU_H_ 
