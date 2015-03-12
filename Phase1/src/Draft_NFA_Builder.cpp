//============================================================================
// Notes:
// 	* all definitions of (int*) should be replaced with (NFA*)
// 	* functions are assumed to be implemented in other files
//	* generate_terminal_NFA is unimplemented
//============================================================================

#include <iostream>
#include <fstream>
#include <stack>
#include <map>
using namespace std;


ifstream in;
map<string, int*> nonterminal_NFA_map;



string read_next_line(){
	string line;
	getline(in, line);
	return line;
}


bool is_operation(string s){
	return s.compare("|")==0 || s.compare("*")==0 || s.compare("+")==0 || s.compare(".")==0;
}

bool is_unary_operation(string s){
	return s.compare("*")==0 || s.compare("+")==0;
}


int* parse_operand_to_NFA(string s){
	map<string, int*>::iterator it = nonterminal_NFA_map.find(s);
	if(nonterminal_NFA_map.find(s) != nonterminal_NFA_map.end())
		return nonterminal_NFA_map[s];

	int* nfa;
	nfa->connect(			// connect NFA of the terminal in single edge:	S------>A
		add_starting(),
		add_acceptor(s),
		s );

	return nfa;
}



int* connect_NFA_with_operation(int* op1, int* op2, string operation){

	if(operation.compare("|")){
		return NFA._union(op1, op2);
	}else if(operation.compare(".")){
		return NFA._concatenate(op1, op2);
	}else if(operation.compare("+")){
		return _concat(_clone(op1), _close(op1));
	}
	// do we need to call distructors of original NFA's??
}



int* generate_terminal_NFA(stack<string> s){

}



int* generate_nonterminal_NFA(stack<string> s){
	stack<int*> tmp;
	int* op1, op2;
	int* complete_NFA;

	while(!s.empty()){

		op1=NULL;
		if(is_operation(s.top())){		// make an operation
			op2 = tmp.top();
			tmp.pop();
			if(!is_unary_operation(s.top())){
				op1 = tmp.top();
				tmp.pop();
			}

			int* tmp_NFA = connect_NFA_with_operation(op1, op2, s.top());
			tmp.push(tmp_NFA);
		}else{							// add operand on top of tmp stack
			int* tmp_NFA = parse_operand_to_NFA(s.top());	// push NFA
			tmp.push(tmp_NFA);
		}

		s.pop();
	}
}


int* process_next_line(){

	int i, j;
	string line = read_next_line();
	for(i = 0; i<line.length() && line[i]==' '; i++);	// pass all spaces before name
	for(j = ++i; i<line.length() && line[i]!=' ' && line[i]!='=' && line[i]!=':'; i++);	// pass all spaces before name

	string lable = line.substr(i, j-i);
	int* nfa;

	stack<string> s = postFix_generator(line.substr(j+1, line.length()));

	if(line.find(':')!= string::npos){	// defining nonterminal
		nfa = generate_nonterminal_NFA(s);
	}else{								// defining terminal
		nfa = generate_terminal_NFA(s);
	}


}





int main() {
	in.open("test.txt");
	return 0;
}
