#ifndef planet_mp
#define planet_mp
#include <iostream>

using namespace std;

class Planet{
	private:
		string id;
		double probability;
		char type;
		static unsigned long s_id;
	public:
		Planet(string, double);
		string getName(){return id;};
		double getProbability(){return probability;};
		double refine(double r);
		bool operator>(const Planet &a);
		bool operator<(const Planet &a);
		bool operator>=(const Planet &a);
		bool operator<=(const Planet &a);
		bool operator==(const Planet &a);
		bool operator!=(const Planet &a);

};

#endif
