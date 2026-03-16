#include <stdio.h>
int main()
{
    int n, i, tq, time = 0, remain;
    int burst[10], remain_bt[10], arrival[10];
    int waiting[10], turnaround[10];
    int complete[10] = {0};
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time for process P%d: ", i+1);
        scanf("%d", &arrival[i]);

        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &burst[i]);

        remain_bt[i] = burst[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    remain = n;
    while(remain > 0)
    {
        for(i = 0; i < n; i++)
        {
            if(arrival[i] <= time && remain_bt[i] > 0)
            {
                if(remain_bt[i] <= tq)
                {
                    time += remain_bt[i];
                    remain_bt[i] = 0;
                    turnaround[i] = time - arrival[i];
                    waiting[i] = turnaround[i] - burst[i];
                    remain--;
                }
                else
                {
                    remain_bt[i] -= tq;
                    time += tq;
                }
            }
        }
        time++;
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++)
    {
        avg_wt += waiting[i];
        avg_tat += turnaround[i];

        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
    return 0;
}
