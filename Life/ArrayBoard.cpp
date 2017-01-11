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
	size = 10;
	tab = new T*[size];
	for (auto i = 0; i < size; ++i)
	{
		tab[i] = new T[size];
	}
}

template <class T>
ArrayBoard<T>::~ArrayBoard()
{
	for (auto i = 0; i < size; ++i)
	{
		delete tab[i];
	}
	delete tab;
}

template <class T>
T ArrayBoard<T>::get(int x, int y)
{
	T retVal = 0;
	if ( (x >= 0) && (x < size) &&
		 (y >= 0) && (y < size))
	{
		retVal = tab[x][y];
	}
	return retVal;
}

template <class T>
void ArrayBoard<T>::set(int x, int y, T val)
{
	if ( (x >= 0) && (x < size) &&
		 (y >= 0) && (y < size))
	{
		tab[x][y] = val;
	}
}

template <class T>
void ArrayBoard<T>::print()
{
	std::cout << " ";
	for (auto j = 0; j < size; ++j)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	for (auto i = 0; i < size; ++i)
	{
		std::cout << "|";
		for (auto j = 0; j < size; ++j)
		{
			tab[i][j] ? std::cout <<  "*" : std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ";
	for (auto j = 0; j < size; ++j)
	{
		std::cout << "-";
	}
}

template <class T>
int ArrayBoard<T>::getSize()
{
	return size;
}

template class ArrayBoard<int>;
