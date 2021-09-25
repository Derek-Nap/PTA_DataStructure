//给定两个有序链表，对其合并，并重新排序。
//由于原来的链表就有序，不需重新排序所有节点，只需把第二个链表的节点插入到合适的地方。时间复杂度为O(n).


# include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;

    struct Node * Next;
};

typedef struct Node * List;

List creat_list(List head1,List tail1)
{
    int a = 0;
    scanf("%d", &a);
    while(a!=-1)
    {
        List p = (List)malloc(sizeof(struct Node));
        p->Data = a;
        tail1->Next = p;
        tail1 = p;
        scanf("%d", &a);
    }
    tail1->Next = NULL;

    return head1;
}



void PrintList(List head)
{
    List p = head->Next;
    if(p!=NULL)
    {
        printf("%d", p->Data);
        p = p->Next;
    }
    while(p!=NULL)
    {
        printf(" %d", p->Data);
        p = p->Next;
    }
}

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



int main ()
{
    List head1,tail1,head2,tail2;
    head1= (List )malloc(sizeof(struct Node));
    head2= (List )malloc(sizeof(struct Node));
    tail1 = head1;
    tail2 = head2;
    head1=creat_list(head1, tail1);
    head2 = creat_list(head2, tail2);
    PrintList(Merge(head1, head2));
    return 0;
}