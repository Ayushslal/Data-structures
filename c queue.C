#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX],front=-1,rear=-1;

void enqueue(int item)
{
	
	if((rear+1)%MAX == front)
	{
		printf("\nQueue is Overflow!!!");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=item;
	}
	else
	{
		rear=(rear+1)%MAX;
		queue[rear]=item;
	}

}

void dequeue()
{

	if(front==-1)
	{
		printf("\nQueue is underflow!!!");
	}
	else if(front == rear)
	{
		printf("Element deleted is %d",queue[front]);
		front=rear=-1;
	}
	else 
	{
		printf("Element deleted is %d",queue[front]);
		front=(front+1)%MAX;
	}

}

void traversal()
{
	
	int i=front;	
	if(front==-1)
	{
		printf("\nQueue is underflow!!!");
	}
	else
	{
		printf("Queue is:\n");
		while(i!=rear)
		{
			printf("%d\t",queue[i]);
			i=(i+1)%MAX;
		}
		printf("%d\t",queue[rear]);
	}

}

int main()
{
	int choice,item;
	
	while(1)
	{
	  
		printf("\nCircular Queue\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Traversal\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("\nEnter the item to be inserted");
			       scanf("%d",&item);
			       enqueue(item);
			       break;
			case 2:dequeue();
			       break;
			case 3:traversal();
			       break;
			case 4:exit(0);
			       break;
			default:printf("Wrong choice!!!");
		}
	}
}


