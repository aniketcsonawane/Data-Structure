#include <stdio.h>
#include<stdlib.h>

struct Queue{
	int* data ;
	int capasity;
	int rear;
	int front;
	int size ;
};

int isEmpty(struct Queue* queue)
{
	if( queue -> size == 0)
		return 1;
	else
		return 0;
}

int isFull(struct Queue* queue)
{
	if( queue -> size == queue -> capasity)
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
		queue -> size = 0 ;

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

		queue -> rear = (queue -> rear)+1 % queue -> capasity ;
		queue -> data[ queue -> rear] = data;
		if(queue -> front == -1)
			( queue -> front )++;
		(queue -> size)++;
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
			queue -> front = ((queue -> front) + 1) % ( queue -> capasity );
			(queue -> size)--;
		}
	}
}

void peek(struct Queue* queue)
{
	if(queue -> size == 0)
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
		int x = queue -> front ;
		for( i = queue->front ; i <= queue->rear ; i++ ) 
		{
			if(queue -> size == 1)
				printf("\t\t\t\t <--- |  %d  | --->",queue -> data[x]);
			else if(i == queue->front)
				printf("\t\t\t\t <--- |  %d  |",queue -> data[x]);
			else if(i == queue->rear)
				printf("  %d  | <---",queue -> data[x]);
			else
				printf("  %d  |",queue -> data[x]);

			x = ( x + 1 ) % ( queue -> capasity );
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