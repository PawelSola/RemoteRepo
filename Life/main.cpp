/*
 * main.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */
#include <iostream>

#include "LifeSimulator.h"

int main()
{
	std::cout << "Starting Life Simulator..." << std::endl;
	LifeSimulator* sim = new LifeSimulator;
	sim->run();
    delete sim;
}

