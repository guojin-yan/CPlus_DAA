#pragma once
#include "arrayList.hpp"
#include "chain.hpp"
#include "chain_node.h"

template<class T>
void array_to_chain_list(ArrayList<T>& array_list, Chain<T>& chain) {
	if (array_list.size() == 0) {
		return;
	}
	for (int i = 0; i < array_list.size(); i++) {
		chain.insret(i, array_list[i]);
	}
}
template<class T>
void chain_to_array_list( Chain<T>& chain, ArrayList<T>& array_list ) {
	if (chain.size() == 0) {
		return;
	}

	for (int i = 0; i < chain.size(); i++) {
		array_list.insert(i, chain[i]);
	}
}
template<class T>
void meld(Chain<T>& chain, Chain<T>& chain1, Chain<T>& chain2) {
	int max_length = max(chain1.size(), chain2.size());
	for (int i = 0; i < max_length; i++) {
		T temp1 = chain1.size() > i ? chain1[i] : NULL;
		T temp2 = chain2.size() > i ? chain2[i] : NULL;

		if (temp1 != NULL) {
			chain.insret(chain.size(), temp1);
		}
		if (temp2 != NULL) {
			chain.insret(chain.size(), temp2);
		}
	}

}

