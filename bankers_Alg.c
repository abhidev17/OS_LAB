#include <stdio.h>

int main()
{
    int processes, resources, i, j, k;
    
    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter number of resources: ");
    scanf("%d", &resources);

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10], safeSeq[10];

    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<processes;i++)
        for(j=0;j<resources;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter Max Matrix:\n");
    for(i=0;i<processes;i++)
        for(j=0;j<resources;j++)
            scanf("%d",&max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(i=0;i<resources;i++)
        scanf("%d",&avail[i]);

    for(i=0;i<processes;i++)
        finish[i] = 0;

    for(i=0;i<processes;i++)
        for(j=0;j<resources;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;

    while(count < processes)
    {
        for(i=0;i<processes;i++)
        {
            if(finish[i] == 0)
            {
                int flag = 0;

                for(j=0;j<resources;j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    safeSeq[count++] = i;
                    finish[i] = 1;

                    for(k=0;k<resources;k++)
                        avail[k] += alloc[i][k];
                }
            }
        }
    }

    printf("\nSafe Sequence is:\n");

    for(i=0;i<processes;i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}