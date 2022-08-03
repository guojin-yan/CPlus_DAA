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

	// ���캯�������ƹ��캯���Լ���������
	// ָ���б��ȹ���
	ArrayList(int initial_capacity = 10);
	// ����ԭ���б���
	ArrayList(const ArrayList<T>& the_list);
	// ָ����ǰ�б����Լ��б��ȵ�����С
	ArrayList(int initial_capacity, int initial_increase);
	~ArrayList() { delete[] element; }

	// �̳�ԭ�е��鷽��
	// �ж����Ա��Ƿ�Ϊ��
	bool empty() const { return list_size == 0; }
	// ��ȡ���Ա���
	int size() const { return list_size; };
	// ��ȡ���Ա�ָ��������ֵ
	T& get(int the_index) const;
	// ���ҵ�һ�γ���the_element������
	int indexOf(const T& the_element) const;
	// ɾ��ָ������λ�õ�Ԫ��
	void erase(int the_index);
	// �����Ա�ָ��λ�ò���ָ��Ԫ��
	void insert(int the_index, const T& the_element);
	// �����Ա���뵽�����
	void output(ostream& out) const;
	// ���б�����ѹ������Ԫ�ظ�����ͬ
	void trim_to_size();
	// �����ƶ��б���
	void set_size(int initiial_length);
	// ���б�������the_element
	void push_back(T the_element);
	// ���б��Ҳ�ɾ����Ա
	void pop_back();
	// �����б�Ԫ��
	void swap(ArrayList<T>& the_list);
	// ���б�������Ϊ����֮��Ľϴ��
	void reserve(ArrayList<T>& the_list);
	// �滻ָ��λ�õ�Ԫ��
	void set(int the_index, T the_element);
	// ����б�
	void clear();
	// �Ƴ�ָ����Χ�ڵ�����Ԫ��
	void remove_range(int begin_index, int end_index, int length = 0);
	// ����ָ��Ԫ�������ֵ�����
	int last_inexOf(T the_element);
	// �ߵ�Ԫ��˳��
	void reverse();
	
	// ��ʼ������
	iterator begin() { return iterator(element); }
	// ����������
	iterator end() { return iterator(element + list_size); }

	// ��������
	// ��ȡ���Ա���
	int capacity() const { return array_length; };

	// ����[]
	T& operator[](int index) const;
	// ����==
	bool operator==(const ArrayList<T>& array);
	// ����!=
	bool operator!=(const ArrayList<T>& array);
	// ����>
	bool operator<(const ArrayList<T>& array);

protected:
	// �ж�����ֵ�Ƿ���Ч
	void check_index(int the_index) const;
	// �ı����鳤��
	void chenge_length_1D(T*& array, int old_length, int new_length);

	T* element;			// �������Ա��һά����
	int array_length;	// һά��������
	int list_size;		// ���Ա�Ԫ�ظ���
	int list_increase = 0;	// �б������С
};



#pragma region ���з���
/// <summary>
/// ���캯��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="initial_capacity">��ʼ������</param>
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
//���ƹ��캯��
//</summary>
//<typeparam name="T"></typeparam>
//<param name="the_list">��������</param>
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& the_list) {

	array_length = the_list.array_length;
	element = new T[array_length];
	list_size = the_list.list_size;
	copy(the_list.element, the_list.element + list_size, element);

}

/// <summary>
/// ͬʱָ���б����Լ����ӵĳ���
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
/// ��ȡ���Ա�ָ��������ֵ
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index">����</param>
/// <returns>������Ӧ��ֵ</returns>
template<class T>
T& ArrayList<T>::get(int the_index) const { 
	// �������ֵ�Ƿ��ڷ�Χ��
	check_index(the_index);
	return element[the_index]; 
}


/// <summary>
/// ���ҵ�һ�γ���the_element������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
/// <returns>
/// 1. ����ڷ���������2.�����ڷ���-1��
/// </returns>
template<class T>
int ArrayList<T>::indexOf(const T& the_element) const {
	// ����Ԫ��the_element
	int the_index = (int)(find(element, element + list_size, the_element) - element);
	// �ж�the_element�Ƿ��ҵ�
	if (the_index == list_size) {
		// û���ҵ�
		return -1;
	}
	else { 
		return the_index; 
	}
}
/// <summary>
/// ɾ��ָ������λ�õ�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
template<class T>
void ArrayList<T>::erase(int the_index) {
	// �ж�����ֵ�Ƿ���Ч
	check_index(the_index);
	
	// �ж������Ƿ�̫��
	if (list_size < array_length / 4) {
		// ���������һ��
		chenge_length_1D(element, array_length, array_length / 2);
		array_length /= 2;
	}
	//ͨ���ƶ��ķ�ʽ����Ҫɾ����Ԫ��
	copy(element + the_index + 1, element + list_size, element + the_index);
	// �ͷŵ����һ��Ԫ��
	element[--list_size].~T();
}
/// <summary>
/// �����Ա�ָ��λ�ò���ָ��Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void ArrayList<T>::insert(int the_index, const T& the_element) {
	// �ж������Ƿ���Ч
	check_index(the_index);
	
	// �ж������Ƿ�����
	if (list_size == array_length) {
		// ����ռ�����
		if (list_increase == 0) {
			// δָ�����ӳ��ȣ����鳤�ȱ���
			chenge_length_1D(element, array_length, 2 * array_length);
			array_length *= 2;
		}
		else {
			// ָ�����ӳ��ȣ����鳤�ȵ���
			chenge_length_1D(element, array_length, array_length + list_increase);
			array_length += list_increase;
		}
	}

	// ��Ԫ�غ���һ��λ��
	copy_backward(element + the_index, element + list_size, element + list_size + 1);
	element[the_index] = the_element;
	list_size++;
}

/// <summary>
/// �����Ա���뵽�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
template<class T>
void ArrayList<T>::output(ostream& out) const {
	copy(element, element + list_size, ostream_iterator<T>(cout, " "));
}

/// <summary>
/// ѹ���б����б��λɾ��
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::trim_to_size() {
	int max_list = max(list_size, 1);
	chenge_length_1D(element, array_length, max_list);
	array_length = max_list;

}

/// <summary>
/// ����ָ���б���
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
/// ��the_element���뵽�б����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_element"></param>
template<class T>
void ArrayList<T>::push_back(T the_element) {
	// �ж������Ƿ�����
	if (list_size == array_length) {
		// ����ռ�����
		if (list_increase == 0) {
			// δָ�����ӳ��ȣ����鳤�ȱ���
			chenge_length_1D(element, array_length, 2 * array_length);
			array_length *= 2;
		}
		else {
			// ָ�����ӳ��ȣ����鳤�ȵ���
			chenge_length_1D(element, array_length, array_length + list_increase);
			array_length += list_increase;
		}
	}
	element[list_size] = the_element;
	list_size++;
}
/// <summary>
/// ɾ���б��Ҳ�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::pop_back() {
	if (list_size < 1) {
		ostringstream s;
		s << "ArrayList is Empty !";
		throw illegalParameterValue(s.str());
	}
	// �ͷŵ����һ��Ԫ��
	element[--list_size].~T();
}


/// <summary>
/// �����б�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_list"></param>
template<class T>
void ArrayList<T>::swap(ArrayList<T>& the_list) {
	T* element = this->element;			// �������Ա��һά����
	int array_length = this->array_length;	// һά��������
	int list_size = this->list_size;		// ���Ա�Ԫ�ظ���
	int list_increase = this->list_increase;	// �б������С

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
/// ���б�������Ϊ����֮��Ľϴ��
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
/// �滻ָ��λ�õ�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <param name="the_element"></param>
template<class T>
void ArrayList<T>::set(int the_index, T the_element) {
	// ��������Ƿ���
	check_index(the_index);

	this->element[the_index] = the_element;
}
/// <summary>
/// ����б�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
void ArrayList<T>::clear() {
	delete[] this->element;
	this->element = new T(array_length);
	this->list_size = 0;
}
/// <summary>
/// ���ָ����Χ�ڵ�Ԫ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="begin_index">��ʼλ��</param>
/// <param name="end_index">����λ��</param>
/// <param name="length">��Χ����</param>
template<class T>
void ArrayList<T>::remove_range(int begin_index, int end_index, int length) {
	if (length != 0) {
		end_index = begin_index + length;
	}
	else {
		length = end_index - begin_index;
	}
	// ��������Ƿ���Ч
	check_index(end_index);
	copy(element + end_index, element + list_size, element + begin_index);
	for (int i = 0; i < length; i++) {
		element[list_size - 1 - i].~T();
	}
	list_size -= length;
}

/// <summary>
/// ����ָ��Ԫ�������ֵ�����
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
/// �ߵ�Ԫ��˳��
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


#pragma region ���������


/// <summary>
/// ����<<
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
/// ����[]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="the_index"></param>
/// <returns></returns>
template<class T>
T& ArrayList<T>::operator[](int the_index) const {
	// �ж������Ƿ���Ч
	check_index(the_index);
	return element[the_index];
}


/// <summary>
/// ����==
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
/// ���أ�=
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
/// ����<
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
/// ��������Ƿ��ڷ�Χ�ڣ������׳��쳣
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
	// �жϳ����Ƿ����
	if (new_length < 0){
		ostringstream s;
		s << "New Length = " << new_length << ". Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	// ת�Ƶ��µ�������
	T* temp = new T[new_length];
	int length = min(new_length, list_size);
	copy(array, array + length, temp);
	delete[] array;
	array = temp;
}



