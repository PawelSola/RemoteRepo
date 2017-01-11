/*
 * Board.h
 *
 *  Created on: 11.01.2017
 *      Author: meep_solp
 */

#ifndef BOARD_H_
#define BOARD_H_

template <class T>
class Board
{
public:
	Board() = default;
	virtual ~Board() = default;

	virtual T get(int x, int y) = 0;
	virtual void set(int x, int y, T val) = 0;

	virtual void print() = 0;

	virtual int getSize() = 0;

};

template class Board<int>;


#endif /* BOARD_H_ */