#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void* thread_function(void *arg)
{
    int n=*(int *)arg;
    int *s=malloc(sizeof(int));
    *s=0;
    for(int i=1;i<=n/2;i++)
    {
        *s+=i;
    }
    return s;
}
int main()
{
    int n;
    int *x;
    printf("Enter a number:");
    scanf("%d",&n);
    pthread_t t;
    pthread_create(&t,NULL,thread_function,&n);
    pthread_join(t,(void**)&x);
    for(int i=(n/2)+1;i<=n;i++)
    {
        *x+=i;
    }
    printf("Total Sum:%d\n",*x);
}