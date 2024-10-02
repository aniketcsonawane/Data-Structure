#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int data;
	struct Stack* nextFrame;
};

struct Stack* createStackFrame()
{
	struct Stack* newFrame = (struct Stack*) malloc(sizeof(struct Stack));
	if(newFrame == NULL)
	{
		printf("\t\t* Frame Not Created ! * \n");
		return NULL;
	}
	else
	{
		int data ;
		printf("\t\t* Enter The Data : ");
		scanf("%d",&data);
		printf("\n");

		newFrame -> data = data;
		newFrame -> nextFrame = NULL;
		return newFrame;
	}	
}

void push(struct Stack** top)
{
	struct Stack* newFrame = createStackFrame();
	if(*top == NULL)
	{
		*top = newFrame;
	}
	else
	{
		newFrame->nextFrame = *top ;
		*top = newFrame;
	}	
}

void pop(struct Stack** top)
{
	if(*top == NULL)
	{
		printf("\t\t* The Stack Is UnderFlow ! * \n");
	}
	else
	{
		struct Stack* tempFrame = *top;

		printf("\t\t* The Element Will Poped : %d \n\n",(*top)->data);
		
		*top = (*top)->nextFrame;
		free(tempFrame);
	}
}

void peek(struct Stack* top)
{
	if(top == NULL)
	{
		printf("\t\t* The Stack Is Empty ! * \n");
	}
	else
	{
		printf("\t\t* PEEK : %d\n",top->data);
	}
}

void displayStack(struct Stack* top)
{
	if(top == NULL)
	{
		printf("\t\t* The Stack Is Empty ! *\n");
	}else
	{
		while(top != NULL)
		{
			printf("\t|      |\n");
			printf("\t|  %d  |\n",top->data);
			printf("\t|______|\n");
			top = top->nextFrame;
		}
	}
	printf("\n\n");
}


void main()
{
	int ch;
	struct Stack* stack = NULL;

	do
	{
		displayStack(stack);
		printf("\t\t* Select Your Choice : \n\t\t1. PUSH Element\n\t\t2. POP Element\n\t\t3. PEEK Element\n\t\t4. Display Stack\n\t\t0. Exit\n");
		printf("\n\t\t* Enter Your Choice : ");
		scanf("%d",&ch);
		printf("\n\n");

		switch(ch)
		{
			case 1 :
					push(&stack);
					break;
			case 2 : 
					pop(&stack);
					break;
			case 3 :
					peek(stack);
					break;
			case 4 :
					displayStack(stack);
					break;
			default:
				printf("\t\t* Invalid Choice ! * \n");
		}
	}while(ch != 0);	
}