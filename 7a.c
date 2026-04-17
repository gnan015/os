#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* thread_function(void* arg)
{
    //int n=*(int*)arg;
    for(int i=0;i<=4;i++)
    {
        printf("Thread:%d\n",i);
        // sleep(0.001);
    }
return NULL;
}
int main()
{
pthread_t t;
pthread_create(&t,NULL,thread_function,NULL);
for(int i=20;i<=24;i++)
{
        sleep(0.001);
    printf("Main Process:%d\n",i);

}
pthread_join(t,NULL);
}