#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* print_even(void *arg)
{
    int n=*(int*)arg;
    for(int i=0;i<=n;i+=2)
    {
        printf("Even : %d\n",i);
        sleep(0.001);
    }
    return NULL;
}
int main()
{
    int n,x;
    printf("Enter n value");
    scanf("%d",&n);
    pthread_t p;
    pthread_create(&p,NULL,print_even,&n);
    // pthread_join(p,NULL);
    for(int i=1;i<=n;i+=2)
    {
    printf("Odd : %d\n",i);
    sleep(0.001);
}
}