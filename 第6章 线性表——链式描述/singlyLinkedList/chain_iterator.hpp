#pragma once
#include <iostream>
#include "chain_node.hpp"
using namespace std;

template<class T>
class ChainIterator {
	// ��ǰ������
public:
	// ���캯��
	ChainIterator(ChainNode<T>* the_node = NULL) {
		node = the_node;
	}
	// �����ò���
	T& operator*() const { return node->element; }
	T* operator->() const { return &node->element; }

	// �������ٷ�����
	ChainIterator<T>& operator++() {	// ǰ��
		node = node->next;
		return *this;
	}
	ChainIterator<T>& operator++(int) {	// ���
		ChainIterator<T> old = *this;
		node = node->next;
		return old;
	}

	// ����Լ���
	bool operator!=(const ChainIterator<T> right) const {
		return node != right.node;
	}
	bool operator==(const ChainIterator<T> right) const {
		return node == right.node;
	}

protected:
	ChainNode<T>* node;
};