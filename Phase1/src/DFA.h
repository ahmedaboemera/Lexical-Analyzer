/*
 * DFA.h
 *
 *  Created on: Mar 12, 2015
 *      Author: karim
 */

#ifndef SRC_DFA_H_
#define SRC_DFA_H_

#include "NFA.h"

class DFAState {
public:
	DFAState(int _id, set<int> _nfa_states);
	int getId() const;
	set<int> get_nfa_states() const;
	~DFAState();
private:
	int id;
	set<int> nfa_states;
};

class DFA {
public:
	DFA(const NFA& nfa);
	Acceptor accepts(string expression); // returns null if expression
										 // is not accepted
	void print_debug();

	int add_node(); // adds a regular node in the graph
	int add_starting(); // adds a starting node to the graph
	int add_acceptor(string accepted_expression = "NONE");

	~DFA();
private:
	static unsigned int label_counter;
	NFA nfa;
	map<DFAState, map<string, DFAState>> adj_list;
	void subset_construct();
};

#endif /* SRC_DFA_H_ */
