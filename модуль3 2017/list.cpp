#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef int Datatype;   

typedef struct node {
    Datatype data;
    struct node *next;
}Node;


Node* creatNode(Datatype data) {
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Datatype));    
    if (p == NULL) {    
        return NULL;
    }
    p->data = data;     
    p->next = NULL;
    return p;
}


void printList(Node* head) {
    Node* p = head;
    if (head == NULL) {
        return;
    }
    while(p != NULL) {
        printf("%d\n",p->data);
        p = p->next;
    }
    return;
}

int insertNodeBehind(Node* p,Node* pnew) {
    if (p == NULL || pnew == NULL) {
        return -1;
    }
    if (p->next != NULL) {
        pnew->next = p->next;
        p->next = pnew;
    }
    else {
        p->next = pnew;
    }

    return 0;  
}

//get the size of the array
typedef struct LNode
{
 ElemType data;
 struct LNode *next;
}LinkList;

int ListLength(struct LNode *L)
{
  int i=0;
  LinkList *p = L->next;
  while(p)
  {
    i++;
    p = p->next;
  }
  return i;
}
int insertDataBehind(Node *p,Datatype data) {
    Node* pnew = NULL;
    if (p == NULL) {
        return -1;
    }
    pnew = creatNode(data);
    insertNodeBehind(p,pnew);
    return 0;
}



Node* findListTail(Node* phead) {
    if (phead == NULL) {
        return NULL;
    }
    while (phead->next != NULL) {
        phead = phead->next;
    }
    return phead;
}

//add a new element after the i-th element
Status ListInsert(struct LNode *L,int i,ElemType e)
{
  int j =0;
  struct LNode *p=L,*s=NULL;
  while(p && j<i-1)
  {
    p=p->next;
    j++;
  }
  if(!p || j>i-1)
    return ERROR;
  s = (struct LNode *)malloc(sizeof(struct LNode));
  if(!s)
    printf("malloc error~\n");
  
  s->data = e;
  
   p->next = s->next;
   s->next = p;
  
  return OK;
}


//get the i-th element
Status GetElem(struct LNode *L,int i,ElemType *e)
{
  int j=1;
  LinkList *p = L->next;
  while(p && j<i)
  {
    p = p->next;
    j++;
  }
  if(!p || j>i)
    return ERROR;
  *e = p->data;
  return OK;
}
//add a new one (add to the end of the array)
int listInsertDataAtTail(Node** phead,Datatype data) {
    Node *p = NULL;
    if (phead == NULL) {
        return -1;
    }
    if (*phead == NULL) {
        *phead = creatNode(data);
        return 0;
    }
    p = findListTail(*phead);
    insertDataBehind(p,data);
    return 0;
}

//delete the i-th element
Status ListDelete(LinkList *L,int i,ElemType *e)
{

  LinkList *p=L,*q;

   int j=0;
  while(p->next && j< i-1)
  {
    p = p->next;
    j++;
  }
  if(!p->next || j>i-1)
    return ERROR;
  q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  return OK;
  }

//sort an array(the comparison ...
int LocateElem(struct LNode *L,ElemType e,Status(*compare) (ElemType,ElemType))
{
  int i =0;
  LinkList *p = L->next;
  while(p)
  {
    i++;
    if(compare(p->data,e))
      return i;
    p=p->next;
  }
  return 0;
}
//delete a last one
int deleteNodeBehind(Node* p) {
    Node* temp  = NULL;
    if (p == NULL) {
        return -1;
    }
    if (p->next == NULL) {
        return 1;
    }
    temp = p->next;
    p->next = p->next->next;
    free(temp);
    return 0;
}

//delete all elements
int listDestroy(Node **phead) {
    if (phead == NULL || (*phead) == NULL) {
        return 0;
    }
    while ((*phead)->next != NULL) {
        deleteNodeBehind(*phead);
    }
    (*phead) = NULL;
    free(*phead);   
    return 0;
}



Node* findNode(Node* head,Datatype data) {
    Node* p = NULL;
    if (head == NULL) {
        return NULL;
    }
    p = head;
    while (p->data != data) {
        if (p->next != NULL) {
            p = p->next;
        }
        else {
            return NULL;   
        }
    }
    return p;
}



//set a element
int listChangeData(Node* head,Datatype oldData,Datatype newData) {
    Node* p = NULL;
    if (head == NULL) {
        return -1;
    }
    p = findNode(head, oldData);
    p->data = newData;
    return 0;
}





int main(int argc, const char * argv[]) {

    Node* p = NULL;
    listInsertDataAtTail(&p, 1); 
    printList(p);

    listInsertDataAtTail(&p, 2);
    listInsertDataAtTail(&p, 3);
    listInsertDataAtTail(&p, 4);
    listInsertDataAtTail(&p, 5);

    printf("It has node??1-2-3-4-5\n");
    printList(p);



//  set the element
    printf("change 2 to 20000\n");
    listChangeData(p, 2, 20000);
    printList(p);

    listDestroy(&p);
    printList(p);
    return 0;
}      

