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
	this->subset_construct();
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
	for (set<int>::iterator it = nfa_states.begin(); it != nfa_states.end();
			it++) {
		set<int>* res = nfa.next_states(*it, in);
		if (res != nullptr)
			next.insert(res->begin(), res->end());
	}
	return next;
}

int DFA::get_first_unvisited_state(set<int> visited) {
	for (map<int, set<int>>::iterator it = d_states.begin();
			it != d_states.end(); it++) {
		if (visited.find(it->first) == visited.end())
			return it->first;
	}
	return -1;
}

void DFA::subset_construct() {
	set<string> lang = nfa.get_lang();

	set<int> inits = nfa.epsilon_closure(nfa.get_starting());
	starting = add_node(inits);

	int current_state;
	set<int> visited;

	while (true) {
		current_state = get_first_unvisited_state(visited);

		if (current_state == -1) {
			break;
		}

		visited.insert(current_state);

		for (set<string>::iterator it = lang.begin(); it != lang.end(); it++) {
			if (it->compare(EPS) == 0) {
				continue;
			}

			set<int> u = nfa.epsilon_closure(
					move(d_states.at(current_state), *it));

			int dfa_state_id = exists(u);

			if (dfa_state_id == -1) {
				dfa_state_id = add_node(u);
			}
			connect(current_state, dfa_state_id, *it);
		}
	}
}

void DFA::connect(int node1, int node2, string input) {
	map<string, int>* connections = &this->adj_list.at(node1);
	connections->insert(pair<string, int>(input, node2));
}

map<string, int>* DFA::get_connections(int state) {
	map<int, map<string, int>>::iterator map_it = adj_list.find(state);
	if (map_it == adj_list.end())
		return nullptr;
	return &(map_it->second);
}

int DFA::add_node(set<int> nfa_states) {
	set<int> nfa_acceptors;
	set_intersection(nfa_states.begin(), nfa_states.end(), this->nfa.get_acceptors().begin(),
			this->nfa.get_acceptors().end(), inserter(nfa_acceptors, nfa_acceptors.end()));
	d_states.insert(pair<int, set<int>>(label_counter, nfa_states));
	adj_list.insert(
			pair<int, map<string, int>>(label_counter, map<string, int>()));
	if (!nfa_acceptors.empty())
		acceptors.insert(label_counter);
	label_counter++;
	return label_counter - 1;
}

void DFA::print_debug() {

	cout << "Starting: " << this->starting << endl;
	cout << "Accepting:";
	for (set<int>::iterator it = acceptors.begin(); it != acceptors.end(); it++)
		cout << " " << *it;
	cout << endl;
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
}

