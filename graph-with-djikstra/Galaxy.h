#ifndef galaxy_mp
#define galaxy_mp
#include "Planet.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list>
#include <vector>

class Galaxy{
	std::vector<Planet *> planets; //vector of all planets
	unsigned int numPlanets=0;
	public:
		Galaxy(std::string filename);
		~Galaxy();
		unsigned int size();
		std::vector<Planet *> findAdjacencies(Planet * p);
		Planet * findByName(std::string planetName);
		double getDistance(Planet plan1, Planet plan2); //gets distance between two diff planets
    	std::vector<Planet *> shortestPath(Planet * start, Planet * dest);
		void printPlanets();
		Planet * minVertex(std::vector<Planet *> planets);
		double pathDistance(Planet * start, Planet * dest);
};
#endif
