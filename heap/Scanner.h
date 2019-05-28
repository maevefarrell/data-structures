#ifndef scanner_mp
#define scanner_mp
#include "Heap.h"
#include "Planet.h"
#include <vector>

class Scanner{
	private:
		Heap<Planet> data;
	public:
		Scanner(vector<Planet>);
		std::vector<Planet> scan(unsigned int num_planets);
		void addPlanet(Planet p);
		Heap<Planet> getHeap();
};
#endif
