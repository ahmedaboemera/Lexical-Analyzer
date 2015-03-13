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
	Acceptor accepts(string expression); // returns null if expression
										 // is not accepted
	void print_debug();

	int add_node(set<int> nfa_states); // adds a regular node in the graph

	void connect(int node1, int node2, string input);

	~DFA();
private:
	NFA nfa;
	static unsigned int label_counter;
	int starting;
	map<int, set<int>> d_states;
	map<int, map<string, int>> adj_list;
	void subset_construct(NFA& nfa);
	int exists(set<int> u);
	set<int> move(set<int> nfa_states, string in);
};

#endif /* SRC_DFA_H_ */
