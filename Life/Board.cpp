/*
 * Board.cpp
 *
 *  Created on: 11.01.2017
 *      Author: meep_solp
 */

#include <iostream>

#include "Board.h"

Board::Board()
{
	tab = new int*[size];
	for (auto i = 0; i < size; ++i)
	{
		tab[i] = new int[size];
	}
}

Board::~Board()
{
	for (auto i = 0; i < size; ++i)
	{
		delete tab[i];
	}
	delete tab;
}

int Board::get(int x, int y)
{
	int retVal = 0;
	if ( (x >= 0) && (x < size) &&
		 (y >= 0) && (y < size))
	{
		retVal = tab[x][y];
	}
	return retVal;
}

void Board::set(int x, int y, int val)
{
	if ( (x >= 0) && (x < size) &&
		 (y >= 0) && (y < size))
	{
		tab[x][y] = val;
	}
}

void Board::print()
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

int Board::getSize()
{
	return size;
}
