#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct  
{
    /* data */
    int data[MAXSIZE];
    int length;
}seqlist;

seqlist *InitList(void) 
{
    seqlist *L;

    if((L  = (seqlist *)malloc(sizeof(seqlist))) == NULL)
    {
        printf("malloc failed\n");
        //printf("sizeof(seqlist) = %d\n",sizeof(seqlist));
        return NULL;
    }
    else
    {
        L->length = 0;
        printf("sizeof(seqlist) = %d\n",(int)sizeof(seqlist));
        
            /* data */
    };
        return L;

    
    
        
}



Status ClearList(seqlist *L)
{
    L->length = 0;
    free(L);
    return OK;

}

Status ListInsert(seqlist *L,int i,int a)
{
    printf("L->length = %d\n",L->length);
    if(L->length == MAXSIZE) /*线性表满*/
    {
        printf("full list\n");
        return ERROR;

    }
    if( i < 1 || i > MAXSIZE)//插入位置无效
    {
        printf("location is invaild\n");
        return ERROR;
    }

    if(i <= L->length) //要插入的元素不在表尾
    {
        for(int j = L->length - 1;  j >= i - 1;j--)
            L->data[j + 1] = L->data[j];
    }
    L->data[i-1] = a;
    L->length++;
    return OK; 

    

}

Status ListDelete(seqlist *L,int i)
{
    if(L->length == 0)
    {
        printf("empty list\n");
        return ERROR;
    }
    if(i < 1 || i> L->length)
    {
        printf("invaild location\n");
        return ERROR;
    }
    int del_data;
    del_data = L->data[i-1];
    //*e = L->data[i-1];
    for(int j = i - 1;j < L->length - 1;j++)
    {
        L->data[j] = L->data[j+1];
    }
    L->length--;
    printf("delete data %d \n",del_data);
    return OK;
}

int ListLength(seqlist *L)
{
    return L->length;
}

int GetData(seqlist *L,int i)
{
    int data;
    if(i < 1 || i > L->length)
    {
        printf("invaild data\n");
        return ERROR;
    }    
    if(L->length == 0)
    {
        printf("empty list\n");
        return ERROR;
    }

    data = L->data[i-1];
    printf("data = %d\n",data);
    return OK;

}
int main(int argc, char const *argv[])
{
    seqlist *L = NULL;
    int *p = NULL;
    int data[10] = {10,4,8,7,2,1,9,5,4,3};
    L = InitList();
    for(int i = 1;i <= sizeof(data)/sizeof(int);i++)
    {
        ListInsert(L,i,data[i-1]);
    }

    ListDelete(L,5);

    //printf("*p = %d\n",*p);
    GetData(L,6);

    for(int i = 0;i < L->length;i++)
        printf("data[%d] = %d\n",i,L->data[i]);



    return 0;
}
