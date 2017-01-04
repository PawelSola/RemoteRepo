//============================================================================
// Name        : Pointers.cpp
// Author      : Pawel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

int main()
{

	string* pWord = 0;
	unique_ptr<string> pWordUnique = 0;

	pWord = new string("Helo");

	cout << *pWord << endl;

	delete pWord;

	return 0;
}
