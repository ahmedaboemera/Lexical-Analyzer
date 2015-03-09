#include <iostream>
#include "NFA.h"

using namespace std;

int main() {
	cout << NFA::label_counter << endl;
	cout << "hello world" << endl;
	cout << "trying the script out..." << endl;
	NFA* n = new NFA();
	n->add_node();
	delete n;
}

