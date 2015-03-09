#include <iostream>
#include "Node.h"

using namespace std;

Node create_nodes() {
	Node n1 ("1");
	Node n2 ("2");
	Node n3 ("3");

	n1.addNext("a", &n2);
	n2.addNext("b", &n3);
	n3.addNext("", nullptr);

	cout << n1.getLabel() << endl; // prints 1
	cout << n1.getNext("a")->getLabel() << endl; // prints 2
	cout << n1.getNext("a")->getNext("b")->getLabel() << endl;

	return n1;
}

int main() {
	Node n = create_nodes();
	cout << "hello world" << endl;
	cout << "trying the script out..." << endl;
}

