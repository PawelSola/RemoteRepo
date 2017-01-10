/*
 * main.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */
#include <iostream>

#include "LifeSimulator.h"

using namespace std;

int main()
{
	cout << "Initializing Life Simulator..." << endl;
	LifeSimulator sim;
	sim.run();

	cout << "Simulation step: " << sim.getSimulationStep() << endl;
}

