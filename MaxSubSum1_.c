# include <stdio.h>
//算法一，遍历
//10^5数据耗时	3729 ms
int array[100000];
int main ()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0,Maxsum=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n;j++)
        {
            sum += array[j];
            if(Maxsum<sum)
                Maxsum = sum;
        }
    }
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i]>=0)
           {
               flag = 1;
               break;
           }
    }
    if(flag)
        printf("%d", Maxsum);
    else
        printf("0");
    return 0;
}
