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

       //	getchar();

	printf("Details for the process %c\n",proc[i].proc_name);

	printf("Arrival Time: ");

	scanf(" %d",&proc[i].A_time);

       //	getchar();

	printf("\a");

	printf("Burst Time: ");

	scanf(" %d",&proc[i].B_time);

       //	getchar();

	printf("Priority: ");

	scanf(" %d", &proc[i].prior);

       //	getchar();

	}

	printf("the data you entered is: \n");

	printf("Process\tAT\tBT\tPriority\n");

	for(i=0;i<n;i++)

	{

	printf("%c\t%d\t%d\t%d\n",proc[i].proc_name,proc[i].A_time,proc[i].B_time,proc[i].prior);

	}

	//int posi,j;

}