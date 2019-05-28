#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <string>

class Node {
	public:
		std::string key;
		double value;
		Node() {
			key = "";
			value = -1.0;
		}
		~Node() {
			key = "";
			value = 0;
		}
};

#endif NODE_H
