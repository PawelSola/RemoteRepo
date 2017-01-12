/*
 * main.cpp
 *
 *  Created on: 10.01.2017
 *      Author: meep_solp
 */
#include <iostream>
#include <conio.h>

#include "LifeSimulator.h"

using namespace std;

int main()
{
	std::cout << "Starting Life Simulator..." << std::endl;
	LifeSimulator* sim = new LifeSimulator;
	sim->run();
	unsigned char key;
	do
    {
    	key = getch();
    	sim->nextStep();
    }
    while( key != 27 );
    delete sim;
}

