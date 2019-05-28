#include "Planet.h"
#include <stdlib.h>
#include <string>
#include <list>
#include <math.h>

using namespace std;

Planet::Planet(string planetName, long xCoor, long yCoor, long zCoor) {
	this->planet_name = planetName;
	this->x_coor = xCoor;
	this->y_coor = yCoor;
	this->z_coor = zCoor;
	this->color = "white";
	this->dist = (unsigned int)-1;
	this->opt_prev = nullptr;
	this->path_dist = 0;
}

Planet::~Planet() {
	opt_prev = nullptr;
	planet_name = "";
}

string Planet::getName(){return this->planet_name;}

long Planet::getXCoor() {return this->x_coor;}

long Planet::getYCoor() {return this->y_coor;}

long Planet::getZCoor() {return this->z_coor;}

string Planet::getColor() {return this->color;}

double Planet::getDist() {return this->dist;}

Planet * Planet::getOptPrev() {return this->opt_prev;}

void Planet::setColor(string s) {this->color = s;}
void Planet::setDist(double d){this->dist = d;}
void Planet::setOptPrev(Planet* p) {this->opt_prev = p;}

list<Planet*> Planet::getAdjacent() {return this->adjacent_planets;}

double Planet::distanceBetween(Planet * p) {
	double xcoor = pow((this->getXCoor() - p->getXCoor()), 2);
	double ycoor = pow((this->getYCoor() - p->getYCoor()), 2);
	double zcoor = pow((this->getZCoor() - p->getZCoor()), 2);

	return sqrt(xcoor + ycoor + zcoor);
}
