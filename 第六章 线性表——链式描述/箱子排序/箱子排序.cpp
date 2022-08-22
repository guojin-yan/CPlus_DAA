// 箱子排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "chain.hpp"
#include "student.h"


int main()
{
    Chain<Student> chain_stu(10);
    
    Student stu1("A", 8);
    Student stu2("B", 2);
    Student stu3("R", 9);
    Student stu4("T", 7);
    Student stu5("Y", 8);
    Student stu6("U", 5);
    Student stu7("O", 7);
    Student stu8("W", 6);
    Student stu9("Q", 2);
    Student stu10("E", 10);
    Student stu11("L", 8);
    chain_stu.insret(0, stu1);
    chain_stu.insret(1, stu2);
    chain_stu.insret(2, stu3);
    chain_stu.insret(3, stu4);
    chain_stu.insret(4, stu5);
    chain_stu.insret(5, stu6);
    chain_stu.insret(6, stu7);
    chain_stu.insret(7, stu8); 
    chain_stu.insret(8, stu9);
    chain_stu.insret(9, stu10);
    chain_stu.insret(10, stu11);

    std::cout << chain_stu << std::endl;
    chain_stu.bin_sort(10);
    std::cout << chain_stu << std::endl;
    std::cout << "排序后" << std::endl;

}
