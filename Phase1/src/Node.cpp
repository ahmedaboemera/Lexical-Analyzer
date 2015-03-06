/*
 * Node.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: karim
 */

#include "Node.h"

Node::Node(string label) {
	this->label = label;
}

string Node::getLabel() {
	return this->label;
}

Node* Node::getNext(string input) {
	map<string, Node*>::iterator it = this->next.find(input);
	if (it == this->next.end())
		return nullptr;
	else
		return it->second;
}

void Node::addNext(string input, Node* next) {
	this->next.insert(pair<string, Node*>(input, next));
}

Node::~Node() {

}
