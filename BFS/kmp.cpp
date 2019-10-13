#include "kmp.h"
#include <string.h>
int violentmatch(char *s,char *p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);

    int i = 0;
    int j = 0;
    while(i < sLen && j < pLen)  
    {
        if(s[i] == p[j]) /*若当前字符相等，则比较下一个*/
        {
            i++;
            j++;
        }
        else /*如果不等，字符串向后移动一个单位，模式串回溯*/
        {
            i = i - j + 1;
            j = 0;
        }
        
    } 
    if(j == pLen)   /*比较成功，返回模式串在字符串中的首地址*/
        return i - j;
    else
        {
            return -1;
        }
}

int kmpsearch(char *s,char *p,int next[])
{
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0;
    int j = 0;
    while(i < sLen && j < pLen)
    {
        if(j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];  
        }
        
    }
    if(j == pLen)
        return i-j;
    else
    {
        return -1;
    }
    
        
}

void GetNext(char *p,int next[])
{
    int Len = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < Len -1)
    {
    if(k == -1 || p[j] == p[k])
    {
        ++k;
        ++j;
        if(p[j] != p[k])
        {
            next[j] = k;
        }
        else
        {
            next[j] = next[k];
        }
            
    }
    else
    {
        k = next[k];
    }
    }
    
}

