#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void* thread_function(void *arg)
{
    int n = *(int*)arg;
    int *s = malloc(sizeof(int)); 
    *s = 1;

    for(int i = 1; i <= n; i++)
    {
        *s *= i;
    }

    return s;  
}

int main()
{
    int n;
    int *x;  
    printf("Enter n value: ");
    scanf("%d",&n);
    pthread_t p;
    pthread_create(&p,NULL,thread_function,&n);
    pthread_join(p,(void**)&x);   
    printf("Factorial : %d\n",*x);
    free(x); 
}