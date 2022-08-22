#pragma once
#include <iostream>
#include <sstream>

#include "chain_node.h"



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
	// ��ָ��λ�ò���Ԫ��
	void insret(int the_index, T& the_element);
	// ��ȡ�������
	void output(ostream& out) const;

	// ���������Ա����ʵ��
	void bin_sort(int range);

	// ��������
	void radix_sort(int r, int range);



private:

	ChainNode<T>* first_node; // ָ������ĵ�һ��ָ��
	int list_size;		// ���Ա����
};

/// <summary>
/// ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity"></param>
template<class T>
inline Chain<T>::Chain(int initial_capacity) {
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
Chain<T>::~Chain() {
	// ���ɾ��
	while (first_node == NULL) {
		ChainNode<T>* next_node = first_node->next;
		delete first_node;
		first_node = next_node;
	}
}

/// <summary>
/// ��ָ��λ�ò���Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void Chain<T>::insret(int the_index, T& the_element) {

	if (the_index == 0) {
		// ������ͷ����
		first_node = new ChainNode<T>(the_element, first_node);
	}
	else {
		// ʹ��ָ��p����Ҫ����Ľڵ�ǰ��Ľڵ�
		ChainNode<T>* p = first_node;
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

// ���������Ա����ʵ��
template<class T>
void Chain<T>::bin_sort(int range) {
	// ��ʼ������͵���
	ChainNode<T>** top, ** bottom;
	bottom = new ChainNode<T>*[range + 1];
	top = new ChainNode<T>*[range + 1];
	for (int b = 0; b <= range; b++) {
		bottom[b] = NULL;
	}

	// ���䶥����ײ�����
	for (; first_node != NULL; first_node = first_node->next) {
		int the_bin = first_node->element;
		if (bottom[the_bin] == NULL) {
			bottom[the_bin] = top[the_bin] = first_node;
		}
		else {
			top[the_bin]->next = first_node;
			top[the_bin] = first_node;
		}
	}
	
	//�����ӷ��䵽�����б���
	ChainNode<T>* y = NULL;
	for (int the_bin = 0; the_bin <= range; the_bin++) {
		if (bottom[the_bin] == NULL) {
			continue;
		}
		if (y == NULL) {
			first_node = bottom[the_bin];
		}
		else {
			y->next = bottom[the_bin];
		}
		y = top[the_bin];
	}
	if (y != NULL) {
		y->next = NULL;
	}
	delete[] bottom;
	delete[] top;
}

// ��������
template<class T>
void Chain<T>::radix_sort(int r, int range) {
	for (int i = r; i <= range + 1; i = i * r) {
		// ��ʼ������͵���
		ChainNode<T>** top, ** bottom;
		bottom = new ChainNode<T>*[r];
		top = new ChainNode<T>*[r];
		for (int b = 0; b < r; b++) {
			bottom[b] = NULL;
		}

		// ���䶥����ײ�����
		for (; first_node != NULL; first_node = first_node->next) {
			int the_bin = ((first_node->element) % i) / (i / r);
			if (bottom[the_bin] == NULL) {
				bottom[the_bin] = top[the_bin] = first_node;
			}
			else {
				top[the_bin]->next = first_node;
				top[the_bin] = first_node;
			}
		}

		//�����ӷ��䵽�����б���
		ChainNode<T>* y = NULL;
		for (int the_bin = 0; the_bin < r; the_bin++) {
			if (bottom[the_bin] == NULL) {
				continue;
			}
			if (y == NULL) {
				first_node = bottom[the_bin];
			}
			else {
				y->next = bottom[the_bin];
			}
			y = top[the_bin];
		}
		if (y != NULL) {
			y->next = NULL;
		}
		delete[] bottom;
		delete[] top;
	
	}
}