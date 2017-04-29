//§³§Ý§Ú§ä§î §Õ§Ó§Ñ §ã§á§Ú§ã§Ü§Ñ
//§²§Ö§Ñ§Ý§Ú§Ù§à§Ó§Ñ§ä§î §ã§Ó§ñ§Ù§ß§í§Û §ã§á§Ú§ã§à§Ü 



#include<stdio.h>
#include<stdlib.h>
 
typedef struct content
{
    int    content1;
    float  content2;
    struct content *next;
}STUD;
 
STUD *creat()  
{
    STUD *h,*p,*q;
    int i;
 
    h=NULL;
    for(i=1;i<=3;i++)
    {
        p=(STUD*)malloc(sizeof(STUD));
            scanf("%d,%f",&p->content1,&p->content2);
 
        if(h==NULL) 
            h = p;
        else
            q->next=p;
 
        q = p;
    }
    q->next=NULL;
 
    return(h);
}
 
void print(STUD *h)   
{
    printf("\n");
    while(h!=NULL)
    {
        printf("%-5d%-5f\n",h->content1,h->content2);
        h=h->next;
    }
}

STUD *connect(STUD *h1,STUD *h2) 
{   
    STUD *head;
     
    head=h1;
    while(h1->next!=NULL)   
    {
        h1=h1->next;
    }
 
    h1->next=h2; 
 
    return head;   
}
 
int main(void) 
{
    STUD *head1,*head2;
 
    head1=creat(); 
    print(head1);   
 
    head2=creat(); 
 
    print(head2);   
 
    head1=connect(head1,head2); 
 
    print(head1);  
 
    return 0;
}
 
