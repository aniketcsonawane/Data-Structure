#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data ; 
	struct Node* next ;
};

struct Node* createNode();
void createLinkedList(struct Node** last);
void displayLinkedList(struct Node* head);
void insertAtFirst(struct Node** last );

void insertAtLast(struct Node** last);
//void insertAtPos(struct Node** head , struct Node** last);
void deleteAtLast(struct Node** last);
void deleteAtFirst(struct Node** last);

void main()
{
	int ch ;
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
					createLinkedList(&LastNode);
					break;
			case 2 :
					displayLinkedList(LastNode);
					break;
			case 3 :
					insertAtFirst(&LastNode);
					break;
			case 4 :
					insertAtLast(&LastNode);
					break;
			//case 5	:
			//		insertAtPos(&FirstNode,&LastNode);
			//		break;
			case 6	:
					deleteAtFirst(&LastNode);
					break;
			case 7	:
					//deleteAtLast(&FirstNode);
					deleteAtLast(&LastNode);
					break;
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
		return newNode;
	}
}


void createLinkedList(struct Node** last)
{
	struct Node* newNode = createNode();

	if(*last == NULL)
	{
		*last = newNode;
		(*last)->next = newNode;
	}
	else
	{
		newNode -> next = (*last)->next;
		(*last)-> next = newNode;
		*last = newNode;

	}
}

void displayLinkedList(struct Node* last)
{
	if(last == NULL)
	{
		printf("Linked List is Empty !");
	}
	else
	{
		struct Node* travNode = last->next ;

		do{
			printf(" [ %d | %p ] ---> ",travNode->data ,travNode -> next);
			travNode = travNode->next;
		}while(travNode != last->next);
	}
}

void insertAtFirst(struct Node** last)
{
	struct Node* newNode = createNode();

	if(*last == NULL)
	{
		*last = newNode;
		(*last)->next = newNode;
	}
	else
	{
		newNode->next = (*last)->next;
		(*last)->next = newNode;
	}
}

void insertAtLast(struct Node** last)
{
	struct Node* newNode = createNode();
	if(*last == NULL)
	{
		*last = newNode;
		(*last)->next = newNode;
	}
	else
	{
		newNode -> next = (*last) -> next;
		(*last) -> next = newNode;
		*last = newNode;
	}
}

void deleteAtLast(struct Node** last)
{
	printf("Here");
	if(*last == NULL)
	{
		printf("\n\t\tThe List is Empty !\n");
	}
	else if((*last)->next == *last)
	{
		*last = NULL;
	}else
	{
		struct Node* travNode = (*last) -> next;
		struct Node* tempNode = *last;
		while(travNode->next != *last)
		{
			travNode = travNode->next; 
		}

		//free(*last);
		travNode->next = (*last)->next;
		*last = travNode->next;
		free(tempNode);
		
	}
}

void deleteAtFirst(struct Node** last)
{
	if((*last)->next == *last)
	{
		*last = NULL;
	}else
	{
		struct Node* tempNode = (*last)->next;
		(*last)->next = tempNode->next;
		free(tempNode);
	}
}
