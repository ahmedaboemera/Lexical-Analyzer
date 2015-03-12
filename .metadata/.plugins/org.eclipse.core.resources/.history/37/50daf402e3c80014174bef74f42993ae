#include <iostream>
#include "NFA.h"

using namespace std;

//NFA* foo() {
//	NFA* t = new NFA();
//
//	int st = t->add_starting();
//	int x1 = t->add_node();
//	int x2 = t->add_node();
//	int x3 = t->add_node();
//	int x4 = t->add_node();
//	int acc = t->add_acceptor("a|b");
//
//	t->connect(st, x1, "");
//	t->connect(st, x2, "");
//
//	t->connect(x1, x3, "a");
//
//	t->connect(x2, x4, "b");
//
//	t->connect(x3, acc, "");
//	t->connect(x4, acc, "");
//
//	return t;
//}

NFA foo() {
	NFA t;

	int st = t.add_starting();
	int x1 = t.add_node();
	int x2 = t.add_node();
	int x3 = t.add_node();
	int x4 = t.add_node();
	int acc = t.add_acceptor("a|b");

	t.connect(st, x1, "");
	t.connect(st, x2, "");

	t.connect(x1, x3, "a");

	t.connect(x2, x4, "b");

	t.connect(x3, acc, "");
	t.connect(x4, acc, "");

	return t;
}

int main() {

	NFA t = foo();

	t.print_debug();

	return 0;
}
