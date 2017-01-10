/*
 * LifeSimulator.h
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */

#ifndef LIFESIMULATOR_H_
#define LIFESIMULATOR_H_

class LifeSimulator
{
public:
	LifeSimulator();

	long getSimulationStep() const;

	void run();
private:
	long simulationStep;
};

#endif /* LIFESIMULATOR_H_ */
