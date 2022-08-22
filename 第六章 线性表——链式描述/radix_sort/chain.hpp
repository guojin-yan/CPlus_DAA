#pragma once
#include <iostream>
#include <sstream>

#include "chain_node.h"



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
	// 在指定位置插入元素
	void insret(int the_index, T& the_element);
	// 获取链表输出
	void output(ostream& out) const;

	// 箱子排序成员函数实现
	void bin_sort(int range);

	// 基数排序
	void radix_sort(int r, int range);



private:

	ChainNode<T>* first_node; // 指向链表的第一个指针
	int list_size;		// 线性表个数
};

/// <summary>
/// 构造
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity"></param>
template<class T>
inline Chain<T>::Chain(int initial_capacity) {
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
Chain<T>::~Chain() {
	// 逐个删除
	while (first_node == NULL) {
		ChainNode<T>* next_node = first_node->next;
		delete first_node;
		first_node = next_node;
	}
}

/// <summary>
/// 在指定位置插入元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void Chain<T>::insret(int the_index, T& the_element) {

	if (the_index == 0) {
		// 在链表头插入
		first_node = new ChainNode<T>(the_element, first_node);
	}
	else {
		// 使用指针p，想要插入的节点前面的节点
		ChainNode<T>* p = first_node;
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

// 箱子排序成员函数实现
template<class T>
void Chain<T>::bin_sort(int range) {
	// 初始化顶箱和底箱
	ChainNode<T>** top, ** bottom;
	bottom = new ChainNode<T>*[range + 1];
	top = new ChainNode<T>*[range + 1];
	for (int b = 0; b <= range; b++) {
		bottom[b] = NULL;
	}

	// 分配顶层与底层箱子
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
	
	//把箱子分配到有序列表中
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

// 基数排序
template<class T>
void Chain<T>::radix_sort(int r, int range) {
	for (int i = r; i <= range + 1; i = i * r) {
		// 初始化顶箱和底箱
		ChainNode<T>** top, ** bottom;
		bottom = new ChainNode<T>*[r];
		top = new ChainNode<T>*[r];
		for (int b = 0; b < r; b++) {
			bottom[b] = NULL;
		}

		// 分配顶层与底层箱子
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

		//把箱子分配到有序列表中
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