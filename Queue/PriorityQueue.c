#include<stdio.h>
#include<stdlib.h>

struct Element
{
	int priority;
	int data;
};

struct Queue
{
	struct Element** dataArr ;
	int capasity;
	int rear;
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
		queue -> dataArr = (struct Element ** )malloc( sizeof(struct Element*) * queue -> capasity) ;
		queue -> rear = -1 ;
		queue -> size = 0 ;

		return queue ;
	}
}

int getMax(struct Queue* queue)
{
	int i , index  ;
	int max = (queue -> dataArr[0])->priority;

	for(i = 0 ; i <= queue -> rear ; i++)
	{
		if( max <= (queue -> dataArr[i])->priority)
		{
			max = (queue -> dataArr[i])->priority;
			index = i ;
		}
	}
	return index;
}

void enqueue(struct Queue* queue)
{
	if(isFull(queue)){
		printf("\t\t* Queue Is Full !\n\n");
	}
	else{
		int data, priority;
		
		printf("\t\t* Enter The Data To Insert : ");
		scanf("%d",&data);
		printf("\n");
			
		printf("\t\t* Enter The Priority : ");
		scanf("%d",&priority);
		printf("\n");

		(queue -> rear)++;

		queue -> dataArr[ queue -> rear] = (struct Element*) malloc(sizeof(struct Element));

		(queue -> dataArr[ queue -> rear ] )-> data = data ;
		(queue -> dataArr[ queue -> rear ] )-> priority = priority ;

		(queue -> size)++;
	}
}

void dequeue(struct Queue* queue)
{
	if(isEmpty(queue)){
		printf("\t\t* Queue Is Empty !\n");
	}
	else{
			int max = getMax(queue),i;
			struct Element* temp = (queue -> dataArr[max]);
			printf("\t\t*Element Will Dequeued is : %d \n\n",(queue -> dataArr[max])->data);

			free(temp);
			for( i = max ; i <= queue -> rear ;i++)
			{
				queue -> dataArr[i] = queue -> dataArr[i+1];
			}

			(queue -> rear )--;
			(queue -> size)--;
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
		for( i = 0 ; i <= queue->rear ; i++ ) 
		{
			if(queue -> size == 1)
				printf("\t\t\t\t <--- [  %d  |  %d  ] --->",(queue -> dataArr[i]) -> data, (queue -> dataArr[i]) -> priority);
			else if(i == 0)
				printf("\t\t\t\t <--- [  %d  |  %d  ]",(queue -> dataArr[i]) -> data, (queue -> dataArr[i]) -> priority);
			else if(i == queue->rear)
				printf("  [  %d  |  %d  ] <---",(queue -> dataArr[i]) -> data, (queue -> dataArr[i]) -> priority);
			else
				printf("  [  %d  |  %d  ] ",(queue -> dataArr[i]) -> data, (queue -> dataArr[i]) -> priority);
		}
	}
	printf("\n\n");
}


void peek(struct Queue* queue)
{
	int max = getMax(queue);

	if(queue -> size == 0)
		printf("\t\tQueue Is Empty ! \n\n");
	else
		printf("\t\tPEEK : %d \n\n",(queue -> dataArr[max])->data);
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