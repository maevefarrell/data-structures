#include "Star.h"
#include "Planet.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

Star::Star() {
	this->planets = vector<Planet>();
}

unsigned long Star::addPlanet() {
	Planet p = Planet(current_planets);
	planets.push_back(p);
	return p.getID();
}

bool Star::removePlanet(unsigned long id) {
	for(vector<Planet>::iterator current = planets.begin(); current != planets.end(); current++) {
		if(current->getID() == id) {
			planets.erase(current);
			return true;
		}
	}

	return false;
}

Planet * Star::getPlanet(unsigned long  id) {
	for(vector<Planet>::iterator current = planets.begin(); current != planets.end(); current++) {
		if((*current).getID() == id) {
			return &(*current);
		}
	}

	return nullptr;
}

vector<Planet> & Star::getPlanets() {
	return this->planets;
}




