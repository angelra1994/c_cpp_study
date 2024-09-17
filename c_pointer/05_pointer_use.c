/**
* brief:
* Created by lzy on 2024-09-17.
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * 1. 输入任意字符串，吧所有小写字母转换成大写字母 (输入 "ABcdEf" 输出 "ABCDEF")
 * 2. 去除字符串中的空格 (输入 "ABc  dE f" 输出"ABcdEf")
 * 3. 判断字符串是不是回文 (输入 "abcxcba" 输出 "是")
 * 4. 给定字符串A和B，输出A和B的最大公共字串 (A="ABC123456FF" B="jjk123456hi"  输出"123456")
 * 5. 字符串单词倒置 (输入 "I am a student" 输出 "student am I")
 * 6. 输入一个字符串，同时输入帧头head和帧尾tail，将字符串中合法数据帧识别出来 (输入 "aaheadabctailcc" 输出 "headabctail")
 * 7. 找出字符串中第一个不重复的字符 (输入 "google" 输出 "l")
 * 8. 向左旋转字符串 (输入 "XYZabcdef" 输出 "abcdefXYZ" 向左移动三位，左边移出的放在末尾)
 */

void remove_space(char* s);

int main(int argc, char* argv[])
{
    // char* str;
    // scanf("%s", str);           // 此处会出现段错误，char* str 未初始化，str是野指针

    char* str = (char*)malloc(128);
    // scanf_s("%s", str);      // 遇到 空格 就结束扫描
    // scanf_s("%[^\n]", str);  // 遇到'\n'结束，遇到空格不结束
    // gets(str);               // 遇到'\n'结束，遇到空格不结束，但是非安全函数
    // fgets(str, 128, stdin);  // 可以有效地避免缓冲区溢出的问题，提高程序的安全性
    char ch;
    int i = 0;
    char* p = str;
    while ((ch = getchar()) != '\n')
    {
        // *(str+ i++) = ch;
        *p++ = ch; //  *str++ = ch 会导致str指向发生变化
    }

    printf_s("before remove space, %s\n", str);
    p = str;
    while (*str != '\0')
    {
        if (*str == ' ')
        {
            remove_space(str);
        }
        else
        {
            str++;
        }
    }
    printf_s("after remove space, %s\n", p);
    free(p);
    p = NULL;
    free(str);
    str = NULL;
    return 0;
}

void remove_space(char* s)
{
    while (*s != '\0')
    {
        *s = *(s + 1);
        s++;
    }
}
