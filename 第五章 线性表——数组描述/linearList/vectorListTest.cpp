#include "vectorListTest.h"

// 测试

void vectorList() {

	VectorList<int> a1(100);
	for (int i = 0; i < 50; i++) {
		a1.insert(i,i);
	}

	std::cout << "a1: " << a1 << std::endl;

	// Q37: 间隔删除元素
	std::cout << "Q37测试 " << std::endl;
	a1.half();
	std::cout << "a1: " << a1 << std::endl;

	// Q37: 合并两个列表，交替填充
	std::cout << "Q38测试 " << std::endl;
	VectorList<int> a2(100);
	for (int i = 0; i < 20; i++) {
		a2.insert(i, i+100);
	}
	VectorList<int> a3(100);
	for (int i = 0; i < 30; i++) {
		a3.insert(i, i);
	}
	VectorList<int> a4(100);
	a4.meld(a2,a3);
	std::cout << "a4: " << a4 << std::endl;


	VectorList<int> a5(100);
	for (int i = 0; i < 20; i++) {
		a5.insert(i, 100 - 4*i );
	}
	VectorList<int> a6(100);
	for (int i = 0; i < 30; i++) {
		a6.insert(i, 60 - i);
	}
	std::cout << "a5: " << a5 << std::endl;
	std::cout << "a5: " << a5.size() << std::endl;
	std::cout << "a6: " << a6 << std::endl;
	VectorList<int> a7(100);
	a7.merge(a5, a6);

	std::cout << "a7: " << a7 << std::endl;
	std::cout << "a7: " << a7.size() << std::endl;

	VectorList<int> a8(100);
	for (int i = 0; i < 80; i++) {
		a8.insert(i, i+1);
	}
	VectorList<int> a9(100);
	VectorList<int> a10(100);
	a8.split(a9,a10);

	std::cout << "a9: " << a9 << std::endl;
	std::cout << "a10: " << a10 << std::endl;
}