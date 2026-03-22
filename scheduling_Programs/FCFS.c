#include<stdio.h>

int main()
{
    int n,i,j;
    int at[10],bt[10],ct[10],wt[10],tat[10];
    int time=0,temp;

    printf("Enter number of processes :  ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Process %d Arrival Time: ",i+1);
        scanf("%d",&at[i]);

        printf("Process %d Burst Time: ",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                 temp=at[i];
                 at[i]=at[j];
                 at[j]=temp;

                temp=bt[i]; 
                bt[i]=bt[j]; 
                bt[j]=temp;
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

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);

    float avgwt=0,avgtat=0;

    for(i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f\n",avgtat/n);

    printf("\n------Gantt Chart------\n");


    
 for(i=0;i<n;i++){
        printf("   P%d ",i+1);
        }
        printf("\n");
 printf("0 ");
        for(i=0;i<n;i++){
        
   printf("     %d",ct[i]);
}
   
}
