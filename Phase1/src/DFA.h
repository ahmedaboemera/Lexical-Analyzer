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
	~DFA();
private:
	NFA nfa;
	vector<int> epsilon_closure(int node);
	vector<int> epsilon_closure(vector<int> node);
	void subset_construct();
};

#endif /* SRC_DFA_H_ */
