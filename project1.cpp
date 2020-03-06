#include<stdio.h>
int arrivalTime1[30],arrivalTime2[30],arrivalTime3[30];
int burstTime1[30],burstTime2[30],burstTime3[30];
int main()
{
	int n,i,at[30],bt[30],p[30],j=0,k=0,l=0;
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
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		if(p[i]>=1&&p[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			arrivalTime1[j]=at[i];
			burstTime1[j]=bt[i];
			j++;
		}
		
		else if(p[i]>=6&&p[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrivalTime2[k]=at[i];
			burstTime2[k]=bt[i];
			k++;
		}
		
		else if(p[i]>=11&&p[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			arrivalTime3[l]=at[i];
			burstTime3[l]=bt[i];
			l++;
		}
	}
	return 0;
}
