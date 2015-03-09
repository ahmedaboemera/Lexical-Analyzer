/*
 * NFA.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: karim
 */

#include "NFA.h"

using namespace std;

int NFA::label_counter = 0; // static variable initialized

//static NFA* _concatenate(NFA* g1, NFA* g2) {
//
//}
//
//static NFA* _union(NFA* g1, NFA* g2) {
//
//}
//static NFA* _close(NFA* g1, NFA* g2) {
//
//}

void NFA::add_node() {
	map<string, set<int>*> connections;
	this->adj_list->insert(pair<int, map<string,
			set<int>*>*>(this->label_counter, &connections));
	this->label_counter++;
}

void NFA::add_starting() {
	map<string, set<int>*> connections;
	this->adj_list->insert(pair<int, map<string,
			set<int>*>*>(this->label_counter, &connections));
	this->starting_points->insert(this->label_counter);
	this->label_counter++;
}

void NFA::add_acceptor(string accepted_expression) {
	map<string, set<int>*> connections;
	this->adj_list->insert(pair<int, map<string,
		set<int>*>*>(this->label_counter, &connections));
	Acceptor* a = new Acceptor(this-label_counter, accepted_expression);
	this->acceptors->insert(a);
	this->label_counter++;
}
void connect(int node1, int node2, string input) {

}
void print_debug() {

}

NFA::NFA() {
	this->starting_points = new set<int>;
	this->adj_list = new map<int, map<string, set<int>*>*>;
	this->acceptors = new set<Acceptor>;
}

NFA::~NFA() {
	for(set<int>::iterator it = this->starting_points->begin();
			it != this->starting_points->end(); it++) {
		delete it;
	}
	delete starting_points;

	for (map<int, map<string, set<int>*>*>::iterator it1 = this->adj_list->begin();
			it1 != this->adj_list->end(); it1++) {
		for (map<string, set<int>*>::iterator it2 = it1->second->begin();
				it2 != it1->second->end(); it2++) {
			for (set<int>::iterator it3 = it2->second->begin();
					it3 != it2->second->end(); it3++) {
				delete it3;
			}
			delete it2;
		}
		delete it1;
	}
	delete adj_list;

	for(set<Acceptor>::iterator it = this->acceptors->begin();
			it != this->acceptors->end(); it++) {
		delete it;
	}
	delete acceptors;
}

