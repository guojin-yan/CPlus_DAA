#pragma once

template<class T>
class ArrayList_iterator {
public:
	/*typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;*/

	// ���캯��
	ArrayList_iterator(T* the_position) { position = the_position; }

	T* get_position() const{
		return position;
	}


	// �����ò�����
	T& operator*() const { return *position; }
	T* operator->() const { return&* position; }

	// ��������ֵ����
	// ǰ��
	ArrayList_iterator& operator++() {
		++position; 
		return *this; 
	}
	// ���
	ArrayList_iterator& operator++(int) {
		ArrayList_iterator old = *this;
		++position; 
		return old; 
	}

	// ��������ֵ��С
	// ǰ��
	ArrayList_iterator& operator--() {
		--position;
		return *this;
	}
	// ���
	ArrayList_iterator& operator--(int) {
		ArrayList_iterator old = *this;
		--position;
		return old;
	}

	ArrayList_iterator& operator-(ArrayList_iterator it) {
		this->position = (T*)(this->position - it.position);
		return *this;
	}

	// ����ж�
	bool operator!=(const ArrayList_iterator right) const {
		return position != right.position;
	}
	bool operator==(const ArrayList_iterator right) const {
		return position == right.position;
	}
protected:
	T* position;  // ָ��Ԫ�ص�ָ��
};