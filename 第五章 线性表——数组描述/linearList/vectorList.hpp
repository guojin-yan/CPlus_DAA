#pragma once
#include <iostream>
#include <vector>
#include "arrayList.hpp"

template<class T>
class VectorList : public ArrayList<T> {

public:
	// 构造函数，复制构造和析构函数
	VectorList(int initial_capacity = 10);
	VectorList(const VectorList<T>&);
	~VectorList() { delete element; }

};