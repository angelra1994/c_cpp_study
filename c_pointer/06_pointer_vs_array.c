/**
* brief: 从使用的角度而言，指针和数组是可以互相替换的
* Created by lzy on 2024-09-17.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[5] = {1, 22, 33, 44, 5};
    // int *p = &a[0];
    int *p = a;

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("a[%d]=%d,", i, a[i]);
        printf("*p+%d=%d ", i,  *(p+i));
    }
    printf("\n");

    char* str = "hello";   //8个字节的栈空间的 str 指向 存储在只读数据区的字符串常量 "hello"
    printf_s("%c\n", *str);
    printf_s("%s\n", str);
    for (i = 0; i < 5; i++)
    {
        printf_s("%c \n", str[i]);  // 通过数组的方式访问指针
    }
    return 0;
}
