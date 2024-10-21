/**
* brief: 利用 联合体 将 float 在内存中的存储形式进行展开
* Created by lzy on 2024-08-31.
*/
#include <stdio.h>

typedef union CH_FLOAT_U_TAG {
    float f;
    char c[sizeof(float)];
} FLOAT_U;

void print_binary(char c);

int main(int argc, char const *argv[])
{
    int i = 1;
    const char *p = (char *)&i;
    if (*p == 1) {
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }

    FLOAT_U float_u;
    float_u.f = 23.375f;
    /*
     * 23.375 = 16 + 0×(2^3) + 4 + 2 + 1 + 0×(2^-1) + 0.25 + 0.125
     * 23.375 = 1×(2^4) + 0×(2^3) + 1×(2^2) + 1×(2^1) + 1×(2^0) + 0×(2^-1) + 1×(2^-2) + 1×(2^-3)
     *        = 0b10111.011 = (0b1.0111011)×(2^4) = 0b(1 + 0.0111011)×(2^4)
     *        = 0b((-1)^0 + 0.M)×(2^(E-127)) = 0b((-1)^S + 0.M)×(2^(E-127))
     * IEEE 754标准下的单精度浮点数（Single-Precision Floating Point Number）：使用32位(4个字节)来存储一个浮点数。
            1位用于符号位(Sign Bit)S。
            8位用于阶码(Exponent)E，偏移量为127。
            23位用于尾数(Mantissa)M，但实际上可以表示24位的精度，因为最前面的1是隐含的
       浮点数的存储形式为："符号位(S)" + "阶码(E)" + "尾数(M)"。所以 23.375 = 0_10000011_01110110000000000000000
     */

    // windows 是 小端环境，所以需要将逆序打印字节的bit
    // 0100_0001_1011_1011_0000_0000_0000_0000 = 0X41BB0000
    for (i = sizeof(float_u.f) - 1; i >= 0; --i)
    {
        print_binary(float_u.c[i]);
        if (i > 0)
        {
            putchar('_');
        }
    }
    return 0;
}

void print_binary(const char c)
{
    for (int i = 7; i >= 0; i--)
    {
        putchar(c & (1 << i) ? '1' : '0');
        if (i == 4)
        {
            putchar('_');
        }
    }
}