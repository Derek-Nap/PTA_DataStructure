
# include <stdio.h>
#include <stdlib.h>
struct List
{
    int expon;//指数
    int coef;//系数

    struct List *next;
};

void AttachNode(int c,int e,struct List **tail)
{
         struct List *p = (struct List *)malloc(sizeof(struct List));
         p->expon = e;
         p->coef = c;
         p->next = NULL;
         (*tail)->next = p;
         *tail = p;
}


void creat_list(struct List*tail1)//创建链表
{
    int a = 0;
    int c = 0, e = 0;
    scanf("%d", &a);
    while(a--)
    {
        scanf("%d %d", &c, &e);
        AttachNode(c, e, &tail1);
    }
}





void PrintList(struct List*head)
{
    struct List *p = head->next;
    int flag = 0;
    if(p!=NULL)
    {
        if(p->coef)//合并同类项
        {printf("%d %d", p->coef,p->expon);
            flag = 1;
        }
        p = p->next;
    }
    while(p!=NULL)
    {   if(p->coef)
        {printf(" %d %d", p->coef,p->expon);
        flag = 2;}
        p = p->next;
    }
    if(!flag)
    {
        printf("0 0");
    }
}

struct List *Add(struct List *head1,struct List*head2)//
{
    struct List*p=head1->next;
    struct List *q = head2->next;
    struct List *head = (struct List *)malloc(sizeof(struct List));
    head->next = NULL;
    struct List *tail = head;


    while(p)
    {
        AttachNode(p->coef, p->expon, &tail);
        p = p->next;
    }
    
    struct List*p0=head->next;
    while(p0->next&&q)
    {

        if(p0->expon>q->expon&&p0->next->expon<q->expon)
        {
            struct List *temp = (struct List *)malloc(sizeof(struct List));
            temp->coef = q->coef;
            temp->expon = q->expon;
            temp->next=p0->next ;
            p0->next = temp;

            p0 = p0->next;
            q = q->next;
        }

        else if(p0->expon==q->expon)
        {
            p0->coef += q->coef;
            q = q->next;
            
        }

        else
        {
            p0 = p0->next;
        }
    }

    

    if(!p0->next)
    {   
        if(p0->expon==q->expon)
        {
            p0->coef += q->coef;
            q = q->next;
        }
        while(q)
        {
        AttachNode(q->coef, q->expon, &tail);
        q = q->next;
        }

    }

    return head;


}


struct List *Multiply(struct List *head1,struct List*head2)
{
    struct List*p=head1->next;
    struct List *q = head2->next;
    struct List *head = (struct List *)malloc(sizeof(struct List));
    head->next = NULL;
    struct List *tail = head;
    

    while(p)//用q的当前项乘以p的每一项得到p0，temp0，插入temp0到p0中
    {
        AttachNode(p->coef*q->coef, p->expon+q->expon, &tail);
        p = p->next;
    }
    q = q->next;
    struct List*p0=head->next;


    struct List *temphead = (struct List *)malloc(sizeof(struct List));
    temphead->next = NULL;
    struct List *temptail = temphead;
    struct List*tempp0=NULL;

    p = head1->next;
    while (p&&q)
    {
        AttachNode(p->coef * q->coef, p->expon + q->expon, &temptail);
        p = p->next;
    }
    //q = q->next;
    int k = 0;
    while(q)//把temp插入p0
{   


    p=head1->next;
    tempp0 = temphead->next;
    p0 =head->next;
    while(p&&k)
    {
        tempp0->coef = p->coef * q->coef;
        tempp0->expon = p->expon + q->expon;
        tempp0=tempp0->next;
        p = p->next;
    }
    tempp0 = temphead->next;
    while(p0->next&&tempp0)
    {

        if(p0->expon>tempp0->expon&&p0->next->expon<tempp0->expon)
        {
            struct List *temp = (struct List *)malloc(sizeof(struct List));
            temp->coef = tempp0->coef;
            temp->expon = tempp0->expon;
            temp->next=p0->next ;
            p0->next = temp;

            ////////
            p0 = p0->next;

            tempp0 = tempp0->next;
        }

        else if(p0->expon==tempp0->expon)
        {
            p0->coef += tempp0->coef;
            tempp0 = tempp0->next;

        }

        else
        {
            p0 = p0->next;
        }
    }

    if(!p0->next)//如果p0结束，
    {
        if(p0->expon==tempp0->expon)
        {
            p0->coef += tempp0->coef;
            tempp0 = tempp0->next;
        }
        while(tempp0)
        {
        AttachNode(tempp0->coef, tempp0->expon, &tail);
        tempp0 = tempp0->next;
        }

    }
    k++;
    q = q->next;
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
    head1->next = NULL;
    head2->next = NULL;

    creat_list(tail1);
    creat_list(tail2);
    if(!head1->next&&!head2->next)
        printf("0 0");
    else if(!head1->next)
    {
        printf("0 0\n");
        PrintList(head2);
    }

    else if(!head2->next)
    {
        printf("0 0\n");
        PrintList(head1);
    }
    else
    {
        struct List *head0 = NULL;
    if(head1->next->expon<head2->next->expon)
    {
        head0 = head1;
        head1 = head2;
        head2 = head0;
    }
    PrintList(Multiply(head1, head2));
    printf("\n");
    PrintList(Add(head1,head2));//相加可能得到零多项式
    }


    return 0;
}