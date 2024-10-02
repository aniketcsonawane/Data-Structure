#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int* arr;
	int capasity;
	int top;
};

int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);

struct Stack* createStack()
{
	struct Stack* newStack = (struct Stack*) malloc(sizeof(struct Stack));
	if(newStack == NULL)
	{
		printf("\t\tStack Not Created! Didnt Get Memmory !\n");
	}
	else
	{
		int cap;

		printf("\t\tEnter The Capasity Of The Stack : ");
		scanf("%d",&cap);
		printf("\n");

		newStack -> capasity = cap ;
		newStack -> arr = (int*)malloc(sizeof(int)* cap) ;
		newStack -> top = -1 ;
	}

	return newStack;
}

void push(struct Stack* stack)
{
	if(isFull(stack))
	{
		printf("\t\tStack is Full !\n\n");
	}
	else
	{
		int ele ;

		printf("\t\tEnter The Element : ");
		scanf("%d",&ele);
		printf("\n");
		( stack -> top )++;
		stack -> arr[ stack->top ] = ele;

	}
}

void display(struct Stack* stack)
{
	int i ;
	for( i = ( stack -> capasity ) - 1 ; i >= 0 ; i-- ) 
	{
		if( i <= stack -> top )
		{
			printf("\t\t\t\t|      |\n");
			printf("\t\t\t\t|  %d  |\n",stack -> arr[i]);
			printf("\t\t\t\t|______|\n");
		}
		else
		{
			printf("\t\t\t\t|      |\n");
			printf("\t\t\t\t|      |\n");
			printf("\t\t\t\t|______|\n");
		}
	}
}

void pop(struct Stack* stack)
{
	if(stack->top == -1)
	{
		printf("\t\tStack Empty! \n");
	}
	else
	{
		printf("\t\tElement Poped is : %d\n",stack->arr[stack->top]);
		(stack->top)--;
	}
}

void peek(struct Stack* stack)
{
	if(stack->top == -1)
		printf("\t\tStack Is in Underflow! \n");
	else
	printf("\t\tPEEK : %d \n",stack->arr[stack->top]);
}

int isFull(struct Stack* stack)
{
	if( stack -> top == stack -> capasity - 1)
		return 1 ;
	else
		return 0 ;
}
int isEmpty(struct Stack* stack)
{
	printf("\t\t top : %d\n ",stack->top);
	if( stack -> top == - 1)
		return 1 ;
	else
		return 0 ;

}

void main()
{
	int ch;
	struct Stack* stack = NULL;

	stack = createStack();
	do
	{
		display(stack);
		printf("\t\tSelect Your Choice : \n\t\t1. PUSH Element\n\t\t2. POP Element\n\t\t3. PEEK Element\n\t\t4. Display Stack\n\t\t0. Exit\n");
		printf("\t\tEnter Your Choice : ");
		scanf("%d",&ch);
		printf("\n");

		switch(ch)
		{
			case 1 :
					push(stack);
					break;
			case 2 : 
					pop(stack);
					break;
			case 3 :
					peek(stack);
					break;
			case 4 :
					display(stack);
					break;
			default:
				printf("\t\tEnvalid Choice!\n");
		}
	}while(ch != 0);
}