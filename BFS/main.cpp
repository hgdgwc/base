#include "kmp.h"

int main(int argc, char const *argv[])
{
    char s[20] = "ABCDABE";
    char p[10] = "ABABE";
    int next[10];
    printf("pos1 = %d\n",violentmatch(s,p));
    GetNext(p,next);
    for(int i = 0; i < strlen(p);i++)
        printf("next[%d] = %d\n",i,next[i]);
    printf("pos2 = %d\n",kmpsearch(s,p,next));
    
    return 0;
}
