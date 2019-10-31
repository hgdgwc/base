#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
typedef int ElemData;
typedef struct Bnode {
    ElemData data;
    struct  Bnode *lchild,*rchild;
}Bnode,*Btree;

typedef struct  
{
    Bnode *root;
}Tree;


void PreOrderTraverse(Btree T)
{
    if(T == NULL)
        return ;
    printf("T->data:%d\n",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(Btree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("T->data:%d\n",T->data);
    InOrderTraverse(T->rchild);
}

void Insert(Tree *tree,int value)
{
    Btree node = (Btree)malloc(sizeof(Bnode));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
    if(tree->root == NULL)
        tree->root = node;
    else
    {
        Btree temp = tree->root;
        while (temp != NULL)
        {
            if(value < temp->data)
                {
                    if(temp->lchild == NULL)
                    {
                        temp->lchild = node;
                        return;
                    }
                    else
                    {
                        temp = temp->lchild;
                    }
                    
                        
                }
            if(value > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = node;
                    return;
                }
                else
                {
                    temp = temp->rchild;
                }
                
            }
        }
        
    }
    
}
int main(int argc, char const *argv[])
{
    Tree *tre;
    int m[10] = {2,1,8,7,4,3,6,5,0,9};
    tre->root = NULL;
    for(int i = 0;i < 10;i++)
        Insert(tre,m[i]);
    InOrderTraverse(tre->root);
    PreOrderTraverse(tre->root);

    return 0;
}
