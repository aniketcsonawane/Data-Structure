#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data ; 
	struct Node* next ;
};

struct Node* createNode();
void createLinkedList(struct Node** Head);
void displayLinkedList(struct Node* head);
void insertAtFirst(struct Node** head);
void insertAtLast(struct Node**  head);
void insertAtPos(struct Node** head);
void deleteAtFirst(struct Node** head);
void deleteAtLast(struct Node** head);
void deleteAtLastSingle(struct Node** head);
void deleteAtPos(struct Node** head);
int countNode(struct Node* head);
void searchNode(struct Node* head);
void sortLinkedList(struct Node* head);
void displayList(struct Node* head);
void reverseLinkedList(struct Node* head);
void deleteLinkedList(struct Node** head);
void replaceNode(struct Node* head);

void main()
{
	int ch ;
	struct Node* FirstNode = NULL;

	do
	{
		displayList(FirstNode);

		printf("\n	Choose Options \n		1. Create Linked List \n		2. Dislay Linked List \n		3. Insert At First POS \n		4. Insert At Last \n		5. Insert At Pos\n		6. Delete AT First\n		7. Delete At Last\n		8. Delete At Pos\n		9. Search Element\n		10. Sort Linked List\n		11. Reverse Linked List\n		12. Delete Linked List\n		13. Replace Node\n		0. Exit \n\n");
		printf("	Enter Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 :
					createLinkedList(&FirstNode);
					break;
			case 2 :
					displayLinkedList(FirstNode);
					break;
			case 3 :
					insertAtFirst(&FirstNode);
					break;
			case 4 :
					insertAtLast(&FirstNode);
					break;
			case 5	:
					insertAtPos(&FirstNode);
					break;
			case 6	:
					deleteAtFirst(&FirstNode);
					break;
			case 7	:
					//deleteAtLast(&FirstNode);
					deleteAtLastSingle(&FirstNode);
					break;
			case 8  :
					deleteAtPos(&FirstNode);
					break;
			case 9	:
					searchNode(FirstNode);
					break;
			case 10 : 
					sortLinkedList(FirstNode);
					break;
			case 11 : 
					reverseLinkedList(FirstNode);
					break;
			case 12 :
					deleteLinkedList(&FirstNode);
					break;
			case 13	:
					replaceNode(&FirstNode);
					break;
			default : 
					printf("	Invalid Choice !\n");
		}
	}while(ch != 0);
}

struct Node* createNode()
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

	if(newNode == NULL)
	{
		printf("\tMemory Not Allocated !\n");
	}
	else
	{
		int Data;
		
		printf("\tEnter The Data : ");
		scanf("%d",&Data);

		newNode -> data = Data;
		newNode -> next = NULL;

		return newNode;
	}
}

void createLinkedList(struct Node** head)
{
	struct Node* currentNode = *head ;
	struct Node* newNode = createNode();

	if(*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while(currentNode->next != NULL)
		{
			currentNode = currentNode -> next;
		}
		currentNode -> next = newNode;
	}
}

void displayLinkedList(struct Node* head)
{
	if(head == NULL)
	{
		printf("\tLinked List Is Empty !\n");
	}
	else
	{
		int nodeNumber = 1;
		printf("\n \tThe Linked List is as Given : \n\n");
		printf("\t\t\t");
		while(head != NULL)
		{
			if(head->next == NULL)
			{
				printf("[ %d | %d | NULL ] ",nodeNumber,head->data);
			}else
			{
				printf("[ %d | %d | %p ] ---> ",nodeNumber,head->data,head->next);
			}			
			head = head -> next;
			nodeNumber++;
		}
		printf("\n\n");
	}
}

void insertAtFirst(struct Node** head)
{
	struct Node* newNode = createNode();
	
	newNode -> next = *head ;
	*head = newNode ; 
}

void insertAtLast(struct Node** head)
{
	createLinkedList(head);
}

void deleteAtFirst(struct Node** head)
{
	struct Node* tempNode;
	if(*head == NULL)
	{
		printf("\t\tList Is Empty!\n");
	}
	else
	{
		tempNode = *head;
		*head = (*head)->next;
		free(tempNode);
	}
}

void deleteAtLastSingle(struct Node** head)
{
	struct Node* currentNode = *head;

	if(*head == NULL)
	{
		printf("\t List is empty !!\n");
	}
	else if(currentNode->next == NULL)
	{
		free(currentNode);
		*head = NULL;
	}
	else
	{
		while(currentNode->next->next != NULL)
		{
			currentNode = currentNode->next ;
		}
		free(currentNode->next);
		currentNode->next = NULL;
	}
	
}

void deleteAtPos(struct Node** head)
{
	int pos ;
	int n, i;
	printf("\n\t\tEnter Position Here : \n\t\t");
	scanf("%d",&pos);

	n = countNode(*head);

	if(pos < 1  || pos > n+1)
	{
		printf("\n\t\t please Enter Valid Pos !! \n");
		deleteAtPos(head);
	}
	else if(pos == 1)
	{
		deleteAtFirst(head);
	}
	else if(pos == n)
	{
		deleteAtLast(head);
	}
	else
	{
		struct Node* tempNode = NULL;
		struct Node* currentNode = *head;

		for(i = 1 ; i < pos - 1 ; i++)
		{
			currentNode = currentNode->next;
		}
		tempNode = currentNode -> next;
		currentNode -> next = currentNode -> next -> next;
		free(tempNode);
	}


}

void deleteAtLast(struct Node** head)
{
	struct Node* prevNode = *head ;
	struct Node* currentNode = *head ;

	if(*head == NULL)
	{
		printf("\t\t List Is Empty!\n");
	}
	else if((*head) -> next == NULL)
	{
		*head = NULL;
	}
	else if(((*head)->next)->next == NULL)
	{
		free((*head) -> next -> next);
		(*head) -> next = NULL;
	}
	else
	{
		while(currentNode->next != NULL)
		{
				prevNode = prevNode -> next;
				currentNode = prevNode->next;
		}
		free(currentNode);
		prevNode->next = NULL;
	}

}

void insertAtPos(struct Node** head)
{
	int pos ;
	int n ;
	printf("\nEnter Position Here : \n");
	scanf("%d",&pos);

	n = countNode(*head);

	if(pos < 1  || pos > n+1)
	{
		printf("\n please Enter Valid Pos !! \n");
		insertAtPos(head);
	}
	else if(pos == 1)
	{
		insertAtFirst(head);
	}
	else if(pos == n+1)
	{
		insertAtLast(head);
	}
	else
	{
		int i ;
		struct Node* newNode = createNode();
		struct Node* currentNode = *head;

		for(i = 1 ; i < pos -1 ; i++)
		{
			currentNode = currentNode->next;
		}

		newNode->next = currentNode->next;
		currentNode -> next = newNode;
	}
}

int countNode(struct Node* head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

void searchNode(struct Node* head)
{
	int search;
	int flag = 0;
	struct Node* currentNode = head;
	int count = 0 ;

	printf("\t\tEnter The Data Of Node To Search :  \n\t\t");
	scanf("%d",&search);


	while(currentNode != NULL)
	{
		count++;
		if(currentNode->data == search)
		{
			flag = 1 ;
			break;
		}
		else
		{
			flag = 0 ;
		}
		currentNode = currentNode -> next; 
	}

	if(flag == 1)
	{
		printf("\t\tData is Found ! in Node Number %d \n",count);
	}
	else
	{
		printf("\t\tData is Not Found ! \n");
	}

}

void sortLinkedList(struct Node* head)
{
	struct Node* i = NULL;
	struct Node* j = NULL;

	for( i = head; i != NULL ;i = i->next)
	{
		for( j = i -> next ; j != NULL ; j = j->next )
		{
			if(i->data > j->data)
			{
				int temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
	printf("\n \t\t Sorted List : \n");
}

void displayList(struct Node* head)
{
	if(head == NULL)
	{
		printf("\n \t\t[ NULL ] \n");
	}
	else
	{
		int nodeNumber = 1;
		printf("\n\t\t");
		while(head != NULL)
		{
			if(head->next == NULL)
			{
				printf("[ %d | %d | NULL ] ",nodeNumber,head->data);
			}else
			{
				printf("[ %d | %d | %p ] ---> ",nodeNumber,head->data,head->next);
			}			
			head = head -> next;
			nodeNumber++;
		}
		printf("\n");
	}
}

void reverseLinkedList(struct Node* head)
{
	if(head != NULL)
	{
		reverseLinkedList(head->next);

		printf("[ %d ] --> " , head->data);
	}
	else
	{
		printf("\n");
		return;
	}
}

void deleteLinkedList(struct Node** head)
{
	struct Node* currentNode = *head;
	struct Node* prevNode  = *head;

	while(currentNode != NULL)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
		free(prevNode);
	}
	printf("Linked List Deleted ! \n");

	*head = NULL;
}

void replaceNode(struct Node** head)
{
	int pos ;
	int i, n;
	struct Node* currentNode = *head;
	struct Node* newNode;
	struct Node* tempNode;

	printf("\n\t\tEnter Position Where Replace Node : \n\t\t");
	scanf("%d",&pos);
	newNode = createNode();

	n = countNode(*head);

	for(i = 1 ; i < pos - 1  ; i++)
	{
		currentNode = currentNode->next;
	}
	
	tempNode = currentNode -> next;
	currentNode->next = newNode;
	newNode->next = tempNode->next;
	free(tempNode);
}