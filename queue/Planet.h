#ifndef PLANET_H
#define PLANET_H

class Planet {
	private:
		int id;
		static int static_id;
		int distance;
		char type;
	public:
		Planet(int);
        int orbit();
		int getID();
		int getDistance();
		char getType();
};

#endif
