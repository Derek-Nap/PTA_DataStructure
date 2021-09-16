#include<stdio.h>
#define MaxSize 1000
int a[MaxSize];
int b[MaxSize][MaxSize];
int Top;

int push(int m , int M)
{   
    if(Top>=M)
        return 0;
    a[Top++] = m;//Top指向前一个空位置
    return 1;
}

int pop()
{
    int m;
    if(Top<0)
        return 0;
    m = a[--Top];
    a[Top] = 0;
    return m;
}

int main()
{

    int M, N, K;//M为栈最大容量，N为要入栈的数长度，K为要测试的序列数
    scanf("%d%d%d", &M, &N, &K);
    for (int k = 0; k < K;k++)
    {
        for (int j = 0; j < N;j++)
            scanf("%d", &b[k][j]);
        
    }

    for (int k = 0; k < K;k++)//判断单个序列，共K个
    {
        int flag = 1;//标记是否满足条件。默认满足。
        int hadpopmax = 0;//记录上一次已经入栈的最大值
        for (int j = 0; j < N;j++)//对序列模拟入栈出栈
        {
            
            if(hadpopmax<b[k][j])//当序列里面的当前值大于之前最大数时，压栈。不取等号，因为题目给出的数据应满足数值正常。
            {
                for (int i =hadpopmax+1; i <= b[k][j];i++)
                {
                if(push(i,M))//压栈成功，即栈未溢出.
                {
                    hadpopmax = b[k][j];//更新最大元素
                }
                else//栈溢出，则不满足。
                   {
                       flag = 0;
                       break;
                   }
                }
                pop();
            }
            else//当序列里面的当前值小于之前最大数时
                {
                    if(b[k][j]==pop())
                        ;
                    else
                        {flag = 0;
                            break;
                        }
                }


        }
        if(!k)//第个序列
        {   
            if(!flag)
                printf("NO");
            else
                printf("YES");
        }
        else
        {
            if(!flag)
                printf("\nNO");
            else
                printf("\nYES");
        }

        for (int i = 0; i < Top;i++)
        {
            a[i] = 0;
        }
        Top = 0;
    }


}