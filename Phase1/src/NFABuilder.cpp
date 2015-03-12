/*
 * NFABuilder.cpp
 *
 *  Created on: 12 Mar 2015
 *      Author: ahmedaboemera
 */

#include "NFABuilder.h"

#include <string>
#include <vector>

NFA_Builder::NFA_Builder(const char* s) {
	this->in.open(s);
	p = new Parser();
}

NFA* NFA_Builder::process_file() {

}

NFA* NFA_Builder::process_next_line() {
	int i, j;
	string line = read_next_line();
	for (i = 0; i < line.length() && line[i] == ' '; i++)
		;	// pass all spaces before name
	for (j = ++i;
			i < line.length() && line[i] != ' ' && line[i] != '='
					&& line[i] != ':'; i++)
		;	// pass all spaces before name

	string lable = line.substr(i, j - i);
	NFA* nfa;

	stack<string> s = p.postFix_generator(line.substr(j + 1, line.length()));

	if (line.find(':') != string::npos) {	// defining nonterminal
		nfa = generate_nonterminal_NFA(s);
	} else {								// defining terminal
		nfa = generate_terminal_NFA(s);
	}
	return nfa;
}

string NFA_Builder::read_next_line() {

}

bool NFA_Builder::is_operation(string s) {

}

bool NFA_Builder::is_unary_operation(string s) {

}

NFA* NFA_Builder::parse_operand_to_nfa(string s) {

}

NFA* NFA_Builder::connect_operand_with_operation(NFA* op1, NFA* op2, string operation) {
	if(operation.compare("*"))
		return NFA_close(op1);

	vector<NFA*> tmp = new vector<NFA*>();

	if(operation.compare("+")){
		tmp.push_back(NFA._clone(op1));
		tmp.push_back(NFA._close(op1));
		return NFA._concatenate(&tmp);
	}

	tmp.push_back(op1);
	tmp.push_back(op2);

	if(operation.compare("|")){
		return NFA._union(&tmp);
	}else if(operation.compare(".")){
		return NFA._concatenate(&tmp);
	}else if(operation.compare("*")){
		return NFA._close(op1);
	}
	// do we need to call distructors of original NFA's??
	return new NFA();	// wrong operation
}

NFA* NFA_Builder::generate_terminal_nfa(stack<string> s) {

}

NFA* NFA_Builder::generate_nonterminal_nfa(stack<string> s) {
	stack<NFA*> tmp;
	NFA *op1, *op2;
	NFA* complete_NFA;

	while (!s.empty()) {

		op1 = NULL;
		if (is_operation(s.top())) {		// make an operation
			op2 = tmp.top();
			tmp.pop();
			if (!is_unary_operation(s.top())) {
				op1 = tmp.top();
				tmp.pop();
			}
			string tt = s.top();
			NFA* tmp_NFA = connect_operand_with_operation(op1, op2, tt);
			tmp.push(tmp_NFA);
		} else {							// add operand on top of tmp stack
			NFA* tmp_NFA = parse_operand_to_NFA(s.top());	// push NFA
			tmp.push(tmp_NFA);
		}

		s.pop();
	}
	return complete_NFA;
}

NFA_Builder::~NFA_Builder() {
	// TODO Auto-generated destructor stub
}

