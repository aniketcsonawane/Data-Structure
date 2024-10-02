#include <stdio.h>
#include<stdlib.h>

struct Queue{
	int* data ;
	int capasity;
	int rear;
	int front;
};

int isFull(struct Queue* queue)
{
	if( queue -> rear == (queue -> capasity) -1)
		return 1;
	else
		return 0;
}

int isEmpty(struct Queue* queue)
{
	if( queue -> front == - 1)
		return 1;
	else
		return 0;
}

struct Queue* createQueue()
{
	struct Queue* queue =  (struct Queue*) malloc(sizeof(struct Queue));
	if(queue == NULL)
	{
		printf("\t\t* Queue Not Created !");
		return NULL;
	}else
	{
		int cap;
		
		printf("\t\t* Enter The Capasity Of Queue : ");
		scanf("%d",&cap);
		printf("\n");
		queue -> capasity = cap;
		queue -> data = (int * )malloc( sizeof(int) * queue -> capasity);
		queue -> rear = queue -> front = -1 ;

		return queue ;
	}
}

void enqueue(struct Queue* queue)
{
	if(isFull(queue)){
		printf("\t\t* Queue Is Full !\n\n");
	}
	else{
		int data;
		
		printf("\t\t* Enter The Data To Insert : ");
		scanf("%d",&data);
		printf("\n");

		(queue -> rear)++;
		queue -> data[ queue -> rear] = data;
		if(isEmpty(queue))
			( queue -> front )++;
	}
}

void dequeue(struct Queue* queue)
{
	if(isEmpty(queue)){
		printf("\t\t* Queue Is Empty !\n");
	}
	else{
		if(!(queue -> rear == queue-> front))
		{
			printf("\t\t*Element Will Dequeued is : %d \n\n",queue -> data[queue->front]);
			(queue -> front)++;
		}
	}
}

void peek(struct Queue* queue)
{
	if(queue->front == -1)
		printf("\t\tQueue Is Empty ! \n\n");
	else
		printf("\t\tPEEK : %d \n\n",queue -> data[queue->front]);
}

void displayQueue(struct Queue* queue)
{
	printf("\n");
	if(isEmpty(queue))
	{
		printf("\t\t* The Queue Is Empty !\n\n");
	}else
	{
		int i ;
		for( i = queue->front ; i <= queue->rear ; i++ ) 
		{
			if(i == queue->front)
				printf("\t\t\t\t <--- |  %d  |",queue -> data[i]);
			else if(i == queue->rear)
				printf("  %d  | <---",queue -> data[i]);
			else
				printf("  %d  |",queue -> data[i]);
		}
	}
	printf("\n\n");
}


void main()
{
	struct Queue* queue = NULL;
	int ch;

	queue = createQueue();

	do
	{
		printf("\t\tSelect Your Choice : \n\t\t1. Enqueue\n\t\t2. Dequeue\n\t\t3. PEEK \n\t\t4. Display Queue\n\t\t0. Exit\n");
		printf("\t\tEnter Your Choice : ");
		scanf("%d",&ch);
		printf("\n");

		switch(ch)
		{
			case 1 :
					enqueue(queue);
					break;
			case 2 : 
					dequeue(queue);
					break;
			case 3 :
					peek(queue);
					break;
			case 4 :
					displayQueue(queue);
					break;
			default:
				printf("\t\tEnvalid Choice!\n");
		}
	}while(ch != 0);

}