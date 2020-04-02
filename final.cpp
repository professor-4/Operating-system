#include<stdio.h>
int arrivalTime1[30],arrivalTime2[30],priority2[30],process2[30],arrivalTime3[30];
int burstTime1[30],burstTime2[30],burstTime3[30];

int Total=0,time1=0,time2=0,time3=0;

int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;

int total,x,temp[30],counter=0;
float avtWaitingTime1=0.0,avgTurnaroundTime1=0.0;

int p,waitingTime3[30],turnaroundTime3[30];
float avtWaitingTime3=0.0,avgTurnaroundTime3=0.0;

int position,q,temp1,sum=0,waitingTime2[30],turnaroundTime2[30];
float avtWaitingTime2,avgTurnaroundTime2;


//making priority function
void priority()
{
	for(i=0;i<k;i++)
    {    //initialize possition to i;
        position=i;
        for(q=i+1;q<k;q++)
        {
            if(priority2[q]<priority2[position])
            {
                position=q;
            }
        }
        temp1=priority2[i];
        priority2[i]=priority2[position];
        priority2[position]=temp1; 
        
        temp1=burstTime2[i];
        burstTime2[i]=burstTime2[position];
        burstTime2[position]=temp1;
        
        temp1=process2[i];
        process2[i]=process2[position];
        process2[position]=temp1;
    }
    waitingTime2[0]=0;
    for(i=1;i<k;i++)
    {
        waitingTime2[i]=0;
        for(q=0;q<i;q++)
        {
            waitingTime2[i]=waitingTime2[i]+burstTime2[j];
        }
        sum=sum+waitingTime2[i];
    }
    avtWaitingTime2=sum/k;
    sum=0;
    printf("Process ID   Burst Time Waiting Time Turnaround Time");
    for(i=0;i<k;i++)
    {
    	turnaroundTime2[i]=burstTime2[i]+waitingTime2[i];
        sum=sum+turnaroundTime2[i];
        printf("\nProcess[%d] %d  %d %d\n",process2[i],burstTime2[i],waitingTime2[i],turnaroundTime2[i]);
    }
    avgTurnaroundTime2=sum/k;
    printf("\nAverage Waiting Time:\t%f",avtWaitingTime2);
    printf("\nAverage Turnaround Time:\t%f\n",avgTurnaroundTime2);
    
    for(i=0;i<k;i++)
    {
    	while(burstTime2[i]!=0)
    	{
    		if(burstTime2[i]>10)
    		{
				printf("\nProcess[%d] of Queue2 is running for 10 units",i+1);
				burstTime2[i]=burstTime2[i]-10;
			}
			else if(burstTime2[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,burstTime2[i]);
				burstTime2[i]=0;
			}
		}
	}

}

void firstcomefs()
{
	waitingTime3[0] = 0;   
    for(i=1;i<l;i++)
    {
        waitingTime3[i] = 0;
        for(p=0;p<l;p++)
        {
            waitingTime3[i]=waitingTime3[i]+burstTime3[p];
        }
    }
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<l;i++)
    {
        turnaroundTime3[i]=burstTime3[i]+waitingTime3[i];
        avtWaitingTime3=avtWaitingTime3+waitingTime3[i];
        avgTurnaroundTime3=avgTurnaroundTime3+turnaroundTime3[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,burstTime3[i],waitingTime3[i],turnaroundTime3[i]);
    }
    avtWaitingTime3=avtWaitingTime3/l;
    avgTurnaroundTime3=avgTurnaroundTime3/l;
    printf("Average Waiting Time=%f",avtWaitingTime3);
    printf("Average Turnaround Time=%f",avgTurnaroundTime3);
    for(i=0;i<l;i++)
    {
    	while(burstTime3[i]!=0)
    	{
    		if(burstTime3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is running for 10 units",i+1);
				burstTime3[i]=burstTime3[i]-10;
			}
			else if(burstTime3[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,burstTime3[i]);
				burstTime3[i]=0;
			}
		}
	}
}
void roundRobin()
{
	printf("Time Quantum for Queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		temp[i]=burstTime1[i];
	} 
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x=j;
    for(i=0,total=0;x!=0;) 
    { 
    	if(temp[i]<=4&&temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for %d units",i+1,temp[i]); 
            total=total+temp[i]; 
            temp[i]=0; 
            counter=1; 
        } 
        else if(temp[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for 4 units",i+1); 
            temp[i]=temp[i]-4; 
            total=total+4; 
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
    //printing average waiting time
    printf("\nAverage Waiting Time:%f",avtWaitingTime1); 
    //printing average turaround time
    printf("\nAverage Turnaround Time:%f\n",avgTurnaroundTime1); 
}

void roundRobin1()
{
	printf("Time Quantum between the 3 queues is 10\n");
	for(i=1;i<Total;i=i+10)
	{
		if(time1>10)
		{
			printf("Queue1 is running for 10 units\n");
			time1=time1-10;
		}
		else if(time1<=10&&time1!=0)
		{
			printf("Queue1 is running for %d units\n",time1);
			time1=0;
		}
		if(time2>10)
		{
			printf("Queue2 is running for 10 units\n");
			time2=time2-10;
		}
		else if(time2<=10&&time2!=0)
		{
			printf("Queue2 is running for %d units\n",time2);
			time2=0;
		}
		if(time3>10)
		{
			printf("Queue3 is running for 10 units\n");
			time3=time3-10;
		}
		else if(time3<=10&&time3!=0)
		{
			printf("Queue3 is running for %d units\n",time3);
			time3=0;
		}
	}
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
		Total=Total+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\nProcess[%d] belongs to Queue 1\n",i+1);
			arrivalTime1[j]=at[i];
			burstTime1[j]=bt[i];
			j++;
			time1=time1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrivalTime2[k]=at[i];
			burstTime2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			time2=time2+bt[i];
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1);
			arrivalTime3[l]=at[i];
			burstTime3[l]=bt[i];
			l++;
			time3=time3+bt[i];
		}
	}
	
	roundRobin1();
	roundRobin();
	firstcomefs();
	priority();
	
	return 0;
}
