//给定两个有序链表，对其合并，并重新排序。
//由于原来的链表就有序，不需重新排序所有节点，只需把第二个链表的节点插入到合适的地方。时间复杂度为O(n).


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

struct List *SortAndCombine(struct List *head1,struct List*head2)//将head2中节点有序插入head1中
{
    struct List*p=head1->next;
    struct List *q = head2->next;
    struct List *temp = NULL;
    while(p->next!=NULL&&q!=NULL)
    {
        if(p->data<=q->data&&p->next->data>=q->data)//插入节点
        {
            temp = q;
            q = q->next;
            temp->next=p->next;
            p->next = temp;
            p = p->next;
        }
        else
            {
                p=p->next;
            }
    }

    if(p->next==NULL)
    {
        p->next = q;
    }

    return head1;
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
        PrintList(head2);
    else if(head2->next==NULL&&head1->next!=NULL)
        PrintList(head1);
    else if(head1->next==NULL&&head2->next==NULL)
        printf("NULL");
    else
        {
            struct List *head0 = NULL;
            if(head1->next->data>head2->next->data)
                {
                    head0 = head1;
                    head1 = head2;
                    head2 = head0;
                }
            PrintList(SortAndCombine(head1, head2));
        }
    return 0;
}