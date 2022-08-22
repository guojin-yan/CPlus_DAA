#pragma once
#include <iostream>
template<class T>
struct ChainNode
{
	// 数据成员
	// 数据域
	T element;
	// 链域
	ChainNode<T>* next;
	ChainNode<T>* previous;


	// 构造方法
	ChainNode() {}
	ChainNode(const T& element) {
		this->element = element;
	}
	ChainNode(const T& element, ChainNode<T>* previous, ChainNode<T>* next) {
		this->element = element;
		this->next = next;
		this->previous = previous;
	}
};