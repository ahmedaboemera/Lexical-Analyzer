/*
 * Node.h
 *
 *  Created on: Mar 6, 2015
 *      Author: karim
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <string>
#include <map>
#include <cstddef>

using namespace std;

class Node {
public:
	Node(string label);
	string getLabel();
	Node* getNext(string input);
	void addNext(string input, Node* next);
	~Node();
private:
	string label;
	map<string, Node*> next;
};

#endif /* SRC_NODE_H_ */
