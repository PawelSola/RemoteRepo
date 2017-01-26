/*
 * main.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */
#include <iostream>
#include <chrono>
#include <thread>

#include "LifeSimulator.h"

int main()
{
	std::cout << "Starting Life Simulator..." << std::endl;
	LifeSimulator* sim = new LifeSimulator;
	sim->run();
	do
    {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
    	sim->nextStep();
    }
    while( sim->isRunning());
    delete sim;
}

