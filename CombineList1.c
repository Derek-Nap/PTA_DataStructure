//给定两个有序链表，对其合并，并重新排序。
//我这里未注意原来的链表就是有序的，使用冒泡法排序了整个链表。时间复杂度为O(n^2),大规模超时。


# include <stdio.h>
#include <stdlib.h>
struct List
{
    int data;

    struct List *next;
};


struct List * creat_list(struct List * head1,struct List*tail1)
{
    int a = 0;
    scanf("%d", &a);
    while(a!=-1)
    {
        struct List *p = (struct List *)malloc(sizeof(struct List));
        p->data = a;
        tail1->next = p;
        tail1 = p;
        scanf("%d", &a);
    }
    tail1->next = NULL;

    return head1;
}

struct List* CombineList(struct List*head1,struct List*head2)
{
    struct List *p = head1->next;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = head2->next;
    return head1;
}

void PrintList(struct List*head)
{
    struct List *p = head->next;
    if(p!=NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    while(p!=NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
}

struct List * sort(struct List*head)
{
    struct List *p = head->next;
    struct List *q = p->next;
    struct List *o = head;//O是前驱节点
    int flag = 1;
    while(flag)
    {   
        p = head->next;//每把一个最大的节点排序完，就要重新初始化指针。
        q = p->next;
        o = head;
        flag = 0;
        while(q!=NULL)
        {
        if(p->data>q->data)
            {
                p->next = q->next;
                q->next = p;
                o->next = q;
                p = o->next;
                q = p->next;
                flag = 1;
            }
            p = p->next;
            q = q->next;
            o = o->next;
        }
    }
    return head;
}

int main ()
{
    struct List *head1,*tail1,*head2,*tail2;
    head1= (struct List *)malloc(sizeof(struct List));
    head2= (struct List *)malloc(sizeof(struct List));
    tail1 = head1;
    tail2 = head2;
    head1=creat_list(head1, tail1);
    head2 = creat_list(head2, tail2);
    if(head1->next==NULL&&head2->next!=NULL)
        PrintList(sort(head2));
    else if(head2->next==NULL&&head1->next!=NULL)
        PrintList(sort(head1));
    else if(head1->next==NULL&&head2->next==NULL)
        printf("NULL");
    else
        {
            head1 = CombineList(head1, head2);
            PrintList(sort(head1));
        }

    return 0;
}