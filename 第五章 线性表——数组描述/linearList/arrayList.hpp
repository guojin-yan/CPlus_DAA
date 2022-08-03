#pragma once


#include <iostream>
#include <sstream>
#include <string>  
#include "arrayList_iterator.hpp"
#include"linearList.h"
#include "illegalParameterValue.h"

using namespace std;

template<class T>
class ArrayList {

public:

	using iterator = ArrayList_iterator<T>;

	// 构造函数、复制构造函数以及析构函数
	// 指定列表长度构造
	ArrayList(int initial_capacity = 10);
	// 复制原有列表构造
	ArrayList(const ArrayList<T>& the_list);
	// 指定当前列表长度以及列表长度递增大小
	ArrayList(int initial_capacity, int initial_increase);
	~ArrayList() { delete[] element; }

	// 继承原有的虚方法
	// 判断线性表是否为空
	bool empty() const { return list_size == 0; }
	// 获取线性表长度
	int size() const { return list_size; };
	// 获取线性表指定索引的值
	T& get(int the_index) const;
	// 查找第一次出现the_element的索引
	int indexOf(const T& the_element) const;
	// 删除指定索引位置的元素
	void erase(int the_index);
	// 在线性表指定位置插入指定元素
	void insert(int the_index, const T& the_element);
	// 将线性表插入到输出流
	void output(ostream& out) const;
	// 将列表容量压缩到与元素个数相同
	void trim_to_size();
	// 重新制定列表长度
	void set_size(int initiial_length);
	// 在列表左侧插入the_element
	void push_back(T the_element);
	// 在列表右侧删除成员
	void pop_back();
	// 交换列表元素
	void swap(ArrayList<T>& the_list);
	// 将列表容量设为两个之间的较大的
	void reserve(ArrayList<T>& the_list);
	// 替换指定位置的元素
	void set(int the_index, T the_element);
	// 清空列表
	void clear();
	// 移除指定范围内的所有元素
	void remove_range(int begin_index, int end_index, int length = 0);
	// 查找指定元素最后出现的索引
	int last_inexOf(T the_element);
	// 颠倒元素顺序
	void reverse();
	
	// 开始迭代器
	iterator begin() { return iterator(element); }
	// 结束迭代器
	iterator end() { return iterator(element + list_size); }

	// 其他方法
	// 获取线性表长度
	int capacity() const { return array_length; };

	// 重载[]
	T& operator[](int index) const;
	// 重载==
	bool operator==(const ArrayList<T>& array);
	// 重载!=
	bool operator!=(const ArrayList<T>& array);
	// 重载>
	bool operator<(const ArrayList<T>& array);

protected:
	// 判断索引值是否有效
	void check_index(int the_index) const;
	// 改变数组长度
	void chenge_length_1D(T*& array, int old_length, int new_length);

	T* element;			// 储存线性表的一维数组
	int array_length;	// 一维数组容量
	int list_size;		// 线性表元素个数
	int list_increase = 0;	// 列表递增大小
};



#pragma region 公有方法
/// <summary>
/// 构造函数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity">初始化长度</param>
template<class T>
ArrayList<T>::ArrayList(int initial_capacity) {
	if (initial_capacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initial_capacity << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	array_length = initial_capacity;
	element = new T[array_length];
	list_size = 0;
}

//<summary>
//复制构造函数
//</summary>
//<typeparam name="T"></typeparam>
//<param name="the_list">复制数组</param>
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& the_list) {

	array_length = the_list.array_length;
	element = new T[array_length];
	list_size = the_list.list_size;
	copy(the_list.element, the_list.element + list_size, element);

}

/// <summary>
/// 同时指定列表长度以及增加的长度
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity"></param>
/// <param name="initial_increase"></param>
template<class T>
ArrayList<T>::ArrayList(int initial_capacity, int initial_increase){
	if (initial_capacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initial_capacity << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	array_length = initial_capacity;
	element = new T[array_length];
	list_size = 0;
	list_increase = initial_increase;
}


/// <summary>
/// 获取线性表指定索引的值
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index">索引</param>
/// <returns>索引对应的值</returns>
template<class T>
T& ArrayList<T>::get(int the_index) const { 
	// 检查索引值是否在范围内
	check_index(the_index);
	return element[the_index]; 
}


/// <summary>
/// 查找第一次出现the_element的索引
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
/// <returns>
/// 1. 如存在返回索引；2.不存在返回-1；
/// </returns>
template<class T>
int ArrayList<T>::indexOf(const T& the_element) const {
	// 查找元素the_element
	int the_index = (int)(find(element, element + list_size, the_element) - element);
	// 判断the_element是否被找到
	if (the_index == list_size) {
		// 没有找到
		return -1;
	}
	else { 
		return the_index; 
	}
}
/// <summary>
/// 删除指定索引位置的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void ArrayList<T>::erase(int the_index) {
	// 判断索引值是否有效
	check_index(the_index);
	
	// 判断数组是否太大
	if (list_size < array_length / 4) {
		// 将数组减少一半
		chenge_length_1D(element, array_length, array_length / 2);
		array_length /= 2;
	}
	//通过移动的方式覆盖要删除的元素
	copy(element + the_index + 1, element + list_size, element + the_index);
	// 释放掉最后一个元素
	element[--list_size].~T();
}
/// <summary>
/// 在线性表指定位置插入指定元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void ArrayList<T>::insert(int the_index, const T& the_element) {
	// 判断索引是否有效
	check_index(the_index);
	
	// 判断数组是否已满
	if (list_size == array_length) {
		// 数组空间已满
		if (list_increase == 0) {
			// 未指定增加长度，数组长度倍增
			chenge_length_1D(element, array_length, 2 * array_length);
			array_length *= 2;
		}
		else {
			// 指定增加长度，数组长度递增
			chenge_length_1D(element, array_length, array_length + list_increase);
			array_length += list_increase;
		}
	}

	// 把元素后移一个位置
	copy_backward(element + the_index, element + list_size, element + list_size + 1);
	element[the_index] = the_element;
	list_size++;
}

/// <summary>
/// 将线性表插入到输出流
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
template<class T>
void ArrayList<T>::output(ostream& out) const {
	copy(element, element + list_size, ostream_iterator<T>(cout, " "));
}

/// <summary>
/// 压缩列表，将列表空位删除
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::trim_to_size() {
	int max_list = max(list_size, 1);
	chenge_length_1D(element, array_length, max_list);
	array_length = max_list;

}

/// <summary>
/// 重新指定列表长度
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="intiial_length"></param>
template<class T>
void ArrayList<T>::set_size(int initiial_length) {
	chenge_length_1D(element, array_length, initiial_length);
	if ((array_length < initiial_length) || 
		(array_length > initiial_length && list_size < initiial_length) ) {
		array_length = initiial_length;
	}
	else {
		array_length = initiial_length;
		list_size = initiial_length;
	}
}
/// <summary>
/// 将the_element插入到列表后面
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
template<class T>
void ArrayList<T>::push_back(T the_element) {
	// 判断数组是否已满
	if (list_size == array_length) {
		// 数组空间已满
		if (list_increase == 0) {
			// 未指定增加长度，数组长度倍增
			chenge_length_1D(element, array_length, 2 * array_length);
			array_length *= 2;
		}
		else {
			// 指定增加长度，数组长度递增
			chenge_length_1D(element, array_length, array_length + list_increase);
			array_length += list_increase;
		}
	}
	element[list_size] = the_element;
	list_size++;
}
/// <summary>
/// 删除列表右侧元素
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::pop_back() {
	if (list_size < 1) {
		ostringstream s;
		s << "ArrayList is Empty !";
		throw illegalParameterValue(s.str());
	}
	// 释放掉最后一个元素
	element[--list_size].~T();
}


/// <summary>
/// 交换列表元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_list"></param>
template<class T>
void ArrayList<T>::swap(ArrayList<T>& the_list) {
	T* element = this->element;			// 储存线性表的一维数组
	int array_length = this->array_length;	// 一维数组容量
	int list_size = this->list_size;		// 线性表元素个数
	int list_increase = this->list_increase;	// 列表递增大小

	this->element = the_list.element;
	this->array_length = the_list.array_length; 
	this->list_size = the_list.list_size;
	this->list_increase = the_list.list_increase;

	the_list.element = element;
	the_list.array_length = array_length;
	the_list.list_size = list_size;
	the_list.list_increase = list_increase;
}

/// <summary>
/// 将列表容量设为两个之间的较大的
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_list"></param>
template<class T>
void ArrayList<T>::reserve(ArrayList<T>& the_list) {
	int max_length = max(this->array_length, the_list.array_length);
	if (max_length == this->array_length) {
		chenge_length_1D(the_list.element, the_list.array_length, max_length);
		the_list.array_length = max_length;
	}
	else {
		chenge_length_1D(this->element, this->array_length, max_length);
		this->array_length = max_length;
	}
}


/// <summary>
/// 替换指定位置的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void ArrayList<T>::set(int the_index, T the_element) {
	// 检查索引是否超限
	check_index(the_index);

	this->element[the_index] = the_element;
}
/// <summary>
/// 清空列表元素
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::clear() {
	delete[] this->element;
	this->element = new T(array_length);
	this->list_size = 0;
}
/// <summary>
/// 清空指定范围内的元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="begin_index">起始位置</param>
/// <param name="end_index">结束位置</param>
/// <param name="length">范围长度</param>
template<class T>
void ArrayList<T>::remove_range(int begin_index, int end_index, int length) {
	if (length != 0) {
		end_index = begin_index + length;
	}
	else {
		length = end_index - begin_index;
	}
	// 检查索引是否有效
	check_index(end_index);
	copy(element + end_index, element + list_size, element + begin_index);
	for (int i = 0; i < length; i++) {
		element[list_size - 1 - i].~T();
	}
	list_size -= length;
}

/// <summary>
/// 查找指定元素最后出现的索引
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
/// <returns></returns>
template<class T>
int ArrayList<T>::last_inexOf(T the_element) {
	ArrayList<T>::iterator end = this->end();
	for (; end != this->begin(); end--) {
		if (*end == the_element) {
			ArrayList<T>::iterator e = end - this->begin();
			return (int)(e.get_position());
		}
	}
	return -1;
}


/// <summary>
/// 颠倒元素顺序
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::reverse() {
	T temp;
	if (list_size % 2 == 0) {
		for (int i = 0; i < list_size / 2; i++) {
			temp = this->element[i];
			this->element[i] = this->element[list_size - i - 1];
			this->element[list_size - i - 1] = temp;
		}
	}
	else {
		for (int i = 0; i < list_size / 2 - 1; i++) {
			temp = this->element[i];
			this->element[i] = this->element[list_size - i - 1];
			this->element[list_size - i - 1] = temp;
		}
	}
}




#pragma endregion


#pragma region 重载运算符


/// <summary>
/// 重载<<
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
/// <param name="x"></param>
/// <returns></returns>
template<class T>
ostream& operator<<(ostream& out, const ArrayList<T>& x) {
	x.output(out); 
	return out;
}

/// <summary>
/// 重载[]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <returns></returns>
template<class T>
T& ArrayList<T>::operator[](int the_index) const {
	// 判断索引是否有效
	check_index(the_index);
	return element[the_index];
}


/// <summary>
/// 重载==
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="array"></param>
/// <returns></returns>
template<class T>
bool ArrayList<T>::operator==(const ArrayList<T>& array) {
	if (list_size != array.list_size) {
		return false;
	}
	else {
		for (int i = 0; i < array.list_size; i++) {
			if (element[i] != array[i]) {
				return false;
			}
		}
	}
	return true;
}

/// <summary>
/// 重载！=
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="array"></param>
/// <returns></returns>
template<class T>
bool ArrayList<T>::operator!=(const ArrayList<T>& array) {
	if (list_size != array.list_size) {
		return true;
	}
	else {
		for (int i = 0; i < array.list_size; i++) {
			if (element[i] != array[i]) {
				return true;
			}
		}
	}
	return false;
}

/// <summary>
/// 重载<
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="array"></param>
/// <returns></returns>
template<class T>
bool ArrayList<T>::operator<(const ArrayList<T>& array) {
	if (list_size != array.list_size) {
		return false;
	}
	else {
		for (int i = 0; i < array.list_size; i++) {
			if (this->element[i] >= array.element[i]) {
				return false;
			}
		}
	}
	return true;
}

#pragma endregion

/// <summary>
/// 检查索引是否在范围内，不在抛出异常
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void  ArrayList<T>::check_index(int the_index) const {
	if (the_index < 0 && the_index >= list_size) {
		ostringstream s;
		s << "index = " << the_index << "size =  "<< list_size;
		throw illegalParameterValue(s.str());
	}
}

template<class T>
void ArrayList<T>::chenge_length_1D(T*& array, int old_length, int new_length) {
	// 判断长度是否合理
	if (new_length < 0){
		ostringstream s;
		s << "New Length = " << new_length << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	// 转移到新的数组中
	T* temp = new T[new_length];
	int length = min(new_length, list_size);
	copy(array, array + length, temp);
	delete[] array;
	array = temp;
}



