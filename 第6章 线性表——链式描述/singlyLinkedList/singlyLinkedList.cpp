// singlyLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "chain.hpp"
#include "chain_extend.hpp"
#include "arrayList.hpp"

int main()
{
    std::cout << "Hello World!\n";
    Chain<char> a(26);
    char s;
    for (int i = 0; i < 26; i++) {
        s = (int)'a' + (char)i;
        a.insret(i, s);
        
    }
    std::cout << "a: " << a << std::endl;

    // Q2测试：设置线性表长度
    std::cout << "Q2测试：设置线性表长度" << std::endl;
    a.set_size(20);
    std::cout << "a: " << a << std::endl;
    a.set_size(24);
    std::cout << "a: " << a << std::endl;

    // Q3测试：修改指定位置的元素
    std::cout << "Q3测试：修改指定位置的元素" << std::endl;
    char ss = 's';
    a.set(5, ss);
    std::cout << "a: " << a << std::endl;

    // Q4测试：删除指定索引范围内的元素
    std::cout << "Q4测试：删除指定索引范围内的元素" << std::endl;
    a.remove_range(10, 15);
    std::cout << "a: " << a << std::endl;

    // Q5测试：返回指定值最后出现的索引
    std::cout << "Q5测试：返回指定值最后出现的索引" << std::endl;
    a.set(7, ss);
    a.set(10, ss);
    a.set(12, ss);
    a.set(2, ss);
    std::cout << "a: " << a << std::endl;
    int index = a.last_indexOf(ss);
    std::cout << "last s in the : " << index << std::endl;

    // Q10测试：交换两个链表元素
    std::cout << "Q10测试：交换两个链表元素" << std::endl;
    Chain<int> b1(50), b2(40);
    for (int i = 0; i < 10; i++) {
        b1.insret(i, i);
        int bb = i + 10;
        b2.insret(i, bb);
    }
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;
    b1.swap(b2);
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;

    // Q6测试：重载[]
    std::cout << "Q6测试：重载[]" << std::endl;
    std::cout << "a[10] = " << a[10] << std::endl;
    std::cout << "a[14] = " << a[14] << std::endl;

    // Q7-9测试：重载== != <
    Chain<int> c1(50), c2(50), c3(50), c4(50);
    for (int i = 0; i < 30; i++) {
        c1.insret(i, i);
        int bb = i + 10;
        c2.insret(i, bb);
        c3.insret(i, i);
        bb = i + 15;
        c4.insret(i, bb);
    }
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "bc2: " << c2 << std::endl;
    std::cout << "c3: " << c1 << std::endl;
    std::cout << "c4: " << c2 << std::endl;
    std::cout << "c1 == c2: " << (c1 == c2) << std::endl;
    std::cout << "c1 == c3: " << (c1 == c3) << std::endl;
    std::cout << "c1 != c2: " << (c1 != c2) << std::endl;
    std::cout << "c1 != c3: " << (c1 != c3) << std::endl;
    std::cout << "c2 < c4: " << (c2 < c4) << std::endl;
    std::cout << "c4 < c2: " << (c4 < c2) << std::endl;


    // Q11测试：将arrayList转为chain
    std::cout << "Q11测试：将arrayList转为chain" << std::endl;
    ArrayList<char> arr(30);
    char sss;
    for (int i = 0; i < 26; i++) {
        sss = (int)'a' + (char)i;
        arr.push_back(sss);
    }
    std::cout << "arrayList array = : " << arr << std::endl;

    Chain<char> chain(100);
    array_to_chain_list(arr,chain);
    std::cout << "chainList list = : " << chain << std::endl;

    // Q12测试：将chain转为arrayList
    std::cout << "Q12测试：将chain转为arrayList" << std::endl;
    Chain<char> chain01 (50);
    char s4;
    for (int i = 0; i < 26; i++) {
        s4 = (int)'a' + (char)i;
        chain01.insret(i, s4);
    }
    std::cout << "chainList list = : " << chain01 << std::endl;
    

    ArrayList<char> arr01(100);
    chain_to_array_list(chain01, arr01);
    std::cout << "arrayList array = : " << arr01 << std::endl;



    // Q13测试：将arrayList转为chain
    std::cout << "Q13测试：将arrayList转为chain" << std::endl;
    ArrayList<char> arr1(30);
    char sss1;
    for (int i = 0; i < 26; i++) {
        sss1 = (int)'a' + (char)i;
        arr1.push_back(sss1);
    }
    std::cout << "arrayList array = : " << arr << std::endl;

    Chain<char> chain1(100);
    chain1.from_list(arr1);
    std::cout << "chainList list = : " << chain1 << std::endl;

    // Q13测试：将chain转为arrayList
    std::cout << "Q13测试：将chain转为arrayList" << std::endl;
    Chain<char> chain2(50);
    char s5;
    for (int i = 0; i < 26; i++) {
        s5 = (int)'a' + (char)i;
        chain2.insret(i, s5);
    }
    std::cout << "chainList list = : " << chain2 << std::endl;


    ArrayList<char> arr2(100);
    chain2.to_list(arr2);
    std::cout << "arrayList array = : " << arr2 << std::endl;

    // Q14测试：左移元素
    std::cout << "Q14测试：左移元素" << std::endl;
    Chain<char> e1(26);
    char s6;
    for (int i = 0; i < 26; i++) {
        s6 = (int)'a' + (char)i;
        e1.insret(i, s6);

    }
    std::cout << "e1 = : " << e1 << std::endl;
    e1.left_shift(5);
    std::cout << "e1 = : " << e1 << std::endl;

    // Q15测试：颠倒元素
    std::cout << "Q15测试：颠倒元素" << std::endl;
    Chain<char> e2(26);
    char s7;
    for (int i = 0; i < 26; i++) {
        s7 = (int)'a' + (char)i;
        e2.insret(i, s7);

    }
    std::cout << "e2 = : " << e2 << std::endl;
    e2.reverse();
    std::cout << "e2 = : " << e2 << std::endl;
    // Q17测试：合并链表
    std::cout << "Q17测试：合并链表" << std::endl;
    Chain<char> e3(26);
    Chain<char> e4(26);
    for (int i = 0; i < 26; i++) {
        s7 = (int)'a' + (char)i;
        e3.insret(i, s7);
    }
    for (int i = 0; i < 5; i++) {
        s7 = (int)'a' + (char)i;
        e4.insret(i, s7);
    }
    Chain<char> e5(100);
    meld(e5, e3, e4);
    std::cout << "e5 = : " << e5 << std::endl;
    std::cout << "e5 = : " << e5.size() << std::endl;

    // Q18测试：合并链表
    std::cout << "Q18测试：合并链表" << std::endl;
    Chain<char> e6(100);
    std::cout << "e3 = : " << e3 << std::endl;
    std::cout << "e4 = : " << e4 << std::endl;
    e6.meld(e3, e4);
    std::cout << "e6 = : " << e6 << std::endl;
    std::cout << "e6 = : " << e6.size() << std::endl;

    // Q20测试：合并两个有序列表
    std::cout << "Q20测试：合并两个有序列表" << std::endl;
    Chain<char> e7(100);
    e7.merge(e3, e4);
    std::cout << "e7 = : " << e7 << std::endl;
    std::cout << "e7 = : " << e7.size() << std::endl;
}
