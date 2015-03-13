/*
 * DFA.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: karim
 */

#include "DFA.h"

DFA::DFA(const NFA& nfa) {
	this->nfa = nfa;
	this->subset_construct();
}

void DFA::subset_construct() {
	set<int> d_states;
	set<int> visited;

	set<int> init_starts = nfa.epsilon_closure(nfa.get_starting());
	d_states.insert(init_starts.begin(), init_starts.end());

	set<int> difference;
	// TODO: change the while true to a proper condition
	while(1) {
		set_difference(d_states.begin(), d_states.end(), visited.begin(),
				visited.end(), inserter(difference, difference.end()));
		if (difference.empty() == true) break;
		int first_unmarked = *(difference.begin()); // take any arbitrary element of the set, for instance the first element
		visited.insert(first_unmarked);

		map<string, vector<int>>* connections = nfa.get_connections(first_unmarked);
		for (map<string, vector<int>>::iterator it = connections->begin(); it != connections->end();
				it++) {
			string input = it->first;
			vector<int>& next_states = it->second;
			set<int> epsClos = nfa.epsilon_closure(next_states);

			// ----------------------- where we stopped yesterday ----------------------- //

			/*
			 * if epsClos are not included in d_states
			 * 		add epsClos to d_states, unmarked
			 * add new states in DFAs adj_matrix
			 */
			if(!includes(epsClos.begin(), epsClos.end(),d_states.begin(), d_states.end())) { // if epsClos are not included in d_states
				d_states.insert(epsClos.begin(), epsClos.end());
			}
			// add epsClos to the DFA's adj_matrix
			map<string, int> in_map;
			for (set<int>::iterator it = epsClos.begin(); it != epsClos.end(); it++) {
				in_map.insert(pair<string, int>(input, *it));
			}
			adj_list.insert(pair<int, map<string, int>>(first_unmarked, in_map));
		}
		difference.clear();

	}
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

