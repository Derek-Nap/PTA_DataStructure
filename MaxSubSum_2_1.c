# include <stdio.h>
//存在问题
int array[100000];
int main ()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0, Maxsum = 0,first=0, last=0,flag=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int num = 0;
    for (int i = 0; i < n; i++)
    {
            sum += array[i];
            if(sum<0)
                sum = 0;
            else if (Maxsum < sum)
                {
                        Maxsum = sum;
                        last = array[i];
                        first = array[i - num];
                        num++;
                }

    }
    flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i]>=0)
           {
               flag = 1;
               break;
           }
    }
    if(flag)
        printf("%d %d %d", Maxsum,first,last);
    else
        {
        printf("0 %d %d", array[0], array[n-1]);
        }
    return 0;
}
