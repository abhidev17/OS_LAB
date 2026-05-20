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
    for(i = 0; i < processes; i++)
    {
        for(j = 0; j < resources; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < processes; i++)
    {
        for(j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < resources; i++)
    {
        scanf("%d", &avail[i]);
    }

    /* Calculate Need Matrix */
    for(i = 0; i < processes; i++)
    {
        for(j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    /* Initialize finish array */
    for(i = 0; i < processes; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while(count < processes)
    {
        int found = 0;

        for(i = 0; i < processes; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 0;

                for(j = 0; j < resources; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                /* Process can execute */
                if(flag == 0)
                {
                    safeSeq[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;

                    for(k = 0; k < resources; k++)
                    {
                        avail[k] += alloc[i][k];
                    }
                }
            }
        }

        /* No process could be executed */
        if(found == 0)
        {
            printf("\nSystem is NOT in safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\n");
    printf("Safe Sequence is:\n");

    for(i = 0; i < processes; i++)
    {
        printf("P%d ", safeSeq[i]);
    }

    printf("\n");

    return 0;
}