// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: April 10th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstring>

#include "utils.h"
#include "IOAble.h"

using namespace std;
namespace sdds 
{
	ostream& operator<<(ostream& L, const IOAble& Object) 
	{
		return Object.write(L);
	}

	istream& operator>>(istream& L, IOAble& Object) 
	{
		return Object.read(L);
	}
}
