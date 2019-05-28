#ifndef PROBE_H
#define PROBE_H
#include "Planet.h"
#include "Star.h"
#include <stdlib.h>
#include <queue>

using namespace std;

class Probe {
	private:
		queue<Planet> hab_planets;
	public:
		Probe();
		vector<Planet> getHabitable(Star s);
		void addToQueue(Planet p);
		Planet getNext();
		queue<Planet>& getQueue();
		void shuffle();
};


#endif
