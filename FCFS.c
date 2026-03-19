#include<stdio.h>
void main(){
 int n,i,j;
 printf("Enter the number of processes\n");
 scanf("%d",&n);
 int id[n],at[n],bt[n],ct[n],tat[n],wt[n];
 for(i=0;i<n;i++)
 {
 id[i]=i+1;
 printf("Enter arrival time and burst time of Process P%d\n",i+1);
 scanf("%d", &at[i]);
 scanf("%d", &bt[i]);
 }
 for(i=0;i<n-1;i++)
 {
 for(j=0;j<n-i-1;j++)
 {
 if(at[j]>at[j+1])
 {
 int temp=at[j];
 at[j]=at[j+1];
 at[j+1]=temp;

 temp=bt[j];
 bt[j]=bt[j+1];
 bt[j+1]=temp;

 temp=id[j];
 id[j]=id[j+1];
 id[j+1]=temp;
 }
 }
 }
 ct[0]=at[0]+bt[0];
 for(i = 1; i < n; i++)
 {
 if(ct[i-1]<at[i])
 ct[i]=at[i]+bt[i];
 else
 ct[i]=ct[i-1]+bt[i];
 }
 float twt=0,ttat=0;
 for(i=0;i<n;i++)
 {
 tat[i]=ct[i]-at[i];
 wt[i]=tat[i]-bt[i];
 ttat=ttat+tat[i];
 twt=twt+wt[i];
 }
 printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
 for(i=0;i<n;i++)
 {
 printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",id[i],at[i],bt[i],ct[i],tat[i],wt[i]);
 }
 printf("Average Turnaround Time=%f\n",ttat/n);
 printf("Average Waiting Time=%f",twt/n);
}
