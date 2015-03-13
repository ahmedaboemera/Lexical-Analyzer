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
	DFA(const NFA& nfa);
	Acceptor accepts(string expression); // returns null if expression
										 // is not accepted
	void print_debug();
	~DFA();
private:
	NFA nfa;
	map<int, map<string, int>> adj_list;
	void subset_construct();
};

#endif /* SRC_DFA_H_ */
