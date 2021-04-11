// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds 
{
    Menu::Menu(const char* MenuContent, int NoOfSelections) 
    {
        setText(MenuContent);
            m_noOfSel = NoOfSelections;
    }

    Menu::~Menu() 
    {
        delete[] m_text;
    }

    Menu::Menu(const Menu& other) 
    {
        setText(other.m_text);
            m_noOfSel = other.m_noOfSel;
    }



    void Menu::setText(const char* text) 
    {
        int txt = strlen(text);
        m_text = new char[txt + 1];

        strcpy(m_text, text);

        m_text[txt] = '\0';
    }

    void Menu::display()const 
    {
        cout << m_text << endl;
            cout << "0- Exit" << endl;
    }



    int& Menu::operator>>(int& Selection) 
    {
        display();

        int correct = getInt(0, m_noOfSel, "> ", "Invalid option ");
        Selection = correct;

            return Selection;
    }
}
