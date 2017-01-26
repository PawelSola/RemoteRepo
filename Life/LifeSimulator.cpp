/*
 * LifeSimulator.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */

#include <iostream>
#include <cstdlib>
#include <memory>

#include "LifeSimulator.h"
#include "ArrayBoard.h"
#include "StdArrayBoard.h"

LifeSimulator::LifeSimulator()
{
	simulationStep = 0;
	isRunningFlag = false;
	board = std::shared_ptr<ArrayBoard<int> >(new ArrayBoard<int>);
	targetBoard = std::shared_ptr<StdArrayBoard<int> >(new StdArrayBoard<int>);
}

long LifeSimulator::getSimulationStep() const
{
	return simulationStep;
}

void LifeSimulator::run()
{
	simulationStep = 0;
	isRunningFlag = true;
	initialize();
}

void LifeSimulator::nextStep()
{
	if (maxSteps <= ++simulationStep)
		isRunningFlag = false;
	std::cout << std::string( 20, '\n' );
	std::cout << std::endl << "Simulation step: " << simulationStep << std::endl;
	std::cout << "Main board:" << std::endl;
	board->print();
	generateNextPopulation();
	std::cout << "Target board:" << std::endl;
	targetBoard->print();
}

void LifeSimulator::initialize()
{
	auto size = board->getSize();
	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j)
		{
			board->set(i, j, 0);
			targetBoard->set(i, j, 0);
		}
	}

	board->set(6, 5, 1);
	board->set(6, 6, 1);
	board->set(6, 7, 1);

	board->set(3, 1, 1);
	board->set(4, 2, 1);
	board->set(2, 3, 1);
	board->set(3, 3, 1);
	board->set(4, 3, 1);

}

bool LifeSimulator::isRunning()
{
	return isRunningFlag;
}

void LifeSimulator::generateNextPopulation()
{
	auto size = board->getSize();
	for (auto i = 1; i < size - 1; ++i)
	{
		for (auto j = 1; j < size - 1; ++j)
		{
			auto count = 0;
			count = board->get(i - 1, j) +
					board->get(i, j - 1) +
					board->get(i + 1, j) +
					board->get(i, j + 1) +
					board->get(i - 1, j - 1) +
					board->get(i + 1, j - 1) +
					board->get(i + 1, j + 1) +
					board->get(i - 1, j + 1);
			if (count < 2 || count > 3)
				targetBoard->set(i, j, 0);
			if (count == 2)
				targetBoard->set(i, j, board->get(i, j));
			if (count == 3)
				targetBoard->set(i, j, 1);
		}
	}

	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j)
		{
			board->set(i, j, targetBoard->get(i, j));
		}
	}

}
