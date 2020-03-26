#include<stdio.h>
int arrivalTime1[30],arrivalTime2[30],arrivalTime3[30];
int burstTime1[30],burstTime2[30],burstTime3[30];
int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;
int time_quantum1,time_quantum2;
int total,x,temp[30],counter=0;
float avtWaitingTime1=0.0,avgTurnaroundTime1=0.0;
void roundRobin()
{
	printf("Enter Time Quantum for Queue1:"); 
    scanf("%d",&time_quantum2);
	for(i=0;i<j;i++)
	{
		temp[i]=burstTime1[i];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(i=0,total=0;x!=0;) 
    { 
    	if(temp[i]<=time_quantum2&&temp[i]>0) 
        { 
            total=total+temp[i]; 
            temp[i]=0; 
            counter=1; 
        } 
        else if(temp[i]>0) 
        { 
            temp[i]=temp[i]-time_quantum2; 
            total=total+time_quantum2; 
        } 
        if(temp[i]==0&&counter==1) 
        { 
            x--; 
            printf("\nProcess[%d]\t%d\t%d\t%d",i+1,burstTime1[i],total-arrivalTime1[i],total-arrivalTime1[i]-burstTime1[i]);
            avtWaitingTime1=avtWaitingTime1+total-arrivalTime1[i]-burstTime1[i]; 
            avgTurnaroundTime1=avgTurnaroundTime1+total-arrivalTime1[i]; 
            counter = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(arrivalTime1[i+1]<=total) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
    avtWaitingTime1=avtWaitingTime1/j;
    avgTurnaroundTime1=avgTurnaroundTime1/j;
    printf("\nAverage Waiting Time:%f",avtWaitingTime1); 
    printf("\nAverage Turnaround Time:%f\n",avgTurnaroundTime1); 
}
int main()
{
	printf("Enter the no. of process you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			arrivalTime1[j]=at[i];
			burstTime1[j]=bt[i];
			j++;
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrivalTime2[k]=at[i];
			burstTime2[k]=bt[i];
			k++;
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			arrivalTime3[l]=at[i];
			burstTime3[l]=bt[i];
			l++;
		}
	}
	
	roundRobin();
	return 0;
}
