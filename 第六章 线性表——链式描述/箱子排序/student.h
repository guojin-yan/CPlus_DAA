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
	out << "ÐÕÃû£º " << x.name << " " << " ³É¼¨£º " << x.score << std::endl;
	return out;
}