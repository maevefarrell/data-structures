#include "Hash.h"
#include <stdlib.h>
#include <string>

unsigned int Hash::hasher(std::string key) {
	int total = 0;
	for(char c : key) {
		total += int(c);
	}

	return total % size();
}

bool Hash::insert(std::string key, double val) {
	if(this->arr[hasher(key)].value == -1) {
		this->arr[hasher(key)].key = key;
		this->arr[hasher(key)].value = val;
		return true;
	}

	else {
		for(int i = hasher(key); i < this->size(); i++) {
			if(arr[i].value == -1) {
				arr[i].key = key;
				arr[i].value = val;
				return true;
			}
		}

		for(int i = 0; i < hasher(key); i++) {
			if(arr[i].value == -1) {
				arr[i].key = key;
				arr[i].value = val;
				return true;
			}
		}
	
	}

}

bool Hash::empty() {
	for(int i = 0; i < this->size(); i++) {
		if(arr[i].value != -1) return false;
	}
	return true;
}

int Hash::size() {
	return this->s;
}

Node * Hash::getTable() {
	return this->arr;
}

double Hash::find(std::string key) {
	for(int i = 0; i < size(); i++) {
		if(key == arr[i].key) return arr[i].value;
	}

	return -1.0;
}

bool Hash::remove(std::string key) {
	for(int i = 0; i < size(); i++) {
		if(key == arr[i].key) {
			arr[i].key = "";
			arr[i].value = -1.0;
			return true;
		}
	}

	return false;
}




