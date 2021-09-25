#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */



List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge( List L1, List L2 )//
{
    List L = (struct Node*)malloc(sizeof(struct Node));
    L->Next = NULL;
    List p;
    List q;
    int flag = 1;
    if(L1->Next==NULL&&L2->Next==NULL)
        {   
            return L;
        }
    if(L1->Next->Data<=L2->Next->Data)
    {
        p = L1->Next;
        q = L2->Next;
    }
    else
        {
        q = L1->Next;
        p = L2->Next;
        flag = 2;
        }

    List temp = NULL;
    while(p->Next!=NULL&&q!=NULL)
    {
        if(p->Data<=q->Data&&p->Next->Data>=q->Data)//插入节点
        {
            temp = q;
            q = q->Next;
            temp->Next=p->Next;
            p->Next = temp;
            p = p->Next;
        }
        else
            {
                p=p->Next;
            }
    }

    if(p->Next==NULL)
    {
        p->Next = q;
    }
    if(flag==1)
    {
    p = L1->Next;
    }
    else
    {
        p = L2->Next;
    }
    List tail = L;
    while(p!=NULL)
    {
        List x = (List)malloc(sizeof(struct Node));
        x->Data = p->Data;
        tail->Next = x;
        tail = tail->Next;
        p = p->Next;
    }
    p = L1->Next;
    while(p)
    {
        temp = p;
        p = p->Next;
        free(temp);
    }
    L1->Next = NULL;

    L2->Next = NULL;
    tail->Next = NULL;

    return L;
}