#pragma once
#include <iostream>
#include <vector>
#include "arrayList.hpp"

using namespace std;

template<class T>
class VectorList : public ArrayList<T> {

public:
	// ���캯�������ƹ������������
	VectorList(int initial_capacity = 10);
	VectorList(const VectorList<T>&);
	~VectorList() { delete element; }

	// �ж��Ƿ�Ϊ���б�
	bool empty() { return element->empty(); }
	// ��ȡ�б���
	int size() const { return (int)element->size(); }
	// ��ȡָ��λ�õ�Ԫ��
	T& get(int the_index) const;
	// ��ȡָ��Ԫ�ص�����
	int indexOf(const T& the_element) const;
	// ɾ��ָ��λ��
	void erase(int the_index);
	// ��ָ��λ�ò���Ԫ��
	void insert(int the_index, const T& the_element);
	// ��ӡ����б�
	void output(ostream& out) const;

	// ��ȡ�б�ռ�
	int capacity() const { return (int)element->capacity(); }
	//�б�Ԫ�ؼ��ɾ��
	void half();
	// �ϲ������б��������
	void meld(VectorList<T>& the_list1, VectorList<T>& the_list2);
	// �ϲ����������б������ҷǵݼ�����
	void merge(VectorList<T>& the_list1, VectorList<T>& the_list2);
	// �����Ա�����żλ�ò��
	void split(VectorList<T>& the_list1, VectorList<T>& the_list2);


	T& operator[](int the_index) const;

	// ������
	typedef typename vector<T>::iterator iterator;
	iterator begin() { return element->begin(); }
	iterator end() { return element->end(); }



protected:
	void check_index(int the_index) const;
	vector<T>* element;
};

/// <summary>
/// ���ȹ���
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
/// ��������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_list"></param>
template<class T>
VectorList<T>::VectorList(const VectorList<T>& the_list){
	element = new vector<T>(*the_list.element);
}




/// <summary>
/// ɾ��ָ��λ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void VectorList<T>::erase(int the_index) {
	check_index(the_index);
	element->erase(begin() + the_index);
}


/// <summary>
/// �����Ա�ָ��λ�ò���ָ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void VectorList<T>::insert(int the_index, const T& the_element) {
	// �ж������Ƿ���Ч
	check_index(the_index);

	element->insert(element->begin() + the_index, the_element);
}


/// <summary>
/// �����Ա���뵽�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
template<class T>
void VectorList<T>::output(ostream& out) const {
	copy(element->begin(), element->end(), ostream_iterator<T>(cout, " "));
}

/// <summary>
/// ��������Ƿ��ڷ�Χ�ڣ������׳��쳣
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
/// �б�Ԫ�ؼ��ɾ��
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

// �ϲ������б��������
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
// �ϲ����������б������ҷǵݼ�����
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


// �����Ա�����żλ�ò��
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
/// ����<<
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
/// ����[]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <returns></returns>
template<class T>
T& VectorList<T>::operator[](int the_index) const {
	// �ж������Ƿ���Ч
	check_index(the_index);
	return element->at(the_index);
}
