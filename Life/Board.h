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
	Board();
	virtual ~Board();

	T get(int x, int y);
	void set(int x, int y, T val);

	void print();

	static int getSize();
private:
	static const int size = 10;
	T** tab;
};

#endif /* BOARD_H_ */
