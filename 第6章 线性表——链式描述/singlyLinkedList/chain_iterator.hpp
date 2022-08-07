#pragma once
#include <iostream>
#include "chain_node.hpp"
using namespace std;

template<class T>
class ChainIterator {
	// 向前迭代器
public:
	// 构造函数
	ChainIterator(ChainNode<T>* the_node = NULL) {
		node = the_node;
	}
	// 解引用操作
	T& operator*() const { return node->element; }
	T* operator->() const { return &node->element; }

	// 迭代器假发操作
	ChainIterator<T>& operator++() {	// 前加
		node = node->next;
		return *this;
	}
	ChainIterator<T>& operator++(int) {	// 后加
		ChainIterator<T> old = *this;
		node = node->next;
		return old;
	}

	// 相等性检验
	bool operator!=(const ChainIterator<T> right) const {
		return node != right.node;
	}
	bool operator==(const ChainIterator<T> right) const {
		return node == right.node;
	}

protected:
	ChainNode<T>* node;
};