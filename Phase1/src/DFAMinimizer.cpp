/*
 * DFAMinimizer.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: omar
 */

#include "DFAMinimizer.h"


void DFAMinimizer::_minimize_dfa(DFA* in, DFA* out){
//	// get all acceptor nodes & group them
//	// get other nodes
//
//	int num_states_before=0, num_states_after=-1;
//	map<int, int> node_state_map = *(new map<int, int>);
//
//	while(num_states_before != num_states_after){
//
//
//	}
	map<int,map<int,set<pair<int,int> > > >* next_in = new map<int, map<int, pair<int, int> > >();
	_build_map(in, next_in);
	_reduce(next_in, out);
}

void DFAMinimizer:: _build_map(DFA* in, map<int,map<int,set<pair<int,int> > > >* out){
	vector<int>* states = in->get_states();
	for(int i : *states){
		for(int j : *states){
			if(i == j){

				map[i][j]=NULL;

			}else{

				if((in->is_acceptor(i) && in->is_acceptor(j))
						|| (!in->is_acceptor(i) && !in->is_acceptor(j))){

					map<string, int>* i_connections = in->get_connections(i);
					map<string, int>* j_connections = in->get_connections(j);

					map<string,int>::iterator it;

					vector<string> inputs = in->inputs();
					set<pair<int,int> >* to_add_in_map;

					bool put_x = false;

					for(string s : inputs){
						map<string, int>::iterator it_1;
						map<string, int>::iterator it_2;
						it_1 = i_connections->find(s);
						it_2 = j_connections->find(s);
						if((it_1 == i_connections->end() && it_2 == j_connections->end())
								||
									(it_1 != i_connections->end() && it_2 != j_connections->end()))
						{
							pair<int,int> s;
							s.first  = it_1->second;
							s.second = it_2->second;
							to_add_in_map->insert(s);
						}else{
							put_x = true;
							break;
						}
					}

					if(put_x){
						map[i][j] = NULL;
					}else{
						map[i][j] = *to_add_in_map;
					}

				}
				else{
					map[i][j] = NULL;
				}
			}
		}
	}
}

void DFAMinimizer:: _reduce(map<int,map<int,set<pair<int,int> > > >* in, DFA* out){

}
