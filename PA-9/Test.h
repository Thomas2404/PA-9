#pragma once

#include "BoidManager.h"
#include <iostream>

class Test
{
public:
	// Runs all the test functions.
	void runTest();

	// Testing of the BoidManager.init function. Tests if the correct number of nodes are created.
	void testInit();

	// Testing of the random color feature in the Boid constructor. Tests to make sure that random colors are applied.
	void testBoidColorConstructor();

	// Testing to make sure that boids are assigned bias groups.
	void testRandomBiasGroups();

	// Tests the calculateDistance utility function to make sure it calculates the right values.
	void testDistanceFunction();

	// Tests the randomVelocity function to be sure that the boids will have different velocities.
	void testRandomVelocity();

};