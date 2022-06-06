#include <stdio.h>

long MAX(long a, long b, long c) { return (a > b && a > c) ? a : (b > c ? b : c); }

int main()
{
    int n, m, Test;
    scanf("%d", &Test);
    while (Test--)
    {
        long A[105][105], C[105][105];
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%ld", &A[i][j]);
        for (int j = 1; j <= m; j++)
            C[1][j] = A[1][j];
        for (int i = 1; i <= n; i++)
            C[i][0] = C[i][m + 1] = -1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                C[i][j] = MAX(C[i - 1][j - 1], C[i - 1][j], C[i - 1][j + 1]) + A[i][j];
        long Max = C[n][1];
        for (int j = 1; j <= m; j++)
            if (Max < C[n][j])
                Max = C[n][j];
        printf("%ld\n", Max);
    }
}