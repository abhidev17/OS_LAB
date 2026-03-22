#include<stdio.h>

int main()
{
    int n,i,j;
    int at[10],bt[10],pr[10],ct[10],wt[10],tat[10],p[10];
    int temp,time=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process %d:\n",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for Process %d:\n",i+1);
        scanf("%d",&bt[i]);
        printf("Enter priority for Process %d:\n",i+1);
        scanf("%d",&pr[i]);

        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=at[i]; at[i]=at[j]; at[j]=temp;
                temp=p[i]; p[i]=p[j]; p[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(time<at[i])
            time=at[i];

        time+=bt[i];
        ct[i]=time;

        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);

         float avgwt=0,avgtat=0;

    for(i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f\n",avgtat/n);


    printf("\nGANTT CHART\n");

     for(i=0;i<n;i++){
        printf("   P%d ",p[i]);
        }
        printf("\n");
 printf("0 ");
        for(i=0;i<n;i++){
        
   printf("     %d",ct[i]);
}
}

