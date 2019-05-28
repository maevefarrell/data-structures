#include "Parser.h"
#include "Planet.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Parser::Parser(string filename) {
	ifstream file(filename);
	string line;
	while(getline(file, line)) {
		int index = line.find(" ");
		string planet_name = line.substr(0, index);
        string planet_prob_str = line.substr(index + 1, line.length());
		double planet_prob = stod(planet_prob_str);
		this->planet_data.push_back(Planet(planet_name, planet_prob));
	}

}

vector<Planet>Parser::getPlanets() {
	return this->planet_data;
}
