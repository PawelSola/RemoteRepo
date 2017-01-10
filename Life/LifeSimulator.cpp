/*
 * LifeSimulator.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */

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
}
