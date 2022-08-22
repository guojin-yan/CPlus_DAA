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

private:
	// 检查索引是否有效
	void check_index(int the_index) const;
	ChainNode<T>* first_node;	// 首节点
	ChainNode<T>* last_node;	// 末尾节点
	int list_size;	// 链表长度
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
/// 析构函数
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
Chain<T>::~Chain() {
	// 逐个删除
	while (first_node == NULL) {
		ChainNode<T>* next_node = first_node->next;
		delete first_node;
		first_node = next_node;
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
	ChainNode<T>* current_node;
	if (the_index < list_size / 2) {
		// 移动到所需要的节点
		current_node = first_node;
		for (int i = 0; i < the_index; i++) {
			current_node = current_node->next;
		}
	}
	else {
		// 移动到所需要的节点
		current_node = last_node;
		for (int i = 0; i < list_size - the_index; i++) {
			current_node = current_node->previous;
		}
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
	ChainNode<T>* current_node = first_node;
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
		delete_Node = first_node;
		first_node = first_node->next;
		first_node->previous = NULL;
	}
	else {
		// 使用指针p,想要删除的节点前面的节点
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
/// 在指定位置插入元素
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
		// 在链表头插入
		first_node = new ChainNode<T>(the_element, NULL, first_node);
		if (list_size == 0) {
			last_node = first_node;
		}
	}
	else if (the_index == list_size - 1) {
		last_node = new ChainNode<T>(the_element, last_node, NULL);
	}
	else {
		// 使用指针p，想要插入的节点前面的节点
		ChainNode<T>* p = first_node;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		p->next = new ChainNode<T>(the_element, p, p->next);
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