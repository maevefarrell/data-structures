#ifndef STAR_H
#define STAR_H
#include "Planet.h"
#include <stdlib.h>
#include <vector>

class Star{
	private:
		int current_planets;
		std::vector<Planet> planets;
	public:
        Star();
		unsigned long addPlanet();
		bool removePlanet(unsigned long);
		Planet * getPlanet(unsigned long);
		std::vector<Planet>& getPlanets();
};

#endif
