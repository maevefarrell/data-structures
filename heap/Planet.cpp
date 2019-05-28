#include "Planet.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Planet::Planet(string id, double probability){
	this->id = id;
	this->probability = probability;
}
double Planet::refine(double r){
	probability += r;
	if(probability > 100) probability = 100;
	if (probability < 0) probability = 0;
	return probability;
}
bool Planet::operator<(const Planet &a){
	if(this->probability < a.probability) {
            return true;
        }
        return false;
}
bool Planet::operator>(const Planet &a){
	if(this->probability > a.probability) {
            return true;
        }
        return false;
}	
bool Planet::operator>=(const Planet &a){
	if(a.probability < this->probability) {
            return true;
        }
	else if(a.probability == this->probability){
	    return true;
	}
        return false;
}
bool Planet::operator<=(const Planet &a){
	if(a.probability > this->probability) {
            return true;
        }
	else if(a.probability == this->probability){
	    return true;
	}
        return false;
}
bool Planet::operator==(const Planet &a){
	if(this->probability == a.probability) {
            return true;
        }
        return false;
}	
bool Planet::operator!=(const Planet &a){
	if(this->probability != a.probability){
		return true;
	}
	return false;
}

