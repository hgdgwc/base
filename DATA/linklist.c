#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct node
{
    /* data */
    ElemType data;
    struct node *Next;
    
}linknode;
typedef struct node *linklist;

linklist InitList(void) 
{
    linklist L = NULL;

    if((L  = (linklist)malloc(sizeof(linklist))) == NULL)
    {
        printf("malloc failed\n");
        //printf("sizeof(seqlist) = %d\n",sizeof(seqlist));
        return NULL;
    }
    else
    {
        L->data = 0;
        L->Next = NULL;


    };
        return L;
}

Status ClearList(linklist L)
{
    linklist s,p;
    s = L;
    if(s)
    {
        p = s;
        free(p);
        s = s->Next;
    }
    return OK;

}
/*初始条件:在链表*/
Status ListInsert(linklist L,int i,int a)
{
    int j;
    linklist p,s;
    p = L;
    j = 1;
    while (p && j < i)
    {
        p = p->Next;
        j++;
        
    }
    if(!p || j > i)
    {
        printf("no location\n");
        return FALSE;
    }
    
    s = (linklist)malloc(sizeof(linknode));
    if(s == NULL)
    {
        printf("malloc failed\n");
        return ERROR;
    }
    else
    {
        L->data++;
        s->Next = p->Next;
        s->data = a;
        p->Next = s;
    }
    return OK;
}

Status ListDelete(linklist L,int i)
{
    linklist p,s;
    p = L;
    int j = 1;
    while (p && j <i)
    {
        /* code */
        j++;
        p = p->Next;
    }
    if( !(p->Next) || j > i)
    {
        printf("invaild data\n");
        return ERROR;
    }
    else
    {
       L->data--;
       s = p->Next;
       int data = s->data;
       p->Next = s->Next;
       free(s);
       printf("delete data %d\n",data);   
    }

    return OK;
    
    
}


/*int ListLength(linklist L)
{
    return L->length;
}*/

int GetData(linklist L,int i)
{
    int data;
    linklist p,s;
    int j = 1;
    p = L;
    while(p && j < i)
    {
        j++;
        p = p->Next;
    }
    if(!(p->Next) || j > i)
        return ERROR;
    data = p->Next->data;
    printf("data %d\n",data);


    return OK;

}
int main(int argc, char const *argv[])
{
    linklist L = NULL;
    linklist p;
    int data[10] = {10,4,8,7,2,1,9,5,4,3};
    L = InitList();
    p = L;
    for(int i = 1;i <= sizeof(data)/sizeof(int);i++)
    {
        ListInsert(L,i,data[i-1]);
    }
    ListInsert(L,2,data[6]);
    while(p)
    {
        printf("data = %d\n",p->data);
        p = p->Next;
    }

    //printf("*p = %d\n",*p);
    GetData(L,6);

    



    return 0;
}
