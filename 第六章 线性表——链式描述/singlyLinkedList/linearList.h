#pragma once

#include <iostream>


/// <summary>
/// 线性表抽象类
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class linearList {

public:
	virtual ~linearList() {};

	// 判断线性表是否为空
	virtual bool empty() const = 0;
	// 获取线性表长度
	virtual int size() const = 0;
	// 获取线性表指定索引的值
	virtual T& get(int the_index) const = 0;
	// 查找第一次出现the_element的索引
	virtual int indexOf(const T& the_element)const = 0;
	// 删除指定索引位置的元素
	virtual void erase(int the_index) = 0;
	// 在线性表指定位置插入指定元素
	virtual void insert(int the_index, const T& the_element) = 0;
	// 将线性表插入到输出流
	virtual void output(std::ostream& out) const = 0;
};