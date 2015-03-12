/*
 * NFA.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: karim
 */

#include "NFA.h"

using namespace std;

unsigned int NFA::label_counter = 0; // static variable initialized

//NFA* NFA::_concatenate(NFA* g1, NFA* g2) {
//	return nullptr;
//}
//
//NFA* NFA::_union(NFA* g1, NFA* g2) {
//	return nullptr;
//}
//NFA* NFA::_close(NFA* g1, NFA* g2) {
//	return nullptr;
//}

void NFA::add_node() {
	this->adj_list.insert(
			pair<int, map<string, vector<int> > >(label_counter,
					map<string, vector<int> >()));
	label_counter++;
}

void NFA::add_starting() {
	this->adj_list.insert(
			pair<int, map<string, vector<int> > >(label_counter,
					map<string, vector<int> >()));
	this->starting_points.push_back(label_counter);
	label_counter++;
}

void NFA::add_acceptor(string accepted_expression) {
	this->adj_list.insert(
			pair<int, map<string, vector<int> > >(label_counter,
					map<string, vector<int> >()));
	this->acceptors.push_back(Acceptor(label_counter, accepted_expression));
	label_counter++;
}

void connect(int node1, int node2, string input) {

}

void NFA::print_debug() {

	cout << "Starting : ";
	for (vector<int>::iterator it = starting_points.begin();
			it != starting_points.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

	cout << "Accepting : ";
	for (vector<Acceptor>::iterator it = acceptors.begin();
			it != acceptors.end(); it++) {
		cout << it->get_id() << ", ";
	}
	cout << endl;

	for (map<int, map<string, vector<int>>> ::iterator it = adj_list.begin();
	it != adj_list.end(); it++) {
		cout << it->first << ":" << endl;
		for (map<string, vector<int>>::iterator it2 = it->second.begin();
		it2 != it->second.end(); it2++) {
			cout << "\t" << it2 -> first << ":";
			for (vector<int>::iterator it3 = it2->second.begin(); it3 != it2->second.end();
			it3++) {
				cout << *it3 << ", ";
			}
			cout << endl;
		}
	}

}

NFA::NFA() {
}

NFA::~NFA() {

}

