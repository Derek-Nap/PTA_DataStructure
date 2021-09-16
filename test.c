#include <stdio.h>
int a[4][5];
int main()
{
    int(*p)[5] = a;
    int m = 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5;j++)
        {
            a[i][j] = m++;
        }
        printf("%d %d %d %d %d", p, p[2]+1, *(p + 1), *(p + 1) + 1,*(*(p + 1) + 1));
        printf("\n%d %d %d %d %d %d", a, *(a + 2)+1, a[0], &a[0], *(a[0] + 1),*(a+1)+1);
}