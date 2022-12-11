#include<stdio.h>
void findwaiting(int n, int tat[], int bt[], int wt[])
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    printf("wating time:\n");
    for (int i = 0; i < n; i++)
    {
       printf(" %d\t",wt[i]);
    }
    printf("\n");
}
void findcompletion_time(int n, int ct[], int at[], int bt[])
{
    ct[0] = bt[0] + at[0];
    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
            ct[i] = at[i] - ct[i - 1];
        ct[i] += ct[i - 1] + bt[i];
    }
for (int i = 0; i < n; i++)
        printf("%d\t",ct[i]);
        
        printf("\n");
}
void findtat(int n, int at[], int ct[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = ct[i] - at[i];
        
     printf("turn around time:\n");
    for (int i = 0; i < n; i++)
    {
       printf(" %d\t",tat[i]);
    }
    printf("\n");
}
void fcfs(int n, int burst_time[], int arrival_time[])
{
    int wt[n], tat[n];
    int ct[n]  ;
    for(int i = 0 ; i < n ; i++){
        ct[i] = 0 ;
    }
    findcompletion_time(n, ct, arrival_time, burst_time);
    findtat(n, arrival_time, ct, tat);
    findwaiting(n, tat, burst_time, wt);
    double avgwt = 0.0, avgtat = 0.0;
    for (int i = 0; i < n; i++)
    {
        avgwt += wt[i];
        avgtat += tat[i];
    }
    printf("Average waiting time %lf:\n", avgwt/n);
    printf("Average turn around time: %lf\n", avgtat/n );
}
int main()
{
    int arrival_time[] = {0,3 ,6};
    int burst_time [] = {5,9,6};
    int n = 3 ;
    fcfs(n, burst_time, arrival_time);
}