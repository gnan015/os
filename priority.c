#include<stdio.h>
struct pro
{
    int visited;
    int pid,wt,pri,rt,ct,tat,at,bt;
};

int main()
{
    int n;
    printf("Enter no of processes\n");
    scanf("%d",&n);
    struct pro p[n];
    for(int i=0;i<n;i++)
    {
        p[i].visited=0;
        p[i].pid=i;
        printf("Enter the arrival time of process %d\n",i);
        scanf("%d",&p[i].at);
        printf("Enter the burst time of process %d\n",i);
        scanf("%d",&p[i].bt);
        printf("Enter the priority of process %d\n",i);
        scanf("%d",&p[i].pri);
    }

    printf("Pid\tAt\tBt\tPri\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt,p[i].pri);
        printf("\n");
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(p[j].pri>p[j+1].pri)
            {
                struct pro temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
        printf("Pid\tAt\tBt\tPri\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt,p[i].pri);
        printf("\n");
    }

    int total_ct=0;
    float waiting_time=0.0,total_tat=0.0;
    for(int i=0;i<n;i++)
    {
        if(p[i].at<=total_ct&&!p[i].visited)
        {
        p[i].rt=total_ct;
        total_ct+=p[i].bt;
        p[i].ct=total_ct;
        p[i].visited=1;
        i=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        total_tat+=p[i].tat;
        p[i].wt=p[i].rt-p[i].at;
        waiting_time+=p[i].wt;
        }
    printf("Pid\tWt\tTat\tCt\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t", p[i].pid , p[i].wt , p[i].tat , p[i].ct);
        printf("\n");
    }
    printf("Average Waiting time:%f\n",(float)(waiting_time/n));
    printf("Average Turn Around Time:%f\n",(float)(total_tat/n));
}