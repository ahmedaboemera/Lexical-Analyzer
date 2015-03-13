#ifndef SRC_NFA_H_
#define SRC_NFA_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

#define EPS ""

using namespace std;

class Acceptor {
public:
	Acceptor(int id, string accepted_expression) {
		this->id = id;
		this->accepted_expr = accepted_expression;
	}
	int get_id() const {
		return this->id;
	}
	string get_accepted_expression() const {
		return this->accepted_expr;
	}
	~Acceptor() {
	}
private:
	int id;
	string accepted_expr;
};

class NFA {

public:
	NFA();
	static NFA* _concatenate(const vector<NFA*>& gs);
	static NFA* _union(const vector<NFA*>& gs);
	static NFA* _close(const NFA& g);
	int add_node(); // adds a regular node in the graph
	int add_starting(); // adds a starting node to the graph
	int add_acceptor(string accepted_expression = "NONE");
	vector<int> get_starting();
	set<string> get_lang();
	void connect(int node1, int node2, string input);
	void print_debug();
	set<int> epsilon_closure(vector<int> node);
	set<int>* next_states(int cur_state, string input); //TODO: returning the vector pointer is dangerous.
	map<string, set<int>>* get_connections(int state);
	~NFA();

private:
	static unsigned int label_counter;
	vector<int> starting_points;
	vector<Acceptor> acceptors;
	map<int, map<string, set<int> > > adj_list;
	set<string> input_laguage;
};

#endif /* SRC_NFA_H_ */
