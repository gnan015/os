#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
void* thread_function(void* args)
{
    int n=*(int*)args;
    int *s=malloc(sizeof(int));
    *s=1;
    for(int i=1;i<=n;i++)
    {
        *s*=i;
    }
    return s;
}
int main()
{
    int *result;
    int n;
    pthread_t t;
    printf("Enter a value");
    scanf("%d",&n);
    pid_t ch1;
    ch1=fork();
    if(ch1<0)
    {
        printf("Error creating the child\n");
        exit(1);
    }
    else if(ch1==0)
    {

        for(int i=1;i<=n;i+=2)
        printf("Odd:%d\n",i);
    }
    else
    {
        for(int i=0;i<=n;i+=2)
        printf("Even:%d\n",i);

        pthread_create(&t,NULL,thread_function,&n);
        pthread_join(t,(void**)&result);
        printf("Factorial : %d\n",*result);
    }
}