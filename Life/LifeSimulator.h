/*
 * LifeSimulator.h
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */

#ifndef LIFESIMULATOR_H_
#define LIFESIMULATOR_H_

#include <memory>

#include "Board.h"

class LifeSimulator
{
public:
	LifeSimulator();
	~LifeSimulator() = default;

	long getSimulationStep() const;

	void run();
	void nextStep();
private:
	static const long maxSteps = 100;
	long simulationStep;
	std::shared_ptr<Board<int> > board;
	std::shared_ptr<Board<int> > targetBoard;

	void initialize();
	void generateNextPopulation();
};

#endif /* LIFESIMULATOR_H_ */
