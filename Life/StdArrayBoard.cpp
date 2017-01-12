/*
 * StdArrayBoard.cpp
 *
 *  Created on: 11.01.2017
 *      Author: meep_solp
 */

#include "StdArrayBoard.h"

#include <iostream>


template <class T>
const T& StdArrayBoard<T>::get(int x, int y)
{
	return tab[x][y];
}

template <class T>
void StdArrayBoard<T>::set(int x, int y, const T& val)
{
	tab[x][y] = val;
}

template <class T>
void StdArrayBoard<T>::print()
{
	std::cout << "StdArrayBoard used" << std::endl;
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
			tab[i][j] ? std::cout << "*" : std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ";
	for (auto j = 0; j < Board<T>::size; ++j)
	{
		std::cout << "-";
	}
}

template class StdArrayBoard<int>;
