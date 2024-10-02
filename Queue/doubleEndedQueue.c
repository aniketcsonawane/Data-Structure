#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int* dataArr;
	int capasity;
	int rear , front;
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
	struct Queue* queue =  (struct Queue*) malloc(sizeof(struct Queue)) ;

	if(queue == NULL)
	{
		printf("\t\t* Queue Not Created !") ;
		return NULL ;
	}else
	{
		int cap;
		
		printf("\t\t* Enter The Capasity Of Queue : ") ;
		scanf("%d",&cap) ;
		printf("\n") ;

		queue -> capasity = cap ;
		queue -> dataArr = (int* )malloc( sizeof(int) * queue -> capasity) ;
		queue -> rear = -1 ;
		queue -> front = -1 ;
		queue -> size = 0 ;

		return queue ;
	}
}


void enqueueAtRear(struct Queue* queue)
{
	if(isFull(queue)){
		printf("\t\t* Queue Is Full !\n\n");
	}
	else{
		int data;
		
		printf("\t\t* Enter The Data To Insert : ");
		scanf("%d",&data);
		printf("\n");
		
		queue -> rear = ((queue -> rear) + 1) % (queue -> capasity);
	
		queue -> dataArr[ queue -> rear] = data;

		if(queue -> front == -1)
			(queue -> front)++;

		(queue -> size)++;
	}
}

void enqueueAtFront(struct Queue* queue)
{
	if(isFull(queue)){
		printf("\t\t* Queue Is Full !\n\n");
	}
	else{
		int data;
		int i ;
		
		printf("\t\t* Enter The Data To Insert : ");
		scanf("%d",&data);
		printf("\n");
		
		if(queue -> front == -1)
			(queue -> front)++;
		else
			queue -> front = ((queue -> front) - 1) % (queue -> capasity);
	
		queue -> dataArr[ queue -> front] = data;

		if(queue -> rear == -1 )
			(queue -> rear)++;
		(queue -> size)++;
	}
}


void dequeueAtFront(struct Queue* queue)
{
	if(isEmpty(queue)){
		printf("\t\t* Queue Is Empty !\n");
	}
	else{
		if(!(queue -> rear == queue-> front))
		{
			printf("\t\t*Element Will Dequeued is : %d \n\n",queue -> dataArr[queue->front]);
			queue -> front = ((queue -> front) + 1) % (queue -> capasity);
		}
		
		(queue -> size)--;
	}
}

void dequeueAtRear(struct Queue* queue)
{
	if(isEmpty(queue)){
		printf("\t\t* Queue Is Empty !\n");
	}
	else{
		if(!(queue -> rear == queue-> front))
		{
			printf("\t\t*Element Will Dequeued is : %d \n\n",queue -> dataArr[queue->rear]);

			queue -> rear = ((queue -> rear) - 1) % (queue -> capasity);
		}

		(queue -> size)--;
	}
}


void peek(struct Queue* queue)
{
	if(queue->front == -1)
		printf("\t\tQueue Is Empty ! \n\n");
	else
	{
		printf("\t\tPEEK Front : %d \n\n",queue -> dataArr[queue->front]);
		printf("\t\tPEEK Rear  : %d \n\n",queue -> dataArr[queue->rear]);
	}
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
				printf("\t\t\t\t <--- |  %d  |",queue -> dataArr[i]);
			else if(i == queue->rear)
				printf("  %d  | <---",queue -> dataArr[i]);
			else
				printf("  %d  |",queue -> dataArr[i]);
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
		printf("\t\tSelect Your Choice : \n\t\t1. Enqueue At Front\n\t\t2. Enqueue At Rear\n\t\t3. Dequeue At Front\n\t\t4. Dequeue At Rear\n\t\t5. PEEK \n\t\t6. Display Queue\n\t\t0. Exit\n");
		printf("\t\tEnter Your Choice : ");
		scanf("%d",&ch);
		printf("\n");

		switch(ch)
		{
			case 1 :
					enqueueAtFront(queue);

					break;
			case 2 :
					enqueueAtRear(queue);
					break;
			case 3 : 
					dequeueAtFront(queue);
					break;
			case 4 :
					dequeueAtRear(queue);
					break;
			case 5 :
					peek(queue);
					break;
			case 6 :
					displayQueue(queue);
					break;
			default:
				printf("\t\tEnvalid Choice!\n");
		}
	}while(ch != 0);

}