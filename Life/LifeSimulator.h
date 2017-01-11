/*
 * LifeSimulator.h
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */

#ifndef LIFESIMULATOR_H_
#define LIFESIMULATOR_H_

#include "Board.h"

class LifeSimulator
{
public:
	LifeSimulator();

	long getSimulationStep() const;

	void run();
	void nextStep();
private:
	static const long maxSteps = 100;
	long simulationStep;
	Board board;
	Board targetBoard;

	void initialize();
	void generateNextPopulation();
};

#endif /* LIFESIMULATOR_H_ */
