#pragma once
#include <iostream>
template<class T>
struct ChainNode
{
	// ���ݳ�Ա
	// ������
	T element;
	// ����
	ChainNode<T>* next;
	ChainNode<T>* previous;


	// ���췽��
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