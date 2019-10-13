#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *pthread_1(void *arg)
{
    printf("thread_1\n");
}

void *pthread_2(void *arg)
{
    printf("thread_2\n");
}
int main(int argc, char const *argv[])
{
    pthread_t pid[2];
    pthread_create(&pid[0],NULL,pthread_1,NULL);
    pthread_create(&pid[1],NULL,pthread_2,NULL);

    pthread_join(pid[0],NULL);
    pthread_join(pid[1],NULL);   
    return 0;
}
