/**
* brief: 指针的基本用法
* Created by lzy on 2024-09-12.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("%llu\n", sizeof(int *));
    printf("%llu\n", sizeof(char *));
    printf("%llu\n", sizeof(double *));
    printf("%llu\n", sizeof(float *));
    printf("%llu\n", sizeof(short *));
    printf("%llu\n", sizeof(long *));

    /**
     * int *p = &a; 读作 int *p 等于 取地址 a
     * p 是 int * 类型，a 是 int 类型
     */
    int a = 1;
    int* p = &a;
    printf("a=%d\n", a);
    *p = 100;   // 效果等价于 a=100;
    /**
     * 定义时: * 表示变量p是指针，是int * 的类型变量p指向一个int类型的变量
     * 使用时：* 表示指针解引用，取指针p指向的int变量的值（取p指向的内存空间的存储的变量值）
     */
    printf("a=%d\n", a);

    char ch = 'a';
    //int * q = &ch; // Expression of type 'char*' is implicitly converted to incompatible pointer type 'int*',
    char *q = &ch;   // 取地址的类型要和 指针指向的变量的类型一致
    *q = 'x';
    printf("ch=%c\n", ch);
    printf("*q=%c\n", *q);


    printf("p(%%p)=%p\n", p);        // 0000000a4fdff66c, p指向的整数变量的地址，整数占4个字节。p+1 地址增加4个字节
    printf("q(%%p)=%p\n", q);        // 0000000a4fdff66b, q指向的字符变量的地址，字符占1个字节。q+1 地址增加1个字节
    printf("p+1(%%p)=%p\n", p+1);    // 0000000a4fdff670 = 6c + 4 = p + sizeof(int)
    printf("q+1(%%p)=%p\n", q+1);    // 0000000a4fdff66c = 6b + 1 = q + sizeof(char)

    return 0;
}