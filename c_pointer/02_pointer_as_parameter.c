/**
* brief: 指针作为函数参数，通过函数调用修改对应内存
* Created by lzy on 2024-09-13.
*/

#include <stdio.h>

void swap_(int x, int y);
void swap(int * x, int * y);

int main(int args, char** argv)
{
    int a = 1, b = 2;
    swap_(a, b);
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);                 // 交换实参的值，必须要传地址
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

void swap_(int x, int y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("x=%d, y=%d\n", x, y);
}

// 经过函数调用，实参对应的变量的值也会被修改。
void swap(int * x, int * y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
    printf("*x=%d, *y=%d\n", *x, *y);
}
