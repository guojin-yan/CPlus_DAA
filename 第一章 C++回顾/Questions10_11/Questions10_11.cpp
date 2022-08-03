// Questions10_11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/// <summary>
/// Q10: 抛出整形异常
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns></returns>
int abc(int a, int b, int c) {
    if (a < 0 && b < 0 && c < 0) {
        throw 1;
    }
    else if (a == 0 && b == 0 && c == 0) {
        throw 1;
    }
    return a + b * c;
}

/// <summary>
/// Q11：当size<1时抛出char*异常
/// Q2: 统计数组a中calue出现的个数
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
/// <param name="a">统计数组</param>
/// <param name="size">数组长度</param>
/// <param name="value">统计值</param>
/// <returns>个数</returns>
template<typename T>
int count(T* a, int size, T value) {
    if (size < 1) {
        throw "size < 1";
    }
    int counts = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == value) {
            counts++;
        }
    }
    return counts;
}

int main()
{
    // test Q10:
    std::cout << "test Q10: \n";
    try {
        std::cout<<abc(1,22,3) << std::endl;
        int s = abc(-1, -2, -3);
    }
    catch(int e) {
        std::cout << e << std::endl;
    }
    char a[] = "eeeee";
    char* a1 = a;
    std::cout << a1 << std::endl;
    //test Q11
    try {
        std::cout << "Q11测试：" << std::endl;
        int a01[10] = { 10,20,30,10,20,20,30,45,40,20 };
        int value01 = 20;
        int count01 = count(a01, 0, value01);
        std::cout << "count01 ： " << count01 << std::endl;
    }
    catch (char*e) {
        std::cout << e << std::endl;
    }

   

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
