#ifndef HASH_H
#define HASH_H
#include <stdlib.h>
#include <string>
#include "Node.h"

class Hash {
	public:
		int s;
		Node *arr;
		Hash(unsigned int size) {
			this->s = size;
			this->arr = new Node[size];
		}
		~Hash() {
			delete[] arr;
			s = 0;
		}
		unsigned int hasher(std::string);
		bool insert(std::string, double);
		bool empty();
		int size();
		Node * getTable();
		double find(std::string);
		bool remove(std::string);
};

#endif HASH_H
