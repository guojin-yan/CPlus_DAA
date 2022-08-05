#pragma once
#include <iostream>
#include <vector>
#include "arrayList.hpp"

using namespace std;

template<class T>
class VectorList : public ArrayList<T> {

public:
	// 构造函数，复制构造和析构函数
	VectorList(int initial_capacity = 10);
	VectorList(const VectorList<T>&);
	~VectorList() { delete element; }

	// 判断是否为空列表
	bool empty() { return element->empty(); }
	// 获取列表长度
	int size() const { return (int)element->size(); }
	// 获取指定位置的元素
	T& get(int the_index) const;
	// 获取指定元素的索引
	int indexOf(const T& the_element) const;
	// 删除指定位置
	void erase(int the_index);
	// 在指定位置插入元素
	void insert(int the_index, const T& the_element);
	// 打印输出列表
	void output(ostream& out) const;

	// 获取列表空间
	int capacity() const { return (int)element->capacity(); }
	//列表元素间隔删除
	void half();
	// 合并两个列表，交替填充
	void meld(VectorList<T>& the_list1, VectorList<T>& the_list2);
	// 合并两个有序列表，从左到右非递减有序
	void merge(VectorList<T>& the_list1, VectorList<T>& the_list2);
	// 将线性表按照奇偶位置拆解
	void split(VectorList<T>& the_list1, VectorList<T>& the_list2);


	T& operator[](int the_index) const;

	// 迭代器
	typedef typename vector<T>::iterator iterator;
	iterator begin() { return element->begin(); }
	iterator end() { return element->end(); }



protected:
	void check_index(int the_index) const;
	vector<T>* element;
};

/// <summary>
/// 长度构造
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity"></param>
template<class T>
VectorList<T>::VectorList(int initial_capacity) {
	if (initial_capacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << initial_capacity << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	element = new vector<T>;
	element->reserve(initial_capacity);
}
/// <summary>
/// 拷贝构造
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_list"></param>
template<class T>
VectorList<T>::VectorList(const VectorList<T>& the_list){
	element = new vector<T>(*the_list.element);
}




/// <summary>
/// 删除指定位置
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void VectorList<T>::erase(int the_index) {
	check_index(the_index);
	element->erase(begin() + the_index);
}


/// <summary>
/// 在线性表指定位置插入指定元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void VectorList<T>::insert(int the_index, const T& the_element) {
	// 判断索引是否有效
	check_index(the_index);

	element->insert(element->begin() + the_index, the_element);
}


/// <summary>
/// 将线性表插入到输出流
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
template<class T>
void VectorList<T>::output(ostream& out) const {
	copy(element->begin(), element->end(), ostream_iterator<T>(cout, " "));
}

/// <summary>
/// 检查索引是否在范围内，不在抛出异常
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void  VectorList<T>::check_index(int the_index) const {
	if (the_index < 0 && the_index >= this->size()) {
		ostringstream s;
		s << "index = " << the_index << "size =  " << this->size();
		throw illegalParameterValue(s.str());
	}
}



/// <summary>
/// 列表元素间隔删除
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void  VectorList<T>::half() {
	int num = size() / 2;
	for (int i = 0; i < size() - num - 1; i++) {
		copy(element->begin() + 2 * (i + 1), element->begin() + 2 * (i + 1) + 1, element->begin() + 1 + i);
	}
	for (int i = 0; i < num; i++) {
		element->pop_back();
	}

}

// 合并两个列表，交替填充
template<class T>
void  VectorList<T>::meld(VectorList<T>& the_list1, VectorList<T>& the_list2) {
	int min_length = min(the_list1.size(), the_list2.size());
	if (the_list1.size() > the_list2.size()) {
		for (int i = 0; i < min_length; i++) {
			element->push_back(the_list1[i]);
			element->push_back(the_list2[i]);
		}
		for (int i = 0; i < the_list1.size() - the_list2.size(); i++) {
			element->push_back(the_list1[min_length + i]);
		}

	}
	else {
		for (int i = 0; i < min_length; i++) {
			element->push_back(the_list1[i]);
			element->push_back(the_list2[i]);
		}
		for (int i = 0; i < the_list2.size() - the_list1.size(); i++) {
			element->push_back(the_list2[min_length + i]);
		}
	}
}
// 合并两个有序列表，从左到右非递减有序
template<class T>
void  VectorList<T>::merge(VectorList<T>& the_list1, VectorList<T>& the_list2) {

	T temp1;
	T temp2;
	int list1 = 1;
	int list2 = 1;
	temp1 = the_list1[0];
	temp2 = the_list2[0];
	for (int i = 0; i < the_list1.size() + the_list2.size(); i++) {
		std::cout << "i: " << i << std::endl;
		if (temp1 >= temp2 && list1 <= the_list1.size()) {
			element->push_back(temp1);
			if (list1 >= the_list1.size()) {
				temp1 = 0;
				continue;
				
			}
			temp1 = the_list1[list1];
			std::cout << "list1: " << list1 << std::endl;
			list1++;
		}
		else if (temp1 < temp2 && list2 <= the_list2.size()) {
			element->push_back(temp2);
			if (list2 >= the_list2.size()) {
				temp2 = 0;
				continue;

			}
			temp2 = the_list2[list2];
			std::cout << "list2: " << list2 << std::endl;
			list2++;
		}
	}
}


// 将线性表按照奇偶位置拆解
template<class T>
void  VectorList<T>::split(VectorList<T>& the_list1, VectorList<T>& the_list2) {
	for (int i = 0; i < size(); i++) {
		if (i % 2 == 0) {
			the_list1.element->push_back(element->at(i));
		}
		else {
			the_list2.element->push_back(element->at(i));
		}
	}
}










/// <summary>
/// 重载<<
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
/// <param name="x"></param>
/// <returns></returns>
template<class T>
ostream& operator<<(ostream& out, const VectorList<T>& x) {
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
T& VectorList<T>::operator[](int the_index) const {
	// 判断索引是否有效
	check_index(the_index);
	return element->at(the_index);
}
