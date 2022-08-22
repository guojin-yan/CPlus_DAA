#pragma once
#include <iostream>
#include <sstream>

#include "chain_node.h"
#include "illegalParameterValue.h"

using namespace std;

template <class T>
class Chain {
public:
	Chain(int initial_capacity);
	~Chain();

	// ��ͨ����
	// �Ƿ�Ϊ��
	bool empty() { return list_size == 0; }
	// ��ȡ������
	int size() const { return list_size; }
	// ��ȡָ��������Ԫ��
	T& get(int the_index) const;
	// ��ȡָ��Ԫ�ص�����
	int indexOf(const T& the_element) const;
	// ɾ��ָ��λ�õ�Ԫ��
	void erase(int the_index);
	// ��ָ��λ�ò���Ԫ��
	void insret(int the_index, T& the_element);
	// ��ȡ�������
	void output(ostream& out) const;

private:
	// ��������Ƿ���Ч
	void check_index(int the_index) const;
	ChainNode<T>* first_node;	// �׽ڵ�
	ChainNode<T>* last_node;	// ĩβ�ڵ�
	int list_size;	// ������
};

template <class T>
Chain<T>::Chain(int initial_capacity) {
	if (initial_capacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initial_capacity << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	first_node = NULL;
	last_node = NULL;
	list_size = 0;
}


/// <summary>
/// ��������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
Chain<T>::~Chain() {
	// ���ɾ��
	while (first_node == NULL) {
		ChainNode<T>* next_node = first_node->next;
		delete first_node;
		first_node = next_node;
	}
}

/// <summary>
/// ���������Ƿ���Ч
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
inline void Chain<T>::check_index(int the_index) const {
	if (the_index < 0 || the_index > list_size) {
		ostringstream s;
		s << "index = " << the_index << ", list size = " << list_size;
		throw illegalParameterValue(s.str());
	}
}




/// <summary>
/// ��ȡ����Ϊ the_index ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
inline T& Chain<T>::get(int the_index) const {
	// �������
	check_index(the_index);
	// �ƶ�������Ҫ�Ľڵ�
	ChainNode<T>* current_node;
	if (the_index < list_size / 2) {
		// �ƶ�������Ҫ�Ľڵ�
		current_node = first_node;
		for (int i = 0; i < the_index; i++) {
			current_node = current_node->next;
		}
	}
	else {
		// �ƶ�������Ҫ�Ľڵ�
		current_node = last_node;
		for (int i = 0; i < list_size - the_index; i++) {
			current_node = current_node->previous;
		}
	}

	return current_node->element;
}

/// <summary>
/// ��ȡָ��Ԫ�ص���������Ԫ�ز����ڷ���-1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
/// <returns></returns>
template<class T>
int Chain<T>::indexOf(const T& the_element) const {
	// ����������Ԫ��
	ChainNode<T>* current_node = first_node;
	int index = 0;
	while (current_node != NULL && current_node->element != the_element) {
		current_node = current_node->next;
		index++;
	}

	// ȷ���Ƿ��ҵ�����Ԫ��
	if (current_node == NULL) {
		return -1;
	}
	else {
		return index;
	}
}


/// <summary>
/// ɾ��ָ��λ�õ�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void Chain<T>::erase(int the_index) {
	// �ж������Ƿ�Խ��
	check_index(the_index);

	// Ѱ��Ҫɾ����Ԫ�ؽڵ�
	ChainNode<T>* delete_Node;
	if (the_index == 0) {
		// ɾ��������׽ڵ�
		delete_Node = first_node;
		first_node = first_node->next;
		first_node->previous = NULL;
	}
	else {
		// ʹ��ָ��p,��Ҫɾ���Ľڵ�ǰ��Ľڵ�
		ChainNode<T>* p = first_node;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		delete_Node = p->next;
		p->next = p->next->next;
		ChainNode<T>* current_node = p;
		p = p->next;
		p->previous = current_node;
	}
	list_size--;
	delete delete_Node;
}


/// <summary>
/// ��ָ��λ�ò���Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void Chain<T>::insret(int the_index, T& the_element) {
	if (the_index < 0 || the_index > list_size) {
		ostringstream s;
		s << "index = " << the_index << ", list size = " << list_size;
		throw illegalParameterValue(s.str());
	}


	if (the_index == 0) {
		// ������ͷ����
		first_node = new ChainNode<T>(the_element, NULL, first_node);
		if (list_size == 0) {
			last_node = first_node;
		}
	}
	else if (the_index == list_size - 1) {
		last_node = new ChainNode<T>(the_element, last_node, NULL);
	}
	else {
		// ʹ��ָ��p����Ҫ����Ľڵ�ǰ��Ľڵ�
		ChainNode<T>* p = first_node;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		p->next = new ChainNode<T>(the_element, p, p->next);
	}
	list_size++;
}

/// <summary>
/// ��ȡ�������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
template<class T>
void Chain<T>::output(ostream& out) const
{
	for (ChainNode<T>* current_node = first_node;
		current_node != NULL;
		current_node = current_node->next) {
		out << current_node->element << " ";
	}
}













template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x) {
	x.output(out);
	return out;
}