/**
* brief: 指针相关运算
* Created by lzy on 2024-09-16.
*/

/**
 1. 赋值运算
    int a, *pa = &a, *pb, pb = pa;  (4条语句)
 2. 常见笔试题
    int x = 3, y = 0, *px = &x;
    y = *px + 5;
    y = ++*px;
    y = *px++;  // *p++和 (*p)++的区别*
 */

#include <stdio.h>

void point_calcuate(void)
{
    int x = 3, y = 0, *px = &x;
    y = *px + 5;  // y = (*px) + 5 = x + 5 = 8
    printf("y=%d, x=%d, (*px=%d, px=%p, &y=%p)\n", y, x, *px, px, &y);
    y = ++*px;    // y = ++(*px) = ++x = 4
    printf("y=%d, x=%d, (*px=%d, px=%p, &y=%p)\n", y, x, *px, px, &y);
    y = *px++;   // y = *px; px++;
    printf("y=%d, x=%d, (*px=%d, px=%p, &y=%p)\n", y, x, *px, px, &y);
}

void my_strcpy(char* dst, const char* src)
{
    // 先判断再赋值
    // while (*src != '\0')
    // {
    //     *dst++ = *src++;
    // }

    // 先赋值再判断
    while ((*dst++ = *src++) != '\0');
}

/**
 * 常量指针: const int * p/ int const * p; const 修饰的是 *p.
 * 指针常量: int* const p; const 修饰的是 p, p不能指向其他地址
 */
void f()
{
    int num;
    int const * p11 = &num;
    const int *p1 = &num;  //常量指针（指向常量的指针）。const修饰了 *p1，不能通过*p1 的方式对内存块中变量进行修改
    //(*p1)++;  // Cannot apply postfix operator++ to readonly type const int. increment of read-only location '*p1'
    p1++;   // p1存储的地址值可以修改，即p1可以指向其他地址
    int *const p2 = &num; //指针常量（指针类型的常量） const 修饰p2
    //p2++;      // Cannot apply postfix operator++ to readonly type int* const
    (*p2)++; // 可以使用*p2的方式，修改p2指向的内存

    const int *const p3 = &num;

}

int main(int argc, char* argv[])
{
    point_calcuate();

    char s1[32] = "hello";
    // char s2[32] = {0};
    char s2[32] = "12345678";
    printf_s("s1=%s, s2=%s\n",s1, s2);

    my_strcpy(s2, s1);
    printf_s("s1=%s, s2=%s\n",s1, s2);
}
