#ifndef PARSER_H
#define PARSER_H
#include "Planet.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class Parser {
	public:
		Parser(string filename);
		vector<Planet> getPlanets();

	private:
		vector<Planet> planet_data;
};

#endif
