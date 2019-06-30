#include <stdio.h>

void buble_sort(int bubble_sort[],int len)
{

    int i,j,temp;
    int *p;
    p = bubble_sort;
    for(i = 0; i < len-1;i++)
    {
        for(j = i;j < len;j++ )
        {
            if(bubble_sort[i] < bubble_sort[j])
                {
                    temp = bubble_sort[j];
                    bubble_sort[j] = bubble_sort[i];
                    bubble_sort[i] = temp; 
                }
        }
    }
}
int main(int argc, char const *argv[])
{
    int bubble_sort[10] = {10,8,45,78,23,21,54,2,78,65};
    buble_sort(bubble_sort,10); 
    for(int i = 0; i < 10;i++)
    printf("bubble_sort[%d] = %d\n",i,bubble_sort[i]);

    return 0;
}


