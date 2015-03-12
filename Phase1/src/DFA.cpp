/*
 * DFA.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: karim
 */

#include "DFA.h"

DFA::DFA(const NFA& nfa) {
	this->nfa = nfa;
}

vector<int> DFA::epsilon_closure(int node) {
//	nfa.next_states(node, EPS);
}

DFA::~DFA() {
	// TODO Auto-generated destructor stub
}

