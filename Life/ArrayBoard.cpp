/*
 * ArrayBoard.cpp
 *
 *  Created on: 11.01.2017
 *      Author: meep_solp
 */

#include "ArrayBoard.h"

#include <iostream>


template <class T>
ArrayBoard<T>::ArrayBoard()
{
	tab = new T*[Board<T>::size];
	for (auto i = 0; i < Board<T>::size; ++i)
	{
		tab[i] = new T[Board<T>::size];
	}
}

template <class T>
ArrayBoard<T>::~ArrayBoard()
{
	for (auto i = 0; i < Board<T>::size; ++i)
	{
		delete tab[i];
	}
	delete tab;
}

template <class T>
const T& ArrayBoard<T>::get(int x, int y)
{
	return tab[x][y];
}

template <class T>
void ArrayBoard<T>::set(int x, int y, const T& val)
{
	if ( (x >= 0) && (x < Board<T>::size) &&
		 (y >= 0) && (y < Board<T>::size))
	{
		tab[x][y] = val;
	}
}

template <class T>
void ArrayBoard<T>::print()
{
	std::cout << "ArrayBoard used" << std::endl;
	std::cout << " ";
	for (auto j = 0; j < Board<T>::size; ++j)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	for (auto i = 0; i < Board<T>::size; ++i)
	{
		std::cout << "|";
		for (auto j = 0; j < Board<T>::size; ++j)
		{
			tab[i][j] ? std::cout <<  "*" : std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ";
	for (auto j = 0; j < Board<T>::size; ++j)
	{
		std::cout << "-";
	}
}

template class ArrayBoard<int>;
