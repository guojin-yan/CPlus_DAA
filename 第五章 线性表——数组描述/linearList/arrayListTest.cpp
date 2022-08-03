// linearList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "arrayListTest.h"


void test_arrayList()
{
    std::cout << "Arraylist Test!\n";
    ArrayList<int> array(100);
    for (int i = 0; i < 100; i++) {
        array.insert(i, i);
    }
    std::cout << "array.capacity(): " << array.capacity() << std::endl;
    std::cout << "list size: " << array.size() << std::endl;
    std::cout << array << std::endl;
    std::cout << "使用迭代器：" << std::endl;

    ArrayList<int>::iterator it = array.begin();

    for (; it != array.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    // Q4：增加指定列表增大的长度
    std::cout << "Q4测试：" << std::endl;
    std::cout << "未指定列表增加长度：" << std::endl;
    std::cout << "原列表array.capacity(): " << array.capacity() << std::endl;
    array.insert(100, 100);
    std::cout << "插入新值后array.capacity(): " << array.capacity() << std::endl;
    ArrayList<int> array01(100, 5);
    for (int i = 0; i < 100; i++) {
        array01.insert(i, i);
    }
    std::cout << "指定列表增加长度：" << std::endl;
    std::cout << "原列表larray.capacity(): " << array01.capacity() << std::endl;
    array01.insert(100, 100);
    std::cout << "插入新值后array.capacity(): " << array01.capacity() << std::endl;

    // Q5：删除列表空位，压缩列表
    std::cout << "Q5测试：" << std::endl;
    array01.trim_to_size();
    std::cout << "列表压缩后array.capacity(): " << array01.capacity() << std::endl;
    std::cout << "列表压缩后list size: " << array01.size() << std::endl;

    // Q6：重新制定列表长度
    std::cout << "Q6测试：" << std::endl;
    array01.set_size(50);
    std::cout << "重新制定列表长度后array.capacity(): " << array01.capacity() << std::endl;
    std::cout << "重新制定列表长度后list size: " << array01.size() << std::endl;
    array01.set_size(200);
    std::cout << "重新制定列表长度后array.capacity(): " << array01.capacity() << std::endl;
    std::cout << "重新制定列表长度后list size: " << array01.size() << std::endl;

    // Q7：重载[]
    std::cout << "Q7测试：" << std::endl;
    std::cout << "array[10] = " << array[10] << std::endl;
    std::cout << "array[50] = " << array[50] << std::endl;
    // Q8：重载==
    std::cout << "Q8测试：" << std::endl;
    ArrayList<int> array2(100);
    for (int i = 0; i < 100; i++) {
        array2.insert(i, i+1);
    }
    ArrayList<int> array3(100);
    for (int i = 0; i < 50; i++) {
        array3.insert(i, i);
    }
    for (int i = 50; i < 100; i++) {
        array3.insert(i, i + 1);
    }
    ArrayList<int> array4(100);
    for (int i = 0; i < 100; i++) {
        array4.insert(i, i + 2);
    }
    std::cout << "array与array01: " << (array==array01) << std::endl;
    std::cout << "array与array2: " << (array2 == array2) << std::endl;
    std::cout << "array与array3: " << (array2 == array3) << std::endl;
    std::cout << "array2与array4: " << (array2 == array4) << std::endl;
    // Q9：重载!=
    std::cout << "Q9测试：" << std::endl;
    std::cout << "array与array01: " << (array != array01) << std::endl;
    std::cout << "array与array2: " << (array2 != array2) << std::endl;
    std::cout << "array与array3: " << (array2 != array3) << std::endl;
    std::cout << "array2与array4: " << (array2 != array4) << std::endl;

    // Q10：重载<
    std::cout << "Q10测试：" << std::endl;
    std::cout << "array2与array4: " << (array2 < array4) << std::endl;

    // Q11-12：右插入与删除
    std::cout << "Q11-12测试：" << std::endl;
    ArrayList<string> str1(10);
    str1.push_back("asdfgh");
    str1.push_back("rrvg");
    str1.push_back("wrgtw ");
    str1.push_back("wt gw");
    str1.push_back("tg s gsr");
    std::cout << "str1: " << std::endl;
    std::cout << str1 << std::endl;
    str1.pop_back();
    str1.pop_back();
    str1.pop_back();
    std::cout << "str1: " << std::endl;
    std::cout << str1 << std::endl;

    // Q13: swap()交换
    std::cout << "Q13测试：" << std::endl;
    ArrayList<char> c1(10);
    c1.push_back('a');
    c1.push_back('e');
    c1.push_back('r');
    c1.push_back('h');
    c1.push_back('v');
    c1.push_back('j');
    c1.push_back('e');
    std::cout << "c1: " << std::endl;
    std::cout << c1 << std::endl;

    ArrayList<char> c2(15);
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    c2.push_back('a');
    std::cout << "c2: " << std::endl;
    std::cout << c2 << std::endl;
    c1.swap(c2);
    std::cout << "c1: " << std::endl;
    std::cout << c1 << std::endl;
    std::cout << "c2: " << std::endl;
    std::cout << c2 << std::endl;

    // Q14: 将列表容量设为两个之间的较大的
    std::cout << "Q14测试：" << std::endl;
    c1.reserve(c2);
    std::cout << "c1 array.capacity(): " << c1.capacity() << std::endl;
    std::cout << "c2 array.capacity(): " << c2.capacity() << std::endl;

    // Q1516: 修改指定位置元素，清空列表内容
    std::cout << "Q1516测试：" << std::endl;
    c1.set(5, '@');
    std::cout << "c1: " << std::endl;
    std::cout << c1 << std::endl;
    c2.clear();
    std::cout << "c2: " << std::endl;
    std::cout << c2 << std::endl;
    std::cout << "c2 list_size(): " << c2.size() << std::endl;

    // Q17: 移除指定范围内的元素
    std::cout << "Q17测试：" << std::endl;
    ArrayList<int> d1(50);
    for (int i = 0; i < 50; i++) {
        d1.insert(i, i);
    }
    std::cout << "d1: " << std::endl;
    std::cout << d1 << std::endl;
    d1.remove_range(10,20,20);
    std::cout << "d1: " << std::endl;
    std::cout << d1 << std::endl;
    std::cout << "d1 list_size(): " << d1.size() << std::endl;

    // Q18: 查找元素出现的最后索引
    std::cout << "Q18测试：" << std::endl;
    ArrayList<char> c3(50);
    c3.push_back('w');
    c3.push_back('r');
    c3.push_back('y');
    c3.push_back('v');
    c3.push_back('w');
    c3.push_back('u');
    c3.push_back('q');
    c3.push_back('c');
    c3.push_back('c');
    c3.push_back('k');
    std::cout << c3.last_inexOf('w') << std::endl;
    std::cout << c3.last_inexOf('a') << std::endl;
    std::cout << c3.last_inexOf('c') << std::endl;

    // Q22: 颠倒元素
    std::cout << "Q22测试：" << std::endl;
    std::cout << "c3: " << std::endl;
    std::cout << c3 << std::endl;
    std::cout << "c3.reverse(): " << std::endl;
    c3.reverse();
    std::cout << c3 << std::endl;
    c3.push_back('l');
    std::cout << "c3: " << std::endl;
    std::cout << c3 << std::endl;
    std::cout << "c3.reverse(): " << std::endl;
    c3.reverse();
    std::cout << c3 << std::endl;

    // Q23: 元素左移
    std::cout << "Q23测试：" << std::endl;
    std::cout << "c3: " << std::endl;
    std::cout << c3 << std::endl;
    std::cout << "c3.left_shift(5): " << std::endl;
    c3.left_shift(5);
    std::cout << c3 << std::endl;

    // Q24: 查找元素出现的最后索引
    std::cout << "Q24测试：" << std::endl;
    ArrayList<char> c4(50);
    c4.push_back('w');
    c4.push_back('r');
    c4.push_back('y');
    c4.push_back('v');
    c4.push_back('w');
    c4.push_back('u');
    c4.push_back('q');
    c4.push_back('c');
    c4.push_back('c');
    c4.push_back('k');
    std::cout << "c4: " << std::endl;
    std::cout << c4 << std::endl;
    c4.circular_shift(5);
    std::cout << "c4.circular_shift(5): " << std::endl;
    std::cout << c4 << std::endl;

    // Q25: 删除一半元素
    std::cout << "Q25测试：" << std::endl;
    ArrayList<int> d2(50);
    for (int i = 0; i < 50; i++) {
        d2.insert(i, i);
    }
    std::cout << "d2: " << std::endl;
    std::cout << d2 << std::endl;
    d2.half();
    std::cout << "d2: " << std::endl;
    std::cout << d2 << std::endl;
    ArrayList<int> d3(50);
    for (int i = 0; i < 9; i++) {
        d3.insert(i, i);
    }
    std::cout << "d3: " << std::endl;
    std::cout << d3 << std::endl;
    d3.half();
    std::cout << "d3: " << std::endl;
    std::cout << d3 << std::endl;

    // Q28: 合并两个列表，交替填充
    std::cout << "Q28测试：" << std::endl;

    ArrayList<int> d4(50);
    for (int i = 0; i < 30; i++) {
        d4.insert(i, i);
    }
    ArrayList<int> d5(50);
    for (int i = 0; i < 40; i++) {
        d5.insert(i, 100+i);
    }
    ArrayList<int> d6(50);
    std::cout << "d4: " << std::endl;
    std::cout << d4 << std::endl;
    std::cout << "d5: " << std::endl;
    std::cout << d5 << std::endl;

    d6.meld(d4, d5);
    std::cout << "d6: " << std::endl;
    std::cout << d6 << std::endl;

    // Q29: 合并两个有序列表，从左到右非递减有序
    std::cout << "Q29测试：" << std::endl;
    ArrayList<int> d7(50);
    for (int i = 0; i < 30; i++) {
        d7.insert(i, 90-3*i);
    }
    ArrayList<int> d8(50);
    for (int i = 0; i < 40; i++) {
        d8.insert(i, 50-i);
    }
    ArrayList<int> d9(50);
    std::cout << "d7: " << std::endl;
    std::cout << d7 << std::endl;
    std::cout << "d8: " << std::endl;
    std::cout << d8 << std::endl;

    d9.merge(d7, d8);
    std::cout << "d9: " << std::endl;
    std::cout << d9 << std::endl;
    std::cout << d9.size() << std::endl;

    // Q30: 将线性表按照奇偶位置拆解
    std::cout << "Q30测试：" << std::endl;
    ArrayList<int> d10(50);
    ArrayList<int> d11(50);
    d7.split(d10, d11);
    std::cout << "d7: " << std::endl;
    std::cout << d7 << std::endl;
    std::cout << "d10: " << std::endl;
    std::cout << d10 << std::endl;
    std::cout << "11: " << std::endl;
    std::cout << d11 << std::endl;
}

