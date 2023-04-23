#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX_ARRAY_DIM 8
#define MAX_ARRAY_DIM 8　 //定义最大维数
typedef struct
{
    int *base;      // 保存数组元素存储空间首地址
    int dim;        // 保存数组维数
    int *bounds;    // 指向保存各维维界的存储空间
    int *constants; // 指向保存求址常量的存储空间
} Array;

// 稀疏矩阵对稀疏矩阵进行压缩存储时，可只保存其中非零元，同时还需指明非零元所处的行列位置及总的行数、列数。使用三元组进行存储
#define MAXSIZE 1000 // 非零元最大个数
typedef struct
{
    int i; // 行下标
    int j; // 列下标
    int e; // 非零元值
} Triple;  // 三元组类型
//三元组定义：
typedef struct
{
    Triple data[MAXSIZE]; // 三元组表
    int m;                // 行数
    int n;                // 列数
    int t;                // 非零元个数
} TSMatrix;
//https://blog.csdn.net/weixin_42437114/article/details/107755449
//略，这个大佬写的确实nb
int main()
{

    system("pause");
    return EXIT_SUCCESS;
}