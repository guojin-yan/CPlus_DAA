#pragma once

#include <iostream>


/// <summary>
/// ���Ա������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class linearList {

public:
	virtual ~linearList() {};

	// �ж����Ա��Ƿ�Ϊ��
	virtual bool empty() const = 0;
	// ��ȡ���Ա���
	virtual int size() const = 0;
	// ��ȡ���Ա�ָ��������ֵ
	virtual T& get(int the_index) const = 0;
	// ���ҵ�һ�γ���the_element������
	virtual int indexOf(const T& the_element)const = 0;
	// ɾ��ָ������λ�õ�Ԫ��
	virtual void erase(int the_index) = 0;
	// �����Ա�ָ��λ�ò���ָ��Ԫ��
	virtual void insert(int the_index, const T& the_element) = 0;
	// �����Ա���뵽�����
	virtual void output(std::ostream& out) const = 0;
};