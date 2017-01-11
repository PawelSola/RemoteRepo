/*
 * StdArrayBoard.h
 *
 *  Created on: 11.01.2017
 *      Author: meep_solp
 */

#ifndef STDARRAYBOARD_H_
#define STDARRAYBOARD_H_

#include <array>

#include "Board.h"

template <class T>
class StdArrayBoard : public Board<T>
{
public:
	StdArrayBoard();
	virtual ~StdArrayBoard();

	virtual T get(int x, int y);
	virtual void set(int x, int y, T val);

	virtual void print();
private:
	std::array<std::array<T, Board<T>::size>, Board<T>::size> tab;
};

#endif /* STDARRAYBOARD_H_ */
