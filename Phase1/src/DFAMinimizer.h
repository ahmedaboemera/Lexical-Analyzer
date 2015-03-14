/*
 * DFAMinimizer.h
 *
 *  Created on: Mar 13, 2015
 *      Author: omar
 */

#ifndef SRC_DFAMINIMIZER_H_
#define SRC_DFAMINIMIZER_H_

#include "DFA.h"
#include <map>

class DFAMinimizer {
public:

	DFAMinimizer();
	static void _minimize_dfa(DFA* in_dfa, DFA* out_dfa);
	virtual ~DFAMinimizer();
};

#endif /* SRC_DFAMINIMIZER_H_ */
