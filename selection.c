#include <stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int sel[],int len)
{
    int i,j,min;
    
    for(int i = 0;i < len - 1;i++)
    {
        min = i;
        for(int j = i+1;j < len;j++)
        {
            if(sel[i] > sel[j])
                min = j;
        }
        swap(&sel[i],&sel[min]);   
    }
    
}
int main(int argc, char const *argv[])
{
    int a[7] = {10,78,5,65,23,10,98};
    for(int i = 0;i<7;i++)
        printf("a[%d] = %d\n",i,a[i]);
    selection_sort(a,7);
    for(int i = 0;i < (sizeof(a)/4);i++)
        printf("a[%d] = %d\n",i,a[i]);
    return 0;
}
