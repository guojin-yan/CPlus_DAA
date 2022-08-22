#pragma once
#include <iostream>
#include <sstream>


#include "chain_node.h"
#include "chain_iterator.hpp"
#include "illegalParameterValue.h"


using namespace std;

template<class T>
class Chain {
public:
	// ���캯�������ƹ������������
	Chain(int initial_capacity = 20);
	//Chain(const Chain<T>& the_list);
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

	//// ��������ĳ���
	//void set_size(int the_size);
	//// �滻ָ��λ��Ԫ��
	//void set(int the_index, T& the_element);
	//// ɾ��ָ��������Χ�ڵ�Ԫ��
	//void remove_range(int form_index, int to_index);
	//// ����ָ��ֵ�����ֵ�����
	//int last_indexOf(T& the_element) const;
	//// ������������Ԫ��
	//void swap(Chain<T> &the_list);
	//// ��array_listתΪchain
	//void from_list(ArrayList<T>& array_list);
	//// ��chainתΪarray_list
	//void to_list(ArrayList<T>& array_list);
	//// ����Ԫ��
	//void left_shift(int num);
	// �ߵ�Ԫ��
	void reverse();
	//// �ϲ�����
	//void meld(Chain<T>& the_list1, Chain<T>& the_list2);
	//// �ϲ����������б�
	//void merge(Chain<T>& the_list1, Chain<T>& the_list2);
	//// ������������б�
	//void spilt(Chain<T>& the_list1, Chain<T>& the_list2);
	//// ѭ������Ԫ��
	//void circular_shift(int index);





	//// ������
	//using iterator = ChainIterator<T>;
	//iterator begin() { return iterator(first_node); }
	//iterator end() { return iterator(NULL); }


	//// ����[]
	//T& operator[](int index) const;
	//// ����==
	//bool operator==(Chain<T>& the_list) const;
	//// ����!=
	//bool operator!=(Chain<T>& the_list) const;
	//// ����<
	//bool operator<(Chain<T>& the_list) const;


private:
	// ��������Ƿ���Ч
	void check_index(int the_index) const;
	ChainNode<T>* header_node; // ͷ�ڵ�
	int list_size;		// ���Ա����
};

/// <summary>
/// ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity"></param>
template<class T>
inline Chain<T>::Chain(int initial_capacity) {
	if (initial_capacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initial_capacity << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	header_node = new ChainNode<T>();
	header_node->next = header_node;
	list_size = 0;
}
//
///// <summary>
///// ��������
///// </summary>
///// <typeparam name="T"></typeparam>
///// <param name="Chain"></param>
//template<class T>
//Chain<T>::Chain(const Chain<T>& the_list) {
//	list_size = the_list.list_size;
//
//	if (list_size == 0) {// ������the_listΪ��
//		first_node = NULL;
//		return;
//	}
//	// ����the_list�ǿ�
//	ChainNode<T>* source_node = the_list.first_node;
//	// ���������ϵ���Ԫ��
//	first_node = new ChainNode<T>(source_node->element);
//	source_node = source_node->next;
//	// ��ǰ����*this�����һ���ڵ�
//	ChainNode<T>* target_node = first_node;
//
//	while (source_node == NULL) {// ����ʣ��Ԫ��
//		target_node->next = new ChainNode<T>(source_node->element);
//		target_node = target_node->next;
//		source_node = source_node->next;
//	}
//
//	target_node->next = NULL; // �������
//}


 //<summary>
 //��������
 //</summary>
 //<typeparam name="T"></typeparam>
template<class T>
Chain<T>::~Chain(){
	ChainNode<T>* delete_node = header_node->next;
	// ���ɾ��
	while (delete_node != header_node) {
		ChainNode<T>* next_node = delete_node->next;
		delete delete_node;
		delete_node = next_node;
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
//#pragma region ��������




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
	ChainNode<T>* current_node = header_node->next;
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
	ChainNode<T>* current_node = header_node->next;
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
		delete_Node = header_node->next;
		header_node->next = delete_Node->next;
	}
	else {
		// ʹ��ָ��p,��Ҫɾ���Ľڵ�ǰ��Ľڵ�
		ChainNode<T>* p = header_node->next;
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

	
	if (the_index == 0) {
		// ������ͷ����
		ChainNode<T>* current_Node = new ChainNode<T>(the_element, header_node->next);
		header_node->next = current_Node;
	}
	else {
		// ʹ��ָ��p����Ҫ����Ľڵ�ǰ��Ľڵ�
		ChainNode<T>* p = header_node->next;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		p->next = new ChainNode<T>(the_element, p->next);
		p = p->next;
		p->next = header_node;
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
	for (ChainNode<T>* current_node = header_node->next;
		current_node != header_node;
		current_node = current_node->next) {
		out << current_node->element << " ";
	}
}




//// ��������ĳ���
//template<class T>
//void Chain<T>::set_size(int the_size) {
//	if (the_size >= list_size) {
//		// ������ó��ȴ���ԭ�г���
//		return;
//	}
//	else {
//		// �ҵ�ָ������λ��
//		ChainNode<T>* current_node = first_node;
//		for (int i = 0; i < the_size-1; i++) {
//			current_node = current_node->next;
//		}		
//		ChainNode<T>* delete_node = current_node->next;
//		// ��ָ������λ����Ϊ����λ��
//		current_node->next = NULL;
//		// ɾ������ԭ�еĳ���
//		while(current_node == NULL) {
//			current_node = delete_node->next;
//			delete delete_node;
//		}
//		list_size = the_size;
//	}
//}
//// �滻ָ��λ��Ԫ��
//template<class T>
//void Chain<T>::set(int the_index, T& the_element) {
//	check_index(the_index);
//	// �ҵ�ָ��λ��
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; i < the_index; i++) {
//		current_node = current_node->next;
//	}
//	current_node->element = the_element;
//}
//// ɾ��ָ��������Χ�ڵ�Ԫ��
//template<class T>
//void Chain<T>::remove_range(int form_index, int to_index) {
//	check_index(to_index);
//	// �ҵ�ָ��λ��
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; i < form_index; i++) {
//		current_node = current_node->next;
//	}
//	// ��¼��ʼλ��node
//	ChainNode<T>* form_node = current_node;
//	current_node = current_node->next;
//	ChainNode<T>* delete_node;
//	// ɾ����Χ�ڵ�Ԫ��
//	for (int i = 0; i < to_index-form_index; i++) {
//		delete_node = current_node;
//		current_node = current_node->next;
//		delete delete_node;
//	}
//	// ��ɾ����Χ��������������
//	form_node->next = current_node;
//	list_size -= (to_index - form_index);
//}
//// ����ָ��ֵ�����ֵ�����
//template<class T>
//int Chain<T>::last_indexOf(T& the_element) const {
//	int index = -1;
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; current_node != NULL; i++) {
//		if (current_node->element == the_element) {
//			index = i;
//		}
//		current_node = current_node->next;
//	}
//	return index;
//
//}
//// ������������Ԫ��
//template<class T>
//void Chain<T>::swap(Chain<T> &the_list) {
//	ChainNode<T>* current_node = first_node;
//	first_node = the_list.first_node;
//	the_list.first_node = current_node;
//
//}
//// ��array_listתΪchain
//template<class T>
//void Chain<T>::from_list(ArrayList<T>& array_list) {
//	if (array_list.size() == 0) {
//		return;
//	}
//	for (int i = 0; i < array_list.size(); i++) {
//		this->insret(i, array_list[i]);
//	}
//}
//// ��chainתΪarray_list
//template<class T>
//void Chain<T>::to_list(ArrayList<T>& array_list) {
//	if (this->list_size == 0) {
//		return;
//	}
//
//	for (int i = 0; i < this->list_size; i++) {
//		array_list.insert(i, this->get(i));
//	}
//}


//
//// ����Ԫ��
//template<class T>
//void Chain<T>::left_shift(int num) {
//	check_index(num);
//	ChainNode<T>* current_node = first_node;
//	ChainNode<T>* delete_node;
//	for (int i = 0; i < num; i++) {
//		delete_node = current_node;
//		current_node = current_node->next;
//		delete delete_node;
//	}
//	first_node = current_node;
//	first_node->element = current_node->element;
//	list_size -= num;
//}


// �ߵ�Ԫ��
template<class T>
void Chain<T>::reverse() {
	ChainNode<T>* current_node = header_node->next;
	ChainNode<T>* current_node1 = current_node->next;
	ChainNode<T>* current_node2 = current_node1->next;
	current_node->next = NULL;
	for (int i = 0; i < list_size-2; i++) {
		current_node2 = current_node1->next;
		current_node1->next = current_node;
		current_node = current_node1;
		current_node1 = current_node2;
	}
	current_node1->next = current_node;
	header_node->next = current_node1;
}


//// �ϲ�����
//template<class T>
//void Chain<T>::meld(Chain<T>& the_list1, Chain<T>& the_list2) {
//	int max_length = max(the_list1.list_size, the_list2.list_size);
//	for (int i = 0; i < max_length; i++) {
//		T temp1 = the_list1.list_size > i ? the_list1[i] : NULL;
//		T temp2 = the_list2.list_size > i ? the_list2[i] : NULL;
//
//		if (temp1 != NULL) {
//			this->insret(this->list_size, temp1);
//		}
//		if (temp2 != NULL) {
//			this->insret(this->list_size, temp2);
//		}
//	}
//}
//
//
//// �ϲ����������б�
//template<class T>
//void Chain<T>::merge(Chain<T>& the_list1, Chain<T>& the_list2) {
//	ChainNode<T>* current_node = new ChainNode<T>(0);
//	first_node = current_node;
//
//	while (the_list1.first_node != NULL && the_list2.first_node != NULL) {
//		if (the_list1.first_node->element > the_list2.first_node->element) {
//			current_node->next = the_list2.first_node;
//			the_list2.first_node = the_list2.first_node->next;
//		}
//		else {
//			current_node->next = the_list1.first_node;
//			the_list1.first_node = the_list1.first_node->next;
//		}
//		current_node = current_node->next;
//	}
//
//	if (the_list1.first_node==NULL) {
//		current_node->next = the_list2.first_node;
//	}
//
//	if (the_list2.first_node==NULL) {
//		current_node->next = the_list1.first_node;
//	}
//	list_size = the_list1.list_size + the_list2.list_size;
//	first_node = first_node->next;
//}
//// ��������б�
//template<class T>
//void Chain<T>::spilt(Chain<T>& the_list1, Chain<T>& the_list2) {
//}
//// ѭ������Ԫ��
//template<class T>
//void Chain<T>::circular_shift(int index) {
//
//	ChainNode<T>* current_node = first_node;
//	ChainNode<T>* current_node1 = first_node;
//	for (int i = 0; i < index - 1; i++) {
//		current_node = current_node->next;
//	}
//	first_node = current_node->next;
//	current_node->next = NULL;
//	current_node = first_node;
//	for (int i = 0; i < list_size - index-1; i++) {
//		current_node = current_node->next;
//	}
//	current_node->next = current_node1;
//}
//
//
//#pragma endregion
//
//#pragma region ���������

template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x) {
	x.output(out);
	return out;
}



//// ����[]
//template<class T>
//T& Chain<T>::operator[](int index) const{
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; i < index; i++) {
//		current_node = current_node->next;
//	}
//	return current_node->element;
//}
//// ����==
//template<class T>
//bool Chain<T>::operator==(Chain<T>& the_list) const {
//	ChainNode<T>* current_node1 = first_node;
//	ChainNode<T>* current_node2 = the_list.first_node;
//	while (current_node1 != NULL) {
//		if (current_node1->element != current_node2->element) {
//			return false;
//		}
//		current_node1 = current_node1->next;
//		current_node2 = current_node2->next;
//		//std::cout << "b1 == b3: " << std::endl;
//	}
//	return true;
//}
//// ����!=
//template<class T>
//bool Chain<T>::operator!=(Chain<T>& the_list) const {
//	ChainNode<T>* current_node1 = first_node;
//	ChainNode<T>* current_node2 = the_list.first_node;
//	for (int i = 0; current_node1 != NULL; i++) {
//		if (current_node1->element == current_node2->element) {
//			return false;
//		}
//		current_node1 = current_node1->next;
//		current_node2 = current_node2->next;
//	}
//	return true;
//}
//// ����<
//template<class T>
//bool Chain<T>::operator<(Chain<T>& the_list) const {
//	ChainNode<T>* current_node1 = first_node;
//	ChainNode<T>* current_node2 = the_list.first_node;
//	for (int i = 0; current_node1 != NULL; i++) {
//		if (current_node1->element > current_node2->element) {
//			return false;
//		}
//		current_node1 = current_node1->next;
//		current_node2 = current_node2->next;
//	}
//	return true;
//}
//
//
//
//#pragma endregion