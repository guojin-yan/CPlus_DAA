#pragma once
template<class T>
struct ChainNode
{
	// ���ݳ�Ա
	// ������
	T element;
	// ����
	ChainNode<T>* next;

	// ���췽��
	ChainNode() {}
	ChainNode(const T& element) {
		this->element = element;
	}
	ChainNode(const T& element, ChainNode<T>* next) {
		this->element = element;
		this->next = next;
	}
};