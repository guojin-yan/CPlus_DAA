#pragma once
#include <iostream>

#include "chain_node.hpp"
#include "chain_iterator.hpp"
#include "illegalParameterValue.h"


using namespace std;

template<class T>
class Chain {
public:
	// ���캯�������ƹ������������
	Chain(int initial_capacity = 20);
	Chain(const Chain<T>& the_list);
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

	// ��������ĳ���
	void set_size(int the_size);
	// �滻ָ��λ��Ԫ��
	void set(int the_index, T& the_element);
	// ɾ��ָ��������Χ�ڵ�Ԫ��
	void remove_range(int form_index, int to_index);
	// ����ָ��ֵ�����ֵ�����
	int last_indexOf(T& the_element) const;
	// ������������Ԫ��
	void swap(Chain<T> the_list);




	// ������
	using iterator = ChainIterator<T>;
	iterator begin() { return iterator(first_node); }
	iterator end() { return iterator(NULL); }


	// ����[]
	T& operator[](int index);
	// ����==
	bool operator==(Chain<T> the_list);
	// ����!=
	bool operator!=(Chain<T> the_list);
	// ����<
	bool operator<(Chain<T> the_list);


private:
	// ��������Ƿ���Ч
	void check_index(int the_index) const;
	ChainNode<T>* first_node; // ָ������ĵ�һ��ָ��
	int list_size;		// ���Ա����
};

template<class T>
inline Chain<T>::Chain(int initial_capacity) {
	if (initial_capacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initial_capacity << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	first_node = NULL;
	list_size = 0;
}

/// <summary>
/// ��������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="Chain"></param>
template<class T>
Chain<T>::Chain(const Chain<T>& the_list) {
	list_size = the_list.list_size;

	if (list_size == 0) {// ������the_listΪ��
		first_node = NULL;
		return;
	}
	// ����the_list�ǿ�
	ChainNode<T>* source_node = the_list.first_node;
	// ���������ϵ���Ԫ��
	first_node = new ChainNode<T>(source_node->element);
	source_node = source_node->next;
	// ��ǰ����*this�����һ���ڵ�
	ChainNode<T>* target_node = first_node;

	while (source_node == NULL) {// ����ʣ��Ԫ��
		target_node->next = new ChainNode<T>(source_node->element);
		target_node = target_node->next;
		source_node = source_node->next;
	}

	target_node->next = NULL; // �������
}
/// <summary>
/// ��������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
Chain<T>::~Chain(){
	// ���ɾ��
	while (first_node == NULL) {
		ChainNode<T>* next_node = first_node->next;
		delete first_node;
		first_node = next_node;
	}
}


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
	ChainNode<T>* current_node = first_node;
	for (int i = 0; i < the_index; i++) {
		current_node = current_node->next;
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
	ChainNode<T> delete_Node;
	if (the_index == 0) {
		// ɾ��������׽ڵ�
		delete_Node = first_node;
		first_node = first_node->next;
	}
	else {
		// ʹ��ָ��p,��Ҫɾ���Ľڵ�ǰ��Ľڵ�
		ChainNode<T> p = first_node;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		delete_Node = p->next;
		p->next = p->next->next;
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
		s << "index = " << the_index << ", list size = "<< list_size;
		throw illegalParameterValue(s.str());
	}

	ChainNode<T> delete_Node;
	if (the_index == 0) {
		// ������ͷ����
		first_node = new ChainNode<T>(the_element, first_node);
	}
	else {
		// ʹ��ָ��p����Ҫ����Ľڵ�ǰ��Ľڵ�
		ChainNode<T> p = first_node;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		p->next = new ChainNode<T>(the_element, p->next);
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
	for (ChainNode<T> current_node = first_node;
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

