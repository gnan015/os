#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* thread_function(void* arg)
{
    int n=*(int*)arg;
    for(int i=0;i<=n;i++)
    {
        printf("Thread:%d\n",i);
    }   
    return NULL;
}
int main()
{
    pthread_t t;
    int n=5;
    pthread_create(&t,NULL,thread_function,&n);
    pthread_join(t,NULL);
    for(int i=20;i<=24;i++)
    {
        printf("Main Thread:%d\n",i);
        sleep(0.001);
    }
    return 0;
}