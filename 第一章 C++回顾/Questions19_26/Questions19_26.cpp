// Questions19_26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>

/// <summary>
/// Q19：计算 n!
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

/// <summary>
/// Q20: 计算斐波那契数列
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

/// <summary>
/// Q21：21题函数
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int f21(int n) {
    if (n % 2 == 0) {
        return n / 2; 
    }
    else {
        return f21(3 * n + 1);
    }
}

int ackermanns(int i, int j) {
    if (i == 1 && j >= 1) {
        return std::pow(2,j);
    }
    else if (i >= 2 && j == 1) {
        return ackermanns(i - 1, 2);
    }
    else {
        int s = ackermanns(i, j - 1);
        return ackermanns(i - 1, s);
    }
}

int main()
{
    //test 19:
    std::cout << "Q19: 计算n!\n";
    int n1 = factorial(5);
    std::cout << n1 << std::endl;

    //test 20:
    std::cout << "Q20: 计算斐波那契数列\n";
    int n2 = fibonacci(5);
    std::cout << n2 << std::endl;

    //test 21:
    std::cout << "Q20: 计算f21\n";
    int n3 = f21(7);
    std::cout << n3 << std::endl;
    //test 22:
    std::cout << "Q20: 计算阿尔曼函数\n";
    int n4 = ackermanns(2,2);
    std::cout << n4 << std::endl;
}


