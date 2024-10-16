/**
* brief:
* Created by lzy on 2024-09-17.
*/


#include <stdio.h>

void array_length(char a[])
{
    // 节约栈空间内存，函数传参的时候，只是把数组首地址传递过去。避免把整个数组复制过去
    // 函数调用传入数组名，数组名赋值给了参数a，局部变量a持有变量a的值。即a[0]的地址。在编译器看来，局部变量a是地址
    printf("%llu, %llu\n", sizeof(a), sizeof(a)/sizeof(a[0]));  // 8, 8
    int b[10] = {};
    printf("%llu, %llu\n", sizeof(b), sizeof(b)/sizeof(b[0]));  // 40, 10
    char c[] = {};
    printf("%llu, %llu\n", sizeof(c), sizeof(c)/sizeof(c[0]));  // 0, 0
}

int main(int argc, char* argv[])
{
    char str[32] = "helloworld";   // 在栈空间申请了，一块32个字节的内存，里面存储了由常量区复制过来的"helloworld"字符和结尾补充上的'/0'
    char *p = "helloworld";   // "helloworld"在字符串常量区，内容不能修复

    // 数组名是指针常量，数组名不能指向其他地址 (Cannot apply postfix operator++ to an array type char[32])
    // str++;   // lvalue required as increment operand. 一旦数组被定义，数组名就代表了一个固定的内存地址，这个地址在程序运行期间不能被改变
    p++;

    //char *const q = "helloworld";
    //q++; // increment of read-only variable 'q'

    str[0] = 'x';
    // p[0] = 'x';   // error: assignment of read-only location 'p[0]', p[0] 指向了常量区

    printf("%llu\n", sizeof(str));  //数组的长度的字节数  32
    printf("%llu\n", sizeof(p));    //指针的长度的字节数  8

    int a[] = {0};
    array_length(a);

    return 0;
}
