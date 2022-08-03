// Questions2_7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/// <summary>
/// Q2: 统计数组a中calue出现的个数
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
/// <param name="a">统计数组</param>
/// <param name="size">数组长度</param>
/// <param name="value">统计值</param>
/// <returns>个数</returns>
template<typename T>
int count(T *a, int size, T value) {
    int counts = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == value) {
            counts++;
        }
    }
    return counts;
}


/// <summary>
/// Q3: 将数组的值都为value
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
/// /// <param name="a">数组</param>
/// <param name="value">数组内容</param>
/// <param name="size">数组长度</param>
/// <returns>生成的数组</returns>
template<typename T>
void fill(T* a, T value, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = value;
    }

}

/// <summary>
/// 求两个数组乘积
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
/// <param name="a">数组1</param>
/// <param name="b">数组2</param>
/// <param name="size">数组长度</param>
/// <returns>数组乘积</returns>
template<typename T>
T inner_product(T* a, T*b, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + a[i] * b[i];
    }
    return sum;
}

/// <summary>
/// a[i] = value+i
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
/// <param name="a">数组</param>
/// <param name="value">值</param>
/// <param name="size">数组长度</param>
template<typename T>
void iota(T* a, T value, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = value + i;
    }
}

/// <summary>
/// 判断数组是否有有序，有序返回true，无序返回flase
/// </summary>
/// <typeparam name="T">数据类型</typeparam>
/// <param name="a">数组</param>
/// <param name="size">数组长度</param>
/// <returns>判断结果</returns>
template<typename T>
bool is_sorted(T*a, int size) {
    // 判断是否为正序
    if (a[0] >= a[size - 1]) {
        for (int i = 1; i < size - 1; i++) {
            if (a[i - 1] <= a[i]) {
                return false;
            }
        }
        return true;
    }
    else{//判断是否为倒序
        for (int i = 1; i < size - 1; i++) {
            if (a[i - 1] > a[i]) {
                return false;
            }
        }
        return true;
    }
}

/// <summary>
/// Q7: 使两个数组变量相等的最小索引
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="size"></param>
/// <returns></returns>
template<typename T>
int mismatch(T* a, T*b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] == b[i]) {
           
            return i;
        }
    }
    return -1;
}

int main()
{
    //test Q2:
    std::cout << "Q2测试：" << std::endl;
    int a01[10] = {10,20,30,10,20,20,30,45,40,20};
    int value01 = 20;
    int count01 = count(a01, 10, value01);
    std::cout << "count01 ： " << count01 <<std::endl;

    char a02[10] = { 'a','s','a','f','a','s','a','s','a' };
    char value02 = 'a';
    int count02 = count(a02, 10, value02);
    std::cout << "count02 ： " << count02 << std::endl;
    std::cout << "----------------------------" << std::endl;

    //test Q3:
    std::cout << "Q3测试：" << std::endl;

    int b01[10];
    fill(b01, 2, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << b01[i] << "  ";
    }
    std::cout<<std::endl;

    char b02[10];
    fill(b02, 'd', 10);
    for (int i = 0; i < 10; i++) {
        std::cout << b02[i] << "  ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;

    //test Q4:
    std::cout << "Q4测试：" << std::endl;

    int c01[10] = { 1,2,6,3,8,9,4,6,5,8 };
    int c02[10] = { 5,9,6,3,7,8,5,1,8,6 };
    int sum01 = inner_product(c01, c02, 10);
    std::cout << "sum01 ： " << sum01 << std::endl;

    float c03[10] = { 1,2,6,3,8,9,4,6,5,8 };
    float c04[10] = { 5,9,6,3,7,8,5.21,1.26,8.56,6 };
    float sum02 = inner_product(c03, c04, 10);
    std::cout << "sum01 ： " << sum02 << std::endl;
    std::cout << "----------------------------" << std::endl;

    //test Q5:
    std::cout << "Q5测试：" << std::endl;

    int d01[20];
    iota(d01, 10, 20);
    std::cout << "d01 ： " << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << d01[i] << "  ";
    }
    std::cout << std::endl;

    char d02[20];
    iota(d02, 'a', 20);
    std::cout << "d02 ： " << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << d02[i] << "  ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;


    //test Q6:
    std::cout << "Q6测试：" << std::endl;

    int e01[10] = { 1,2,3,8,9,14,16,25,28,30 };
    int e02[10] = { 5,9,6,3,7,8,5,1,8,6 };
    double e03[10] = { 1.11,2.3,5.6,8.9,10.566,12.999,14.56,78.2,102.3,863.8 };

    bool flag1 = is_sorted(e01, 10);
    bool flag2 = is_sorted(e02, 10);
    bool flag3 = is_sorted(e03, 10);

    std::cout << "flag1 ： " << flag1 << std::endl;
    std::cout << "flag2 ： " << flag2 << std::endl;
    std::cout << "flag3 ： " << flag3 << std::endl;

    std::cout << "----------------------------" << std::endl;



    //test Q7:
    std::cout << "Q7测试：" << std::endl;

    int f01[10] = { 1,2,6,3,8,9,4,6,5,8 };
    int f02[10] = { 5,9,6,3,7,8,5,1,8,6 };
    int index01 = mismatch(c01, c02, 10);
    std::cout << "index01 ： " << index01 << std::endl;

    float f03[10] = { 1,2,6.14,3.25,8,9,5.21,6,5,8 };
    float f04[10] = { 5,9,6,3,7,8,5.21,1.26,8.56,6 };
    int index02 = mismatch(f03, f04, 10);
    std::cout << "index02 ： " << index02 << std::endl;
    std::cout << "----------------------------" << std::endl;
}



