#include "Scanner.h"
#include "Heap.h"
#include "Planet.h"
#include "Parser.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

Scanner::Scanner(vector<Planet> planets){
	data = Heap<Planet>(planets);
}

vector<Planet> Scanner::scan(unsigned int num_planets){
	vector<Planet> scanned_planets;
	if(num_planets > data.size()){
		num_planets = data.size();
	}
	for(int i = 0; i < num_planets; i++){
		Planet p = data.getPriority();
		std::vector<int> rand_arr{-1,1};
		int index = rand() % rand_arr.size();
		if(!(p.getProbability() == 100 || p.getProbability() == 0)) {
			p.refine(rand_arr[index]);
			scanned_planets.push_back(p);
		}
	}

	return scanned_planets;
}

void Scanner::addPlanet(Planet p) {
	data.addElement(p);
}

Heap<Planet> Scanner::getHeap() {
	return data;
}
