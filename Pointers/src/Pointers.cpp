//============================================================================
// Name        : Pointers.cpp
// Author      : Pawel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <map>
using namespace std;


template <class T>
void f(T)
{

}

template <class T>
void g(const T&)
{

}

template <class T>
void h(T&)
{

}


int main()
{

	string* pWord = 0;
	unique_ptr<string> pWordUnique = 0;

	pWord = new string("Helo");

	cout << *pWord << endl;


	auto* x = new int;

	cout << std::is_same<int*, decltype(x)>::value << endl;
//	cout << "Type: " <<  << endl;

	std::map<int,int> Mymap;
	Mymap[0] = 0;

	for ( const std::pair<const int, int>& entry : Mymap)
	{

	}

	//C++ 11
	for ( const auto& entry : Mymap)
	{

	}

	//C++ 14
//	for ( decltype(auto) entry : Mymap)
//	{
//
//	}

	int i = 0;
	const int ci = 2;
	int& i_ref = i;
	const int& ci_ref = ci;

	int a = 0;
	int& b = a;
	int&& c = 5;

	int&& d = std::move(c);
	int&& e = static_cast<int&&>(d);

	auto x0 = i;
	auto x1 = ci;

	cout << std::is_const<decltype(ci)>::value << endl;

	f(i);
	f(ci);

	g(i);
	g(ci);

	h(i);
	h(ci);


	delete pWord;

	return 0;
}
