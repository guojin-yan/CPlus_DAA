#pragma once
#include <iostream>
#include <vector>
#include "arrayList.hpp"

template<class T>
class VectorList : public ArrayList<T> {

public:
	// ���캯�������ƹ������������
	VectorList(int initial_capacity = 10);
	VectorList(const VectorList<T>&);
	~VectorList() { delete element; }

};