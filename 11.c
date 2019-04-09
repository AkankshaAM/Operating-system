#include<stdio.h>
#include<conio.h>
struct proc
{
char proc_name;
int A_time,B_time,C_time,W_time,TA_time,prior;
int status;
};
void main()
{
struct proc wq[10];
struct proc proc[10];
struct proc proc1[10];
struct proc temp;
int n,i;
int posi,j,tq,t;
printf("total number of processes to enter:");
scanf("%d",&n);
for(i=0;i<n;i++)
{	
printf("Enter name for process p[%d]: ",i);
scanf(" %c",&proc[i].proc_name);
printf("Details for the process %c\n",proc[i].proc_name);
printf("Arrival Time: ");
scanf(" %d",&proc[i].A_time);
printf("Burst Time: ");
scanf(" %d",&proc[i].B_time);
printf("Priority: ");
scanf(" %d", &proc[i].prior);
}
printf("the data you entered is: \n");
printf("Process\tAT\tBT\tPriority\n");
for(i=0;i<n;i++)
{
printf("%c%d%d%d\n",proc[i].proc_name,proc[i].A_time,proc[i].B_time,proc[i].prior);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
proc[i].status=0;
if(proc[j].A_time<proc[i].A_time)
posi=j;
}
temp=proc[i];
proc[i]=proc[posi];
proc[posi]=temp;
}
printf("sorted the data according to arival time:");
printf("process\tat\tbt\tpriority\n");
for(i=0;i<n;i++)
{
printf("%c\t%d\t%d\t%d\n",proc[i].proc_name,proc[i].A_time,proc[i].B_time,proc[i].prior);
}
for(i=0;i<n;i++)
{
if(proc[i].prior<proc[i+1].prior)
{
for(i=0;i<n;i++)
{
do{
int c=1;
proc[i].B_time=proc[i].B_time-c;
if(proc[i].B_time==0)
{
printf("the process %d has been exhausted\n",proc[i].proc_name);
break;
}
if(proc[i+1].prior>=proc[i].prior)
{
wq[i].proc_name=proc[i+1].proc_name;
wq[i].B_time=proc[i+1].B_time;
}
}
while(proc[i].A_time<proc[i+1].A_time);
}
}
printf("\nwaiting queue:");
for(i=0;i<n;i++)
{
printf("%c\n",wq[i].proc_name);
}
}
printf("\n\n");
printf("\nround robin scheduling algorithm:");
printf("\nenter the time quantam for each process:");
scanf("%d",&tq);
if(tq%2!=0)
{
scanf("%d",&tq);
}
if(wq[i].B_time>tq)
{
t+=tq;
wq[i].B_time-=tq;
}
else
{
t=t+wq[i].B_time;
wq[i].W_time=t-wq[i].B_time;
wq[i].B_time=0;
}
printf("%c\n",wq[i].proc_name);
for(i=0;i<n;i++)
{
wq[i].B_time-=tq;
if(wq[i].B_time==0)
{
printf("%c\n",wq[i].proc_name);
}
}
getch();
}
