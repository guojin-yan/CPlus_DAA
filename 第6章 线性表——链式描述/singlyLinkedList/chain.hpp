#pragma once
#include <iostream>

#include "chain_node.hpp"
#include "chain_iterator.hpp"
#include "illegalParameterValue.h"


using namespace std;

template<class T>
class Chain {
public:
	// 构造函数、复制构造和析构函数
	Chain(int initial_capacity = 20);
	Chain(const Chain<T>& the_list);
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

	// 设置链表的长度
	void set_size(int the_size);
	// 替换指定位置元素
	void set(int the_index, T& the_element);
	// 删除指定索引范围内的元素
	void remove_range(int form_index, int to_index);
	// 返回指定值最后出现的索引
	int last_indexOf(T& the_element) const;
	// 交换两个链表元素
	void swap(Chain<T> the_list);




	// 迭代器
	using iterator = ChainIterator<T>;
	iterator begin() { return iterator(first_node); }
	iterator end() { return iterator(NULL); }


	// 重载[]
	T& operator[](int index);
	// 重载==
	bool operator==(Chain<T> the_list);
	// 重载!=
	bool operator!=(Chain<T> the_list);
	// 重载<
	bool operator<(Chain<T> the_list);


private:
	// 检查索引是否有效
	void check_index(int the_index) const;
	ChainNode<T>* first_node; // 指向链表的第一个指针
	int list_size;		// 线性表个数
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
/// 拷贝构造
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="Chain"></param>
template<class T>
Chain<T>::Chain(const Chain<T>& the_list) {
	list_size = the_list.list_size;

	if (list_size == 0) {// 当链表the_list为空
		first_node = NULL;
		return;
	}
	// 链表the_list非空
	ChainNode<T>* source_node = the_list.first_node;
	// 复制链表上的首元素
	first_node = new ChainNode<T>(source_node->element);
	source_node = source_node->next;
	// 当前链表*this的最后一个节点
	ChainNode<T>* target_node = first_node;

	while (source_node == NULL) {// 复制剩余元素
		target_node->next = new ChainNode<T>(source_node->element);
		target_node = target_node->next;
		source_node = source_node->next;
	}

	target_node->next = NULL; // 链表结束
}
/// <summary>
/// 析构函数
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
Chain<T>::~Chain(){
	// 逐个删除
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
/// 获取索引为 the_index 的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
inline T& Chain<T>::get(int the_index) const {
	// 检查索引
	check_index(the_index);
	// 移动到所需要的节点
	ChainNode<T>* current_node = first_node;
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
	ChainNode<T> delete_Node;
	if (the_index == 0) {
		// 删除链表的首节点
		delete_Node = first_node;
		first_node = first_node->next;
	}
	else {
		// 使用指针p,想要删除的节点前面的节点
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

	ChainNode<T> delete_Node;
	if (the_index == 0) {
		// 在链表头插入
		first_node = new ChainNode<T>(the_element, first_node);
	}
	else {
		// 使用指针p，想要插入的节点前面的节点
		ChainNode<T> p = first_node;
		for (int i = 0; i < the_index - 1; i++) {
			p = p->next;
		}
		p->next = new ChainNode<T>(the_element, p->next);
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

