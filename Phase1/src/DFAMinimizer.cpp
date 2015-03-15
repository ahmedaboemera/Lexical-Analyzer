/*
 * DFAMinimizer.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: omar
 */

#include "DFAMinimizer.h"



void update_map(vector<set<int> >* sets_after, map<int, int>* node_set_map){
cout<<"new sets are:\n";
	node_set_map->clear();

	int i=0;
	for(set<int> s:*sets_after){		// iterating on the vector
		for(int state : s){
cout<<"\t"<<state;
			node_set_map->insert(pair<int, int>(state, i));
		}
		i++;
cout<<"\n";
	}
}



void DFAMinimizer::_minimize_dfa(DFA* in, DFA* out){
	vector<set<int> > sets_before, sets_after;

	// get all acceptor nodes & group them

	//------ temp code for testing -------
	set<int> s1, s2;
	s1.insert(0);s1.insert(1);s1.insert(2);s1.insert(3);	// all non-accepting states in test example
	s2.insert(4);											// all accepting states in test example
	sets_after.push_back(s1);
	sets_after.push_back(s2);
	//------------------------------------

	map<int, int> node_set_map;
	update_map(&sets_after, &node_set_map);

	while(sets_before.size() != sets_after.size()){
cout<<"\n\n-------------------------------\n\tstarting new pass\n-------------------------------\n\n";
		sets_before.clear();
		sets_before = sets_after;
		sets_after.clear();

		for(set<int> s:sets_before){				// loop on sets

			vector<set<int>> splitted_sets;
			for(int state : s){						// loop on states
cout<<"\nworking on state "<<state<<":\n\n     ";
				bool found_group=false;

				vector<set<int>>::iterator s_next_level=splitted_sets.begin();
				for(; s_next_level!=splitted_sets.end(); s_next_level++){		// looping on splitted sets
					map<string, int> m1 = *in->get_connections(*s_next_level->begin());
					map<string, int> m2 = *in->get_connections(state);
					map<string, int>::iterator it;

					// check if state is mergeable with this set - compare connections
					for(it = m1.begin(); it!= m1.end(); it++){
						// o/p undefined for this input || output nodes are in different sets
						if(m2.find(it->first)==m2.end() || node_set_map[ m2[it->first] ] != node_set_map[it->second])
							break;
					}

					// found the set that matches
					if(it==m1.end()){
						found_group = true;
						break;
					}
				}
				if(found_group){				// add this state to the lucky set
cout<<"\t--adding to splitted_set .. set after update:\n";
					s_next_level->insert(state);
				}else{							// create a set for this poor state
cout<<"\t--creating new set ...\n";
					set<int> new_set;			// Baaaaaaaaaaaaaaaad allocation
					new_set.insert(state);
					splitted_sets.push_back(new_set);
				}

			}
			sets_after.insert(sets_after.end(), splitted_sets.begin(), splitted_sets.end());	// append splitted sets
		}

		// update node_state_map for the next iteration
		update_map(&sets_after, &node_set_map);
		int i;
		cin>>i;
	}
}




//void _convert_map_to_DFA(map<int,map<int,pair<int,int> > >* in,
//		map<int, map<int, bool>>* are_reducable, DFA* out){
//
//	map<int,map<int,pair<int,int> > >::iterator it1;
//	map<int,pair<int,int> >::iterator it2;
//
//	for(it1 = in->begin(); it1 != in->end(); it1++){
//		for(it2 = it1->second.begin(); it2 != it1->second.end(); it2++){
//			if(!are_reducable[it2->second.first][it2->second.second]){
//
//			}
//		}
//	}
//}



//void DFAMinimizer::_reduce(map<int,map<int,pair<int,int> > >* in, DFA* out){
//	bool not_finished = true;
//	map<int, map<int, bool>> are_reducable;
//
//	map<int,map<int,pair<int,int> > >::iterator it1;
//	map<int,pair<int,int> >::iterator it2;
//
//	// initialize bool maps
//	for(it1 = in->begin(); it1 != in->end(); it1++)
//		for(it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
//			are_reducable[it1->first][it2->first] = false;
//
//	// make passes as long as possible
//	while(not_finished){
//		not_finished = false;
//
//		// make a pass on all combinations
//		for(it1 = in->begin(); it1 != in->end(); it1++){
//
//			for(it2 = it1->second.begin(); it2 != it1->second.end(); it2++){
//
//				if(!are_reducable[it2->second.first][it2->second.second]){
//					are_reducable[it2->second.first][it2->second.second] = false;
//					are_reducable[it2->second.second][it2->second.first] = false;
//					not_finished = true;
//				}
//			}
//		}
//	}
//
//	_convert_map_to_DFA(in, &are_reducable, out);
//	return;
//}



//void DFAMinimizer::_minimize_dfa(DFA* in_dfa, DFA* out_dfa){
//
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
