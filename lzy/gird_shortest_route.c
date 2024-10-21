/**
* brief:
* Created by lzy on 2024-10-20.
*/
#include <stdio.h>

#define MAX 100

/**
 * 3*4 表格，左上角到右下角的最短路径走法数量
 * C(3+4,3) = (7!)/(4!*3!) = 7*6*5/3*2*1 = 35
 * A(3+4,4) = (7!)/((7-4)!) = 7*6*5*4=840
 */
int f0_0(const int m, const int n)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }

    int factorial = 1;
    int m_f=0;
    int n_f=0;
    for (int i = 1; i <= m+n; i++)
    {
        factorial *= i;
        if (i == m)
        {
            m_f = factorial;
        }
        if (i == n)
        {
            n_f = factorial;
        }
    }
    return factorial / (m_f * n_f);
}

int f0_1(const int m, const int n)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }
    int big = m;
    int small = n;
    if (n>m)
    {
        big = n;
        small = m;
    }

    int numerator = 1;
    int denominator = 1;
    for (int i = n+m; i > big; --i)
    {
        numerator *= i;
    }
    for (int i = 1; i <= small; ++i)
    {
        denominator *= i;
    }
    return numerator / denominator;
}

/**
 * 递归的的方式实现分治，和走楼梯类似
 * 走楼梯：可以看做是走步长为1和2的走法，然后求和。f(n) = f(n-1) + f(n-2);
 * 田字格：左边一个点和上面一个点的路径数之和，即f(m,n) = f(m-1,n) + f(m,n-1);
 */
int f1_0(int m, int n)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0 && n == 0)
    {
        return 1;
    }
    return f1_0(m-1, n) + f1_0(m, n-1);
}

/**
 * 递归 + cache。实现类似dp的效果，减少额外计算
 */
static int cache[MAX][MAX] = {0};
int f1_1(int m, int n)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (cache[m][n] != 0)
    {
        return cache[m][n];
    }
    cache[m][n] = f1_1(m-1, n) + f1_1(m, n-1);
    return cache[m][n];
}

/**
 * 动态规划实现
 */
static int dp[MAX][MAX] = {0};
int f_dp(int m, int n)
{
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main(int argc, char** argv)
{
    const int m = 3;
    const int n = 4;
    printf("f0_0(%d, %d)=%d\n", m, n, f0_0(m,n));
    printf("f0_1(%d, %d)=%d\n", m, n, f0_1(m,n));
    printf("f1_0(%d, %d)=%d\n", m, n, f1_0(m,n));
    printf("f1_1(%d, %d)=%d\n", 15, 15, f1_1(15,15));
    printf("f_dp(%d, %d)=%d\n", 15, 15, f_dp(15,15));
    return 0;
}