#ifndef SRC_PARSER_H
#define SRC_PARSER_H

#include <fstream>
#include <stack>
#include <string>

using namespace std;

class Parser{
	public :
		Parser();
		void process_next_line();
		~Parser();
	private:
		stack<string>* postFix_generator(string line);
		bool is_operator(char c);
		int get_order(char c);
		string get_operator(char c);
};

#endif
