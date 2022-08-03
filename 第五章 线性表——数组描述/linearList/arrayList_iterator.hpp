#pragma once

template<class T>
class ArrayList_iterator {
public:
	/*typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;*/

	// 构造函数
	ArrayList_iterator(T* the_position) { position = the_position; }

	T* get_position() const{
		return position;
	}


	// 解引用操作符
	T& operator*() const { return *position; }
	T* operator->() const { return&* position; }

	// 迭代器的值增加
	// 前加
	ArrayList_iterator& operator++() {
		++position; 
		return *this; 
	}
	// 后加
	ArrayList_iterator& operator++(int) {
		ArrayList_iterator old = *this;
		++position; 
		return old; 
	}

	// 迭代器的值减小
	// 前减
	ArrayList_iterator& operator--() {
		--position;
		return *this;
	}
	// 后减
	ArrayList_iterator& operator--(int) {
		ArrayList_iterator old = *this;
		--position;
		return old;
	}

	ArrayList_iterator& operator-(ArrayList_iterator it) {
		this->position = (T*)(this->position - it.position);
		return *this;
	}

	// 相等判断
	bool operator!=(const ArrayList_iterator right) const {
		return position != right.position;
	}
	bool operator==(const ArrayList_iterator right) const {
		return position == right.position;
	}
protected:
	T* position;  // 指向元素的指针
};