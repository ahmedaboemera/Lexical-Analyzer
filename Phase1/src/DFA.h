/*
 * DFA.h
 *
 *  Created on: Mar 12, 2015
 *      Author: karim
 */

#ifndef SRC_DFA_H_
#define SRC_DFA_H_

#include "NFA.h"

class DFA {
public:
	DFA(NFA& nfa);

	void print_debug();

	int add_node(set<int> nfa_states); // adds a regular node in the graph

	void connect(int node1, int node2, string input);

	map<string, int>* get_connections(int state);

	~DFA();
private:
	NFA nfa;
	static unsigned int label_counter;
	int starting;
	map<int, set<int>> d_states;
	map<int, map<string, int>> adj_list;
	void subset_construct();
	int exists(set<int> u);
	int get_first_unvisited_state(set<int> visited);
	set<int> move(set<int> nfa_states, string in);
	set<int> acceptors;
};

#endif /* SRC_DFA_H_ */
