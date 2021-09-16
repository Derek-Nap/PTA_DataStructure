# include <stdio.h>

int array[100000];
int main ()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0, Maxsum = -1,tempfirstindex=0,firstindex=0, lastindex=n-1,flag=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }


    for (int i = 0; i < n; i++)
    {
            sum += array[i];
            if(sum<0)
                {sum = 0;
                    tempfirstindex =i+ 1;
                }
            else if (Maxsum < sum)
                {
                        Maxsum = sum;
                        lastindex = i;
                        firstindex = tempfirstindex;
                }
            /* else if(Maxsum<=sum&&array[i]==0)   //题目规定只记录一个和最大的子序列。末位为零相当于第二个和最大。
                lastindex = i; */
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
        printf("%d %d %d", Maxsum,array[firstindex],array[lastindex]);
    else
        {
        printf("0 %d %d", array[0], array[n-1]);
        }
    return 0;
}
