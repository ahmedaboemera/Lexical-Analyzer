/*
 * DFA.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: karim
 */

#include "DFA.h"

unsigned int DFA::label_counter = 0; // static variable initialized

DFA::DFA(NFA& nfa) {
	this->nfa = nfa;
	starting = 0;
	this->subset_construct(nfa);
}

int DFA::exists(set<int> u) {
	for (map<int, set<int>>::iterator entry = d_states.begin();
			entry != d_states.end(); entry++) {
		if (u == entry->second) {
			return entry->first;
		}
	}
	return -1;
}

set<int> DFA::move(set<int> nfa_states, string in) {
	set<int> next;

	for(set<int>::iterator it  = nfa_states.begin(); it != nfa_states.end(); it++){

	}
}

void DFA::subset_construct(NFA& nfa) {
	set<int> inits = nfa.epsilon_closure(nfa.get_starting());
	starting = add_node(inits);
	set<string> lang = nfa.get_lang();
	set<int> visited;
	set<int> keys;
	keys.insert(starting);
	int current_state = starting;

//	for(map<int, set<int>>::iterator it = it)

	set<int> c = d_states.at(current_state);

	for (set<int>::iterator it = c.begin(); it != c.end(); it++) {
		visited.insert(*it);
		for (set<string>::iterator sim = lang.begin(); sim != lang.end();
				sim++) {
			set<int> u = nfa.epsilon_closure(
					*(nfa.next_states(current_state, *sim)));
			int nextNode = exists(u);
			if (nextNode < 0) {
				nextNode = add_node(u);
			}
			connect()
		}
	}

	set<int> diff;
	do {

		diff.clear();
		set_difference(keys.begin(), keys.end(), visited.begin(), visited.end(),
				inserter(diff, diff.end()));
	} while (!diff.empty());

}

void DFA::connect(int node1, int node2, string input) {
	map<string, int>* connections = &this->adj_list.at(node1);
	connections->insert(pair<string, int>(input, node2));
}

int DFA::add_node(set<int> nfa_states) {
	d_states.insert(pair<int, set<int>>(label_counter, nfa_states));
	adj_list.insert(
			pair<int, map<string, int>>(label_counter, map<string, int>()));
	label_counter++;
	return label_counter - 1;
}

int DFA::add_starting() {

}

void DFA::print_debug() {

//	cout << "Starting : ";
//	for (vector<int>::iterator it = starting_points.begin();
//			it != starting_points.end(); it++) {
//		cout << *it << ", ";
//	}
//	cout << endl;
//
//	cout << "Accepting : ";
//	for (vector<Acceptor>::iterator it = acceptors.begin();
//			it != acceptors.end(); it++) {
//		cout << it->get_id() << ", ";
//	}
//	cout << endl;

	for (map<int, map<string, int>>::iterator it = adj_list.begin();
			it != adj_list.end(); it++) {
		cout << it->first << ":" << endl;
		for (map<string, int>::iterator it2 = it->second.begin();
				it2 != it->second.end(); it2++) {
			cout << "\t'" << it2->first << "':" << it2->second << endl;
		}
	}

}

DFA::~DFA() {
	// TODO Auto-generated destructor stub
}

