#include <stdio.h>

int main()
{
    int n, tq;
    int at[10], bt[10], rt[10];
    int ct[10], wt[10], tat[10];
    int i, time = 0, remain, flag = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                if(rt[i] <= tq)
                {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    remain--;
                }
                else
                {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    printf("Process  AT  BT  CT  WT  TAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d      %d   %d   %d   %d   %d\n",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avg_wt/n);
    printf("Average TAT = %.2f\n", avg_tat/n);

    printf("\n\nGANTT CHART\n");
    printf("%d ", 0);

    time = 0;
    remain = n;
    for(i = 0; i < n; i++)
        rt[i] = bt[i];

    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                if(rt[i] <= tq)
                {
                    time += rt[i];
                    rt[i] = 0;

                    printf("|P%d| %d ", i+1, time);

                    remain--;
                }
                else
                {
                    time += tq;
                    rt[i] -= tq;

                    printf("|P%d| %d ", i+1, time);
                }
            }
        }
    }

    printf("\n");
    return 0;
}`