/*
 * LifeSimulator.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */

#include <iostream>
#include <cstdlib>

#include "LifeSimulator.h"

LifeSimulator::LifeSimulator()
{
	simulationStep = 0;
}

long LifeSimulator::getSimulationStep() const
{
	return simulationStep;
}

void LifeSimulator::run()
{
	simulationStep = 0;
	initialize();
}

void LifeSimulator::nextStep()
{
	simulationStep++;
	std::cout << std::string( 20, '\n' );
	std::cout << std::endl << "Simulation step: " << simulationStep << std::endl;
	std::cout << std::endl << "Main board:" << std::endl;
	board.print();
	generateNextPopulation();
	std::cout << std::endl << "Target board:" << std::endl;
	targetBoard.print();
}

void LifeSimulator::initialize()
{
	auto size = Board::getSize();
	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j)
		{
			board.set(i, j, 0);
			targetBoard.set(i, j, 0);
		}
	}

	board.set(5, 5, 1);
	board.set(5, 6, 1);
	board.set(6, 6, 1);
	board.set(7, 5, 1);
	board.set(7, 6, 1);
}

void LifeSimulator::generateNextPopulation()
{
	auto size = Board::getSize();
	for (auto i = 1; i < size - 1; ++i)
	{
		for (auto j = 1; j < size - 1; ++j)
		{
			auto count = 0;
			count = board.get(i - 1, j) +
					board.get(i, j - 1) +
					board.get(i + 1, j) +
					board.get(i, j + 1);
			if(count < 2 || count > 3)
				targetBoard.set(i, j, 0);
			if(count == 2)
				targetBoard.set(i, j, board.get(i, j));
			if(count == 3)
				targetBoard.set(i, j, 1);
		}
	}

	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j)
		{
			board.set(i, j, targetBoard.get(i, j));
		}
	}

}
