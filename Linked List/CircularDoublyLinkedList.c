#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};


struct Node* createNode()
{
	struct Node* newNode = (struct Node* ) malloc(sizeof(struct Node*));

	if(newNode == NULL)
	{
		printf("\t\tMemory Not Allocated !\n");
	}
	else
	{
		int data ;
		printf("\t\t Enter The Data :  \n\t\t");
		scanf("%d",&data);

		newNode -> next = NULL;
		newNode -> data = data;
		newNode -> prev = NULL;

		return newNode;
	}
}


void createLinkedList(struct Node** head , struct Node** last)
{
	struct Node* newNode = createNode();

	if(*last == NULL && *head == NULL)
	{
		*head = newNode;
		*last = newNode;
		(*last)->next = newNode;
		(*head)->prev = newNode;
	}
	else
	{
		newNode -> prev = *last;
		newNode -> next = *head;
		(*head) -> prev = newNode;
		(*last) -> next = newNode;
		*last = newNode;
		*head = (*last)->next;
	}
}


void displayLinkedList(struct Node* head , struct Node* last)
{
	if(last == NULL && head == NULL)
	{
		printf("Linked List is Empty !");
	}
	else
	{
		struct Node* travNode = head ;

		do
		{
			printf( " [ %d | %p ] ---> " , travNode -> data , travNode -> next );
			travNode = travNode -> next ;
		}while( travNode ->next != last );
	}
}

void insertAtFirst(struct Node** head, struct Node** last)
{
	struct Node* newNode = createNode();

	if(*head == NULL && *last == NULL)
	{
		*head = newNode;
		*last = newNode;
		(*last)->next = newNode;
		(*head)->prev = newNode;
	}
	else
	{
		newNode->prev = *last;
		newNode->next = *head;
		(*last)->next = newNode;
		(*head)->prev = newNode;
		*head = newNode; 
	}
}

void insertAtLast(struct Node** head, struct Node** last)
{
	createLinkedList(head,last);
}

void main()
{
	int ch ;
	struct Node* FirstNode = NULL;
	struct Node* LastNode = NULL;

	do
	{
		//displayLinkedList(LastNode);

		printf("\n	Choose Options \n		1. Create Linked List \n		2. Dislay Linked List \n		3. Insert At First POS \n		4. Insert At Last \n		5. Insert At Pos\n		6. Delete AT First\n		7. Delete At Last\n		8. Delete At Pos\n		9. Search Element\n		10. Sort Linked List\n		11. Reverse Linked List\n		12. Delete Linked List\n		13. Replace Node\n		0. Exit \n\n");
		printf("	Enter Choice : ");
		scanf("%d",&ch);


		switch(ch)
		{
			case 1 :
					createLinkedList(&FirstNode,&LastNode);
					break;
			case 2 :
					displayLinkedList(FirstNode,LastNode);
					break;
			case 3 :
					insertAtFirst(&FirstNode,&LastNode);
					break;
			case 4 :
					insertAtLast(&FirstNode ,&LastNode);
					break;
			//case 5	:
			//		insertAtPos(&FirstNode,&LastNode);
			////		break;
			//case 6	:
			//		deleteAtFirst(&LastNode);
			//		break;
			//case 7	:
			//		//deleteAtLast(&FirstNode);
			//		deleteAtLast(&LastNode);
			//		break;
			////case 8  :
			//		deleteAtPos(&FirstNode);
			//		break;
			//case 9	:
			//		searchNode(FirstNode);
			//		break;
			//case 10 : 
			//		sortLinkedList(FirstNode);
			//		break;
			//case 11 : 
			//		reverseLinkedList(FirstNode);
			//		break;
			//case 12 :
			//		deleteLinkedList(&FirstNode);
			//		break;
			//case 13	:
			//		replaceNode(&FirstNode);
			//		break;
			//default : 
					printf("	Invalid Choice !\n");
		}
	}while(ch != 0);
}