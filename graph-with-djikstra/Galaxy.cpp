#include "Galaxy.h"
#include "Planet.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <limits>
#include <cfloat>

#define INFINITY numeric_limits<unsigned int>::max()

using namespace std;

Galaxy::Galaxy(string filename){
	ifstream file(filename);
	string line;
	while(getline(file, line)){
		int index = line.find(" ");
		string planet_name = line.substr(0, index);

		string newLine = line.substr(index+1, line.length());
		index = newLine.find(" ");
		long xCoor = stol(newLine.substr(0, index), nullptr);

		string newLine2 = newLine.substr(index+1, newLine.length());
		index = newLine2.find(" ");
		long yCoor = stol(newLine2.substr(0, index), nullptr);

		string newLine3 = newLine2.substr(index+1, newLine2.length());
		index = newLine3.find(" ");
		long zCoor = stol(newLine3.substr(0, index), nullptr);

		planets.push_back(new Planet(planet_name, xCoor, yCoor, zCoor));

		numPlanets++;
	}

	for(int i = 0; i < numPlanets; i++) {
		vector<Planet *> adjs = findAdjacencies(planets[i]);
		for(Planet * p : adjs) {
			planets[i]->adjacent_planets.push_back(p);
		}
	}
}
vector<Planet *> Galaxy::findAdjacencies(Planet* p){
	// Vector of current adj planets
	vector<pair<Planet *, double>> current_adjacents;
	vector<double> current_adjacent_distances;

	for (auto p_it = this->planets.begin(); p_it != this->planets.end(); p_it++) {
		if (p == *p_it) continue;

		if (current_adjacents.size() < 4) {
			current_adjacents.push_back(pair<Planet *, double> (*p_it, p->distanceBetween(*p_it)));
			current_adjacent_distances.push_back(p->distanceBetween(*p_it));
			sort(current_adjacent_distances.begin(), current_adjacent_distances.end());
		}

		else {
			double p_it_d = p->distanceBetween(*p_it);
			double greatest_distance = current_adjacent_distances[3];

			if (p_it_d < greatest_distance) {
				current_adjacent_distances.erase(current_adjacent_distances.begin() + 3);
				current_adjacent_distances.push_back(p_it_d);

				for (auto ca_it = current_adjacents.begin(); ca_it != current_adjacents.end(); ca_it++) {
					if ((*ca_it).second == greatest_distance) {
						current_adjacents.erase(ca_it);
						break;
					}
				}

				current_adjacents.push_back(pair<Planet *, double> (*p_it, p_it_d));

				sort(current_adjacent_distances.begin(), current_adjacent_distances.end());
			}
		}
	}

	vector<Planet *> ret_val;

	for (auto ca_it = current_adjacents.begin(); ca_it != current_adjacents.end(); ca_it++) {
		ret_val.push_back((*ca_it).first);
	}

	cout << p->getName() << " is adjacent to" << endl;

	for (auto it = ret_val.begin(); it != ret_val.end(); it++) {
		cout << "\t" << (*it)->getName() << endl;
	}
	return ret_val;
}

Galaxy::~Galaxy() {
	for(int i = 0; i < planets.size(); i++) {
		delete planets.at(i);
	}
}

/*double Galaxy::getDistance(Planet plan1, Planet plan2) {
  return sqrt((pow(plan1.getXCoor(), 2) + pow(plan1.getYCoor(), 2), pow(plan1.getZCoor(), 2)) + (pow(plan2.getXCoor(), 2) + pow(plan2.getYCoor(), 2), pow(plan2.getZCoor(), 2)));
  }*/

double Galaxy::getDistance(Planet plan1, Planet plan2) {
	double xcoor = pow((plan1.getXCoor() - plan2.getXCoor()), 2);
	double ycoor = pow((plan1.getYCoor() - plan2.getYCoor()), 2);
	double zcoor = pow((plan1.getZCoor() - plan2.getZCoor()), 2);

	return sqrt(xcoor + ycoor + zcoor);
}

unsigned int Galaxy::size(){
	return numPlanets;
}
Planet * Galaxy::findByName(string planetName){
	for(int i = 0; i < planets.size(); i++){
		if(planets[i]->getName().compare(planetName) == 0){
			return planets[i];
		}
	}
	return nullptr;
}
void Galaxy::printPlanets() {
	for(Planet * p : planets) {
		cout << "Name: " << p->getName() << endl;
		cout << "X-Coor: " << p->getXCoor() << endl;
		cout << "Y-Coor: " << p->getYCoor() << endl;
		cout << "Z-Coor: " << p->getZCoor() << endl;
	}
}
vector<Planet *> Galaxy::shortestPath(Planet * start, Planet * dest) {
	vector<Planet *> ret_val;
	for(int i = 0; i < this->numPlanets; i++) { //initializes all planets to white, INF, nullptr
		planets.at(i)->setColor("white");
		planets.at(i)->setDist(INFINITY);
		planets.at(i)->setOptPrev(nullptr);
	}
	start->setDist(0); //zero dist from itself

	for(int i = 0; i < numPlanets; i++) {
		Planet * min = minVertex(planets);
		min->setColor("red"); //set first node to being fully explored

		if(min->getDist() == INFINITY) { //if unreachable
			break;
		}

		list<Planet *> temp = min->getAdjacent();
		vector<Planet *> adjs{begin(temp), end(temp)};

		for(int k = 0; k < adjs.size(); k++){
			Planet * w = adjs.at(k);
			if(w->getColor().compare("white") == 0){
				if(w->getDist() > (min->getDist() + getDistance(*min, *w))){
					w->setDist(min->getDist() + getDistance(*min, *w));
					w->setOptPrev(min);

				}
			}
		}
	}

	//vector<Planet *> retVal(numPlanets);
	vector<Planet *> retVal;
	Planet * temp = dest;
	retVal.insert(retVal.begin(), temp);

	while(temp != start && temp !=NULL) {

		retVal.insert(retVal.begin(), temp->getOptPrev());
		temp = temp->getOptPrev(); //setting optimal previous to null on the first time
	}

	if(dest->getDist() == INFINITY) {
		vector<Planet *> empty;
		return empty;
	}
	return retVal;
}
Planet * Galaxy::minVertex(vector<Planet *> planets){
	Planet* min = planets[0];
	for (int i = 0; i < planets.size(); i++) {
		if (planets[i]->getColor().compare("white") == 0) {
			min = planets.at(i);
			break;
		}
	}

	for(int i = 0; i < numPlanets; i++) {
		if(planets.at(i)->getDist() < min->getDist() && (planets.at(i)->getColor().compare("white") == 0)) {
			min = planets.at(i);
		}
	}
	return min;
}

double Galaxy::pathDistance(Planet * start, Planet * dest) {
	vector<Planet *> path = shortestPath(start, dest);
	if(path.size() == 0){
		return LDBL_MAX;
	}
	if(path.size() == 1){
		return 0;
	}
	double retVal = 0;
	for(int i = 0; i< path.size()-1; i++){
		retVal += getDistance((*path.at(i)), (*path.at(i+1)));
	}
	return retVal;
}
