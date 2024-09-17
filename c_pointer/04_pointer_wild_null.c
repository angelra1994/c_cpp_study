/**
* brief:
* Created by lzy on 2024-09-16.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    // 指针访问了不确定地址和无效内存地址
    //int *p1;
    //*p1 = 100;  //Linux环境下可能出现 Segmentation Error：段错误，访问了不能访问的内存

    int *p2 = NULL;
    *p2 = 100;
    // Process finished with exit code -1073741819 (0xC0000005)

    // 1. 使用系统分配的内存, &(取变量地址)，只读数据区
    int a;
    int *p1 = &a;

    // 2. 用户申请内存，malloc 申请的堆内存
    char* str = (char *)malloc(32); // 向操作系统动态申请32个字节的堆内存，运行的时候才能分配
    free(str);  // 释放内存，和malloc成对出现，如果忘记释放，则会造成内存泄露
    str = NULL; // 释放完的内存，需要置空改变指向成空，不然str就会变成野指针（否则会指向一块已经被释放的内存）

    printf("end!");

    return 0;
}
