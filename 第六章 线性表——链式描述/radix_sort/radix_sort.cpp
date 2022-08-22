// radix_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <cstdlib>

#include "chain.hpp"


int main()
{
    
    std::cout << rand() % 10000 << std::endl;
    Chain<int> chain(100);
    for (int i = 0; i < 1000; i++) {
        int r = rand() % 10000000;
        chain.insret(i, r);
    }
    std::cout << chain << std::endl;
    chain.radix_sort(100, 10000000);
    std::cout << chain << std::endl;
}


