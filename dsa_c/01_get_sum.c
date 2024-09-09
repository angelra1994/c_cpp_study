/**
* brief:
* Created by lzy on 2024-09-05.
*/
#include <stdio.h>
#include <time.h>
#define max 100000000

long get_sum_1(int n);
long get_sum_2(int n);

int main(int argc, char** argv)
{
    long sum = 0;
    for (int i = 0; i <= 100; ++i)
    {
        sum += i;
    }
    printf("%ld\n", sum);
    clock_t start_time = clock();
    sum = get_sum_1(max);
    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("sum=%ld, get_sum_1 use %fs\n", sum, cpu_time_used);

    start_time = clock();
    sum = get_sum_2(max);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("sum=%ld, get_sum_2 use %fs\n", sum, cpu_time_used);
}

long get_sum_1(const int n)
{
    long sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        sum += i;
    }
    return sum;
}

long get_sum_2(const int n)
{
    return n * (1 + n) / 2;
}
