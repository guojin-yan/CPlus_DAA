// Questions12_14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/// <summary>
/// Q12：创建二维数组
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="x"></param>
/// <param name="number_rows"></param>
/// <param name="row_size"></param>
template<class T>
void mak2dArray(T** &x, int number_rows, int* row_size) {
    // 创建行指针
    x = new T * [number_rows];

    // 为每一行分配空间
    for (int i = 0; i < number_rows; i++) {
        x[i] = new T[row_size[i]];
    }

}

/// <summary>
/// Q13: 改变一维数组的大小
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="old_length"></param>
/// <param name="new_length"></param>
/// <returns></returns>
template<class T>
T* chang_length_1D(T* a, int old_length, int new_length) {
    T* b = new T[new_length];
    for (int i = 0; i < std::min(old_length, new_length); i++){
        b[i] = a[i];
    }
    delete[]a;
    return b;
}


int main()
{
    // test12
    int size[5] = { 3,4,5,6,7 };
    double** x = NULL;

    try{
        mak2dArray(x,5,size);
        std::cout << "创建成功！！！\n";
    }
    catch (std::bad_alloc e) {
        std::cout << "创建失败！！！\n";
    }


    // test13
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int *b = new int;
    b = chang_length_1D( a, 10, 5);

    for (int i = 0; i < 6; i++) {
        std::cout << b[i] << "  ";
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
