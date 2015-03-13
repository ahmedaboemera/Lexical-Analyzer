/*
 * NFABuilder.h
 *
 *  Created on: 12 Mar 2015
 *      Author: ahmedaboemera
 */

#ifndef SRC_NFABUILDER_H_
#define SRC_NFABUILDER_H_

#include <iostream>
#include <fstream>
#include <stack>
#include <map>
<<<<<<< HEAD
<<<<<<< HEAD
#include <NFA.h>
#include <Parser.h>
=======
=======
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
#include "NFA.h"
#include "Parser.h"
#include <string>
#include <vector>
<<<<<<< HEAD
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0
=======
>>>>>>> c52159a70d9a1726a1191f5192aa1fee3ae2a5c0

class NFA_Builder {
public:
	NFA_Builder(char* filename);
	NFA* process_file();
	virtual ~NFA_Builder();
private:
	Parser* p;
	ifstream in;
	map<string, NFA*> nonterminal_NFA_map;
	NFA* process_next_line();
	string read_next_line();
	bool is_operation(string s);
	bool is_unary_operation(string s);
	NFA* parse_operand_to_nfa(string s);
	NFA* connect_operand_with_operation(NFA* op1, NFA* op2, string operation);
	NFA* generate_terminal_nfa(stack <string>* s);
	NFA* generate_nonterminal_nfa(stack <string>* s);
};

#endif /* SRC_NFABUILDER_H_ */
