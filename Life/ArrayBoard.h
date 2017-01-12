/*
 * ArrayBoard.h
 *
 *  Created on: 11.01.2017
 *      Author: meep_solp
 */

#ifndef ARRAYBOARD_H_
#define ARRAYBOARD_H_

#include "Board.h"

template <class T>
class ArrayBoard : public Board<T>
{
public:
	ArrayBoard();
	virtual ~ArrayBoard();

	virtual const T& get(int x, int y);
	virtual void set(int x, int y, const T& val);
	virtual void print();
private:
	T** tab;
};

#endif /* ARRAYBOARD_H_ */
