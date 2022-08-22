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
	// 构造函数、复制构造和析构函数
	Chain(int initial_capacity = 20);
	//Chain(const Chain<T>& the_list);
	~Chain();

	// 普通方法
	// 是否为空
	bool empty() { return list_size == 0; }
	// 获取链表长度
	int size() const { return list_size; }
	// 获取指定索引的元素
	T& get(int the_index) const;
	// 获取指定元素的索引
	int indexOf(const T& the_element) const;
	// 删除指定位置的元素
	void erase(int the_index);
	// 在指定位置插入元素
	void insret(int the_index, T& the_element);
	// 获取链表输出
	void output(ostream& out) const;

	//// 设置链表的长度
	//void set_size(int the_size);
	//// 替换指定位置元素
	//void set(int the_index, T& the_element);
	//// 删除指定索引范围内的元素
	//void remove_range(int form_index, int to_index);
	//// 返回指定值最后出现的索引
	//int last_indexOf(T& the_element) const;
	//// 交换两个链表元素
	//void swap(Chain<T> &the_list);
	//// 将array_list转为chain
	//void from_list(ArrayList<T>& array_list);
	//// 将chain转为array_list
	//void to_list(ArrayList<T>& array_list);
	//// 左移元素
	//void left_shift(int num);
	// 颠倒元素
	void reverse();
	//// 合并链表
	//void meld(Chain<T>& the_list1, Chain<T>& the_list2);
	//// 合并两个有序列表
	//void merge(Chain<T>& the_list1, Chain<T>& the_list2);
	//// 拆分两个有序列表
	//void spilt(Chain<T>& the_list1, Chain<T>& the_list2);
	//// 循环左移元素
	//void circular_shift(int index);





	//// 迭代器
	//using iterator = ChainIterator<T>;
	//iterator begin() { return iterator(first_node); }
	//iterator end() { return iterator(NULL); }


	//// 重载[]
	//T& operator[](int index) const;
	//// 重载==
	//bool operator==(Chain<T>& the_list) const;
	//// 重载!=
	//bool operator!=(Chain<T>& the_list) const;
	//// 重载<
	//bool operator<(Chain<T>& the_list) const;


private:
	// 检查索引是否有效
	void check_index(int the_index) const;
	ChainNode<T>* header_node; // 头节点
	int list_size;		// 线性表个数
};

/// <summary>
/// 构造
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
///// 拷贝构造
///// </summary>
///// <typeparam name="T"></typeparam>
///// <param name="Chain"></param>
//template<class T>
//Chain<T>::Chain(const Chain<T>& the_list) {
//	list_size = the_list.list_size;
//
//	if (list_size == 0) {// 当链表the_list为空
//		first_node = NULL;
//		return;
//	}
//	// 链表the_list非空
//	ChainNode<T>* source_node = the_list.first_node;
//	// 复制链表上的首元素
//	first_node = new ChainNode<T>(source_node->element);
//	source_node = source_node->next;
//	// 当前链表*this的最后一个节点
//	ChainNode<T>* target_node = first_node;
//
//	while (source_node == NULL) {// 复制剩余元素
//		target_node->next = new ChainNode<T>(source_node->element);
//		target_node = target_node->next;
//		source_node = source_node->next;
//	}
//
//	target_node->next = NULL; // 链表结束
//}


 //<summary>
 //析构函数
 //</summary>
 //<typeparam name="T"></typeparam>
template<class T>
Chain<T>::~Chain(){
	ChainNode<T>* delete_node = header_node->next;
	// 逐个删除
	while (delete_node != header_node) {
		ChainNode<T>* next_node = delete_node->next;
		delete delete_node;
		delete_node = next_node;
	}
}

/// <summary>
/// 检验索引是否有效
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
//#pragma region 公共方法




/// <summary>
/// 获取索引为 the_index 的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
inline T& Chain<T>::get(int the_index) const {
	// 检查索引
	check_index(the_index);
	// 移动到所需要的节点
	ChainNode<T>* current_node = header_node->next;
	for (int i = 0; i < the_index; i++) {
		current_node = current_node->next;
	}
	return current_node->element;
}

/// <summary>
/// 获取指定元素的索引，若元素不存在返回-1
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
/// <returns></returns>
template<class T>
int Chain<T>::indexOf(const T& the_element) const {
	// 搜索链表中元素
	ChainNode<T>* current_node = header_node->next;
	int index = 0;
	while (current_node != NULL && current_node->element != the_element) {
		current_node = current_node->next;
		index++;
	}

	// 确定是否找到所需元素
	if (current_node == NULL) {
		return -1;
	}
	else {
		return index;
	}
}
/// <summary>
/// 删除指定位置的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void Chain<T>::erase(int the_index) {
	// 判断索引是否越界
	check_index(the_index);
	
	// 寻找要删除的元素节点
	ChainNode<T>* delete_Node;
	if (the_index == 0) {
		// 删除链表的首节点
		delete_Node = header_node->next;
		header_node->next = delete_Node->next;
	}
	else {
		// 使用指针p,想要删除的节点前面的节点
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
/// 在指定位置插入元素
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
		// 在链表头插入
		ChainNode<T>* current_Node = new ChainNode<T>(the_element, header_node->next);
		header_node->next = current_Node;
	}
	else {
		// 使用指针p，想要插入的节点前面的节点
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
/// 获取链表输出
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




//// 设置链表的长度
//template<class T>
//void Chain<T>::set_size(int the_size) {
//	if (the_size >= list_size) {
//		// 如果设置长度大于原有长度
//		return;
//	}
//	else {
//		// 找到指定长度位置
//		ChainNode<T>* current_node = first_node;
//		for (int i = 0; i < the_size-1; i++) {
//			current_node = current_node->next;
//		}		
//		ChainNode<T>* delete_node = current_node->next;
//		// 将指定长度位置设为结束位置
//		current_node->next = NULL;
//		// 删除后面原有的长度
//		while(current_node == NULL) {
//			current_node = delete_node->next;
//			delete delete_node;
//		}
//		list_size = the_size;
//	}
//}
//// 替换指定位置元素
//template<class T>
//void Chain<T>::set(int the_index, T& the_element) {
//	check_index(the_index);
//	// 找到指定位置
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; i < the_index; i++) {
//		current_node = current_node->next;
//	}
//	current_node->element = the_element;
//}
//// 删除指定索引范围内的元素
//template<class T>
//void Chain<T>::remove_range(int form_index, int to_index) {
//	check_index(to_index);
//	// 找到指定位置
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; i < form_index; i++) {
//		current_node = current_node->next;
//	}
//	// 记录开始位置node
//	ChainNode<T>* form_node = current_node;
//	current_node = current_node->next;
//	ChainNode<T>* delete_node;
//	// 删除范围内的元素
//	for (int i = 0; i < to_index-form_index; i++) {
//		delete_node = current_node;
//		current_node = current_node->next;
//		delete delete_node;
//	}
//	// 将删除范围的链表连接起来
//	form_node->next = current_node;
//	list_size -= (to_index - form_index);
//}
//// 返回指定值最后出现的索引
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
//// 交换两个链表元素
//template<class T>
//void Chain<T>::swap(Chain<T> &the_list) {
//	ChainNode<T>* current_node = first_node;
//	first_node = the_list.first_node;
//	the_list.first_node = current_node;
//
//}
//// 将array_list转为chain
//template<class T>
//void Chain<T>::from_list(ArrayList<T>& array_list) {
//	if (array_list.size() == 0) {
//		return;
//	}
//	for (int i = 0; i < array_list.size(); i++) {
//		this->insret(i, array_list[i]);
//	}
//}
//// 将chain转为array_list
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
//// 左移元素
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


// 颠倒元素
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


//// 合并链表
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
//// 合并两个有序列表
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
//// 拆分两个列表
//template<class T>
//void Chain<T>::spilt(Chain<T>& the_list1, Chain<T>& the_list2) {
//}
//// 循环左移元素
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
//#pragma region 运算符重载

template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x) {
	x.output(out);
	return out;
}



//// 重载[]
//template<class T>
//T& Chain<T>::operator[](int index) const{
//	ChainNode<T>* current_node = first_node;
//	for (int i = 0; i < index; i++) {
//		current_node = current_node->next;
//	}
//	return current_node->element;
//}
//// 重载==
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
//// 重载!=
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
//// 重载<
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