#include "Star.h"
#include "Planet.h"
#include "Probe.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

Probe::Probe() {
	this->hab_planets = queue<Planet>();
}

vector<Planet> Probe::getHabitable(Star s) {
	vector<Planet>::iterator plan;
	vector<Planet> ret_val = vector<Planet>();
			
	for(plan = s.getPlanets().begin(); plan < s.getPlanets().end(); plan++) {
		if((*plan).getType() == 'h' && (*plan).getDistance() >= 60 && (*plan).getDistance() <= 140) {
			ret_val.push_back(*plan);
			hab_planets.push(*plan);
		}
	}

	return ret_val;
}

void Probe::addToQueue(Planet p) {
	hab_planets.push(p);
}

Planet Probe::getNext() {
	Planet next = hab_planets.front();
	hab_planets.pop();
	return next;
}

queue<Planet>& Probe::getQueue() {
	return hab_planets;
}

void Probe::shuffle() {
	vector<Planet> v = vector<Planet>();
	while(!hab_planets.empty()) {
		v.push_back(hab_planets.front());
		hab_planets.pop();
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	random_shuffle(v.begin(), v.end());

	for(const auto& e: v) {
		hab_planets.push(e);
	}

	
}
