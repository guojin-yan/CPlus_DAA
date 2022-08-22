#pragma once
#include <iostream>

struct Student {
	int score;
	std::string name;
	Student() {}
	Student(std::string name, int score) {
		this->name = name;
		this->score = score;
	}

	int operator!=(const Student& x)const {
		return (score != x.score);
	}

	operator int()const {
		return score;
	}
};
std::ostream& operator<<(std::ostream& out, const Student& x) {
	out << "������ " << x.name << " " << " �ɼ��� " << x.score << std::endl;
	return out;
}