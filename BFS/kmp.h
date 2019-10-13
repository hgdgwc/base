#ifndef __KMP__H
#define __KMP__H

#include <stdio.h>
#include <string.h>
int violentmatch(char *s,char *p);
int kmpsearch(char *s,char *p,int next[]);
void GetNext(char *p,int next[]);
#endif