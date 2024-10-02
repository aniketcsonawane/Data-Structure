#include<stdlib.h>
#include<stdio.h>

struct Node
{
	int data ; 
	struct Node* next ;
	struct Node* prev ;
};

struct Node* createNode();
void createLinkedList(struct Node** head , struct Node** last);
void displayLinkedList(struct Node* head);
void insertAtFirst(struct Node** head );
void insertAtLast(struct Node** head , struct Node** last);
void insertAtPos(struct Node** head , struct Node** last);
void deleteAtLast(struct Node** head , struct Node** last);
void deleteAtFirst(struct Node** head , struct Node** last);

void main()
{
	int ch ;
	struct Node* FirstNode = NULL;
	struct Node* LastNode = NULL;

	do
	{
		displayLinkedList(FirstNode);

		printf("\n	Choose Options \n		1. Create Linked List \n		2. Dislay Linked List \n		3. Insert At First POS \n		4. Insert At Last \n		5. Insert At Pos\n		6. Delete AT First\n		7. Delete At Last\n		8. Delete At Pos\n		9. Search Element\n		10. Sort Linked List\n		11. Reverse Linked List\n		12. Delete Linked List\n		13. Replace Node\n		0. Exit \n\n");
		printf("	Enter Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 :
					createLinkedList(&FirstNode, &LastNode);
					break;
			case 2 :
					displayLinkedList(FirstNode);
					break;
			case 3 :
					insertAtFirst(&FirstNode);
					break;
			case 4 :
					insertAtLast(&FirstNode,&LastNode);
					break;
			case 5	:
					insertAtPos(&FirstNode,&LastNode);
					break;
			case 6	:
					deleteAtFirst(&FirstNode,&LastNode);
					break;
			case 7	:
					//deleteAtLast(&FirstNode);
					deleteAtLast(&FirstNode,&LastNode);
					break;
			//case 8  :
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
		printf("\t\t Enter The Data :  \n");
		scanf("%d",&data);

		newNode -> next = NULL;
		newNode -> prev = NULL;
		newNode -> data = data;
		return newNode;
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
void createLinkedList(struct Node** head, struct Node** last)
{
	struct Node* newNode = createNode();

	if(*head == NULL && *last == NULL)
	{
		*head = newNode;
		*last = newNode;
	}
	else
	{
		(*last )->next = newNode;
		newNode->prev = *last;
		*last = newNode;
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
		printf("\n \tThe Linked List is as Given : \n\n");
		printf("\t\t\t");
		while(head != NULL)
		{
			if(head->prev == NULL && head->next == NULL)
			{
				printf("[ NULL | %d | NULL ] ", head->data, head->next);
			}
			else if(head->next == NULL && head->prev != NULL)
			{

				printf("--> [ %p | %d | NULL ] ", head->prev, head->data);
			}
			else if(head->prev == NULL && head->next != NULL)
			{
				printf("[ NULL | %d | %p ] <--", head->data, head->next);
			}
			else
			{
				printf("--> [ %p | %d | %p ] <--", head -> prev , head->data , head->next);

			}			
			head = head -> next;
		}
		printf("\n\n");
	}
}
void insertAtFirst(struct Node** head )
{
		struct Node* newNode = createNode();
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;

}
void insertAtLast(struct Node** head, struct Node** last)
{
	createLinkedList(head,last);
}
void insertAtPos(struct Node** head , struct Node** last)
{
	struct Node* newNode = NULL;
	struct Node* currentNode = NULL;
	int pos ;
	int n, i ;
	printf("\nEnter The Position Where to insert Node : \n");
	scanf("%d",&pos);
	n = countNode(*head);
		
	if(pos < 0 && pos > n+1){
		printf("\n Invalid Position !");
		insertAtPos(head,last);
	}
	else if(pos == 1)
	{
		insertAtFirst(head);
	}
	else if(pos == n+1)
	{
		insertAtLast(head, last);
	}
	else
	{
		newNode = createNode();
		currentNode = *head ;
		for(i = 1 ; i < pos-1 ; i++)
		{
			currentNode = currentNode->next;
			
		}
		newNode->next = currentNode->next;
		newNode -> prev = currentNode;
		
		(newNode->prev)->next = newNode;
	}
}

void deleteAtLast(struct Node** head , struct Node** last)
{
	if(*head == NULL && *last == NULL)
	{
		printf("\nLinked List is Empty TO delete Node\n");
	}
	else if((*head)->next == NULL && (*head)->prev == NULL)
	{
		free(*head);

		*head = NULL;
		*last = NULL;
	}else
	{
		struct Node* tempNode = *last ;
		*last = (*last)->prev;
		(*last) ->next = NULL;
		free(tempNode);
	}
}

void deleteAtFirst(struct Node** head , struct Node** last)
{
	if(*head == NULL && *last == NULL)
	{
		printf("\nLinked List is Empty TO delete Node\n");
	}
	else if((*head)->next == NULL && (*head)->prev == NULL)
	{
		free(*head);

		*head = NULL;
		*last = NULL;
	}else
	{
		struct Node* tempNode = *head;

		*head = (*head)->next;
		free(tempNode);

		(*head)->prev = NULL;
	}
}

void deleteLinkedList(struct Node** head, struct Node** last)
{
	if(*last == NULL && *head == NULL)
	{
		printf("\n\t\tThe List is Empty!\n");
	}else
	{
		while((*head) != NULL)
		{
			*head = (*head)->next;
			free((*head)->prev);
		}

	}
}