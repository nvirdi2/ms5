// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>

#include <cstring>
#include <cstdlib>
#include <ctime>

#include "utils.h"
#include "Time.h"

using namespace std;
namespace sdds
{
    bool debug = false;

    int getTime()
    {
        int minutes {-1};

        if (debug)
        {
            Time x(0);

            cout << "Enter current time: ";
                do
                {
                    cin.clear();
                    cin >> x;

                        if (!cin)
                        {
                            cout << "Invlid time, try agian (HH:MM): ";
                            cin.clear();
                        }

                            else
                            {
                                minutes = int(x);
                            }
                    cin.ignore(1000, '\n');

                } while (minutes < 0);
        }
        
        else
        {
            time_t x = time(NULL);

            tm i = *localtime(&x);

            minutes = i.tm_hour * 60 + i.tm_min;
        } return minutes;
    }


    int getInt(const char *prompt)
    {
        int flag = 0;
        bool UserIn = false;
        int number;

            if (prompt != nullptr)
            {   
                cout << prompt;
            }

        string x;
        getline(cin, x);
        x = x + '\n';

            bool InvalidIn = false;

        while (flag == 0 || flag == 1) 
        {
            number = 0;
            int l = 0;
            InvalidIn = false;
            UserIn = false;
            while (x[l]) 
            {
                if (x[l] == '-')
                {
                    InvalidIn = true;
                }
                else if (x[l] < '0' || x[l] > '9') 
                {
                    if (UserIn == false) 
                    {
                        cout << "Oye Hoye: " << x[l] << endl;
                            flag = 0;
                    }

                    else if (x[l] == '\n')
                    {
                        flag = 2;
                    }
                    else
                    {
                        flag = 1;
                    }
                        break;
                }

                else 
                {
                    UserIn = true;
                    number = number * 10 + x[l] - '0';
                }

                l++;
            }

            if (InvalidIn)
            {
                number = 1 * number;
            }
            if (flag != 2) 
            {
                if (flag == 0)
                {
                    cout << "Bad integer value, try again: ";
                }
                else
                {
                    cout << "Enter only an integer, try again: ";
                }
                    getline(cin, x);
                x = x + '\n';
            }
        } return number;
    }

    char *getcstr(const char *prompt, istream &istr, char delimiter)
    {
        char *cstr;

        string tmp;

        if (prompt != nullptr)
        {
            cout << prompt;
        }

        getline(istr, tmp);

        cstr = new char[tmp.length() + 1];

        strcpy(cstr, tmp.c_str());
        
        return cstr;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) 
    {
        int flag = 0;
        bool UserIn = false;
        int number;

            if (prompt != nullptr)
            {   
                cout << prompt;
            }

        string i;
        getline(cin, i);
        i = i + '\n';

        bool InvalidIN = false;

        while (flag == 0 || flag == 1) 
        {
            InvalidIN = false;
            number = 0;
            int x = 0;
            UserIn = false;

            while (i[x]) 
            {
                if (i[x] == '-')
                {
                    InvalidIN = true;
                }

                else if (i[x] < '0' || i[x] > '9') 
                {

                    if (UserIn == false)
                    {
                        flag = 0;
                    }

                    else if (i[x] == '\n')
                    {   
                        flag = 2;
                    }

                    else
                    {
                        flag = 1;
                    }

                    break;
                }

                else 
                {
                    UserIn = true;
                    number = number * 10 + i[x] - '0';
                }
                x++;
            }

            if (InvalidIN)
            {
                number = -1 * number;
            }

            if (flag != 2) 
            {
                if (flag == 0)
                {
                    cout << "Bad integer value, try again: ";
                }

                else
                {
                    cout << "Enter only an integer, try again: ";
                }
                
                getline(cin, i);
                    i = i + '\n';
            }

            else if (number < min || number > max) 
            {
                flag = 1;

                if (errorMessage != nullptr)
                {
                    cout << errorMessage;
                }

                if (showRangeAtError) 
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
                
                getline(cin, i);
                    i = i + '\n';
            }
        } return number;
    }
}
