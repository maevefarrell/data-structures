#include "Planet.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

Planet::Planet(int distance){
	srand(time(NULL));
	const char arrayChar[3] = {'h', 'r', 'g'};
	char randChar = arrayChar[(rand() % 3)];
	this->id = static_id++;
	this->distance = rand() % (3000 + 1 - 1) + 1;
	this->type = randChar;
}

int Planet::getID() {
	return this->id;
}

int Planet::getDistance() {
	return this->distance;
}

char Planet::getType() {
	return this->type;
}

int Planet::static_id = 0;
