#include<stdio.h>

int main()
{
    int n,i,time=0,count=0;
    int at[10],bt[10],ct[10],wt[10],tat[10],p[10];
    int completed[10]={0};
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process %d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter burst time for Process %d: ",i+1);
        scanf("%d",&bt[i]);

        p[i]=i+1;
    }

    int gantt[20], gtime[20], gindex=0;

    while(count < n)
    {
        int idx = -1;
        int min_bt = 9999;

        // find shortest job among arrived processes
        for(i=0;i<n;i++)
        {
            if(at[i] <= time && completed[i]==0)
            {
                if(bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        // if no process has arrived yet
        if(idx == -1)
        {
            time++;
            continue;
        }

        // store Gantt chart
        gantt[gindex] = idx;
        gtime[gindex] = time;
        gindex++;

        time += bt[idx];
        ct[idx] = time;

        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        avgwt += wt[idx];
        avgtat += tat[idx];

        completed[idx] = 1;
        count++;
    }

    gtime[gindex] = time;

    // 🔹 Output Table
    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],wt[i],tat[i]);

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f\n",avgtat/n);

    // 🔹 Gantt Chart
    printf("\n---------GANTT CHART---------\n");

    for(i=0;i<gindex;i++)
        printf("| P%d ", gantt[i]+1);
    printf("|\n");

    for(i=0;i<=gindex;i++)
        printf("%d   ", gtime[i]);

    printf("\n");

    return 0;
}