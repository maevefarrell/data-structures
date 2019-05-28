#ifndef PLANET_H
#define PLANET_H
#include <stdlib.h>
#include <string>
#include <list>
#include <vector>

class Planet {
	public:
		Planet(std::string planetName, long xCoor, long yCoor, long zCoor);
		~Planet();
		std::string getName();
		long getXCoor();
		long getYCoor();
		long getZCoor();
		std::string getColor();
		double getDist();
		Planet * getOptPrev();
		void setColor(std::string);
		void setDist(double);
		void setOptPrev(Planet*);
		std::list<Planet*> getAdjacent();
		double distanceBetween(Planet * p);
		std::list<Planet*> adjacent_planets; //this planet's adjacent lists
		double path_dist;
	private:
		std::string planet_name = "";
		long x_coor = 0;
		long y_coor = 0;
		long z_coor = 0;
		std::string color = "white";
		double dist = 0;
		Planet * opt_prev = nullptr;
};
#endif
