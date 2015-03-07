/*
 * Graph.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: karim
 */

#include "Graph.h"


Graph::Graph() {
	this->count = 0;
	this->root = nullptr;
}

vector<Node*> Graph::get_nodes() {
	return this->graph_nodes;
}

/**
 * adds a new entry to the adjacency matrix with the current count
 */
void Graph::update_adj_matrix() {
	// 1) add a new boolean vector which corresponds to the current count
	this->adj_matrix.push_back(new vector<string>);
	cout << "\tnew bool vector added" << endl;
	// 2) initialize the new vector with all false values (since it's isolated)
	for (int i = 0; i < this->count; i++) {
		this->adj_matrix.at(this->count-1)->push_back("-");
	}
	cout << "\tnew bool vector initialized" << endl;
	// 3) for each of the previous nodes in the adjacency matrix, add a false
	for (int i = 0; i < this->count-1; i++) {
		this->adj_matrix.at(i)->push_back("-");
	}
	cout << "\tprev bool updated" << endl;
}

/**
 *	user can only request a new node to be added to the graph
 *	a new node is added with a label that corresponds to its count
 *	in the graph, a pointer to this node is returned which can then
 *	be used to create a connection between itself and any other node
 *	in the graph
 */
Node* Graph::add_node() {
	Node* new_node = new Node (to_string(this->count));
	this->graph_nodes.push_back(new_node);
	if (this->count == 0) { // first insertion
		this->root = new_node;
	}
	cout << "node added" << endl;
	this->count++;
	update_adj_matrix();
	cout << "matrix updated" << endl;
	return new_node;
}

void Graph::connect_nodes(Node* src, Node* dest, string input) {
	/**
	 * since all the nodes in the graph have integer labels which are
	 * monotonically increasing, validating that a node exists in the
	 * graph is equivalent to simply checking if the node's label is
	 * less than the size of the graph
	 */
	unsigned int src_int = stoi(src->getLabel(), nullptr, 10);
	unsigned int dest_int = stoi(dest->getLabel(), nullptr, 10);
	if (this->get_nodes().size() > src_int &&
		this->get_nodes().size() > dest_int) {
		src->addNext(input, dest);
		// update in adj matrix
		this->adj_matrix.at(src_int)->at(dest_int) = input;
	}

}

void Graph::print_adj_matrix() {
	cout << "current count: " << this->count << endl;
	cout << "adj matrix size: " << this->adj_matrix.size() << endl;
	for (unsigned int i = 0; i < this->count; i++) {
		cout << "\tsize of vector (" << i << "): " << this->adj_matrix.at(i)->size() << endl;
		cout << "\t" << i << ":";
		for (unsigned int j = 0; j < this->count; j++) {
			cout << " " << this->adj_matrix.at(i)->at(j);
		}
		cout << endl;
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

