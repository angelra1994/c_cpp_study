/**
* brief:
* Created by lzy on 2024-10-20.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define MAX_COL 5
#define MAX_ROW 4

#define N 8

/**
* 从点 (x,y) 到 点 (m,n) 有多少种走法
*/
bool visited[MAX_COL][MAX_ROW] = {0};
int step_dfs(int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x > MAX_COL || y > MAX_ROW) {
        return 0;  // dead end (出界了)
    }

    if(x == m && y == n) {
       return 1;  // found it (找到了一个抵达目标的走法)
    }

    // if(is_block(x, y)) { // (2, 2) 不让走
    //    return 0;  // block here (不让走)
    // }

    if(visited[x][y]) {
       return 0;  // been here (已经走过了)
    }
    visited[x][y] = true;
    int sum = 0;
    sum += step_dfs(x + 1, y, m, n);  // go right
    sum += step_dfs(x, y + 1, m, n);  // go down
    sum += step_dfs(x - 1, y, m, n);  // go left
    sum += step_dfs(x, y - 1, m, n);  // go up

    visited[x][y] = false;
    return sum;
}

void print_queen(int *queens) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (queens[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool is_safe(int* q_pos, int row, int col)
{
    for (int i = 0; i < row; i++) {
        if (q_pos[i] == col || abs(q_pos[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}



/**
 * N皇后。用长度为N的一维数组 queens，记录皇后的位置。queens[i]的值表示第i行的皇后所在的列。
 */
int n_queen(int *q_pos, int row)
{
    int static sum = 0;
    if (row == N) {
        return 1;
    }
    for (int i = 0; i < N; ++i)
    {
        if (is_safe(q_pos, row, i)) {
            q_pos[row] = i;
            sum += n_queen(q_pos, row + 1);
        }
    }
    return sum;
}

int main(int argc, char** argv)
{
    const int m = 3;
    const int n = 4;

    // visited[2][2] = true;
    printf_s("%d\n", step_dfs(4, 4, 5, 4));

    int q_pos[N];
    int sum = n_queen(q_pos, 0);
    if (sum)
    {
        print_queen(q_pos);
    }
    return 0;
}