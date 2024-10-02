#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* createNode()
{
	
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

	if(newNode != NULL)
	{
		int Data;
		printf("\n Enter the Data :");
		scanf("%d",&Data);

		newNode -> data = Data;
		newNode -> next = NULL;

		return newNode;
	}
	else
	{
		printf("\n Memory Not Allocated ! \n");
	}
}

void createLinkedList(struct Node** head)
{
	struct Node* tempNode = createNode();
	struct Node* currentNode = *head;

	if(*head == NULL)
	{
		*head = tempNode;
	}
	else
	{
		while(currentNode -> next != NULL)
		{
			currentNode = currentNode -> next;
		}

		currentNode -> next = tempNode;

	}

}

void displayLinkedList(struct Node* head)
{
	if(head == NULL)	
	{
			printf("\n \tList Is Empty! \n");
	}
	else
	{
		while(head!=NULL)
		{
			if(head -> next == NULL)
				printf("[ %d | NULL ]", head->data);
			else
				printf("[ %d | %u ] ---> ", head->data, head->next);

			head = head->next;
		}
	}
}

void main()
{
	int ch ;
	struct Node* FirstNode = NULL;
	do{
		printf("\tChoose From Following : \n\t\t 1. Create Linked List \n\t\t 2. Display Linked List\n\t\t 3. Exit \n");
		printf("\tEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			createLinkedList(&FirstNode);
			break;
		case 2:
			displayLinkedList(FirstNode);
			break;
		default:
			printf("\tPlease En=ter Valid Choice !\n");
		}
	}while(ch != 0);
}

