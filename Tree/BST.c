#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* leftNode ;
	int data;
	struct Node* rightNode;
	int size ;
};

struct Queue
{
	struct Node** arr ;
	int front;
	int capasity;
	int rear ;
};

struct Node* createNode()
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	if(newNode == NULL)
	{
		printf("\t\t\tMemory Not Allocated !\n");
	}
	else
	{
		int data;
		printf("\t\tEnter The Data :");
		scanf("%d",&data);
		printf("\n");

		newNode->data = data;
		newNode->leftNode = NULL;
		newNode->rightNode = NULL;

		return newNode;
	}
}

void createBST(struct Node** root)
{
	struct Node* newNode = createNode();
	struct Node* tempNode = *root;
	if(*root == NULL)
	{
		*root = newNode;
	}
	else
	{
		while(tempNode != NULL)
		{
			if(newNode -> data < tempNode -> data)
			{
				//left
				if(tempNode->leftNode == NULL)
				{
					tempNode->leftNode = newNode;
					(tempNode ->size)++;
					break;
				}
				else
				{
					tempNode = tempNode->leftNode;
				}
			}
			else
			{
				//right
				if(tempNode->rightNode == NULL)
				{
					tempNode->rightNode = newNode;
					(tempNode ->size)++;
					break;
				}
				else
				{
					tempNode = tempNode->rightNode;
				}
			}
		}
	}
}

void preOrder(struct Node* root)
{
	//printf("\t\tPreorder : \n");
	if(root == NULL)
	{
		return ;
	}
	else
	{		
		printf(" | %d | -> ",root ->data);
		preOrder(root->leftNode);
		preOrder(root->rightNode);
	}
}

void inOrder(struct Node* root)
{
	
	if(root == NULL)
	{
		return ;
	}
	else
	{
		inOrder(root->leftNode);
		printf(" | %d | -> ",root ->data);
		inOrder(root->rightNode);
	}
}

void postOrder(struct Node* root)
{	
	if(root == NULL)
	{
		return ;
	}
	else
	{
		postOrder(root->leftNode);
		postOrder(root->rightNode);
		printf(" | %d | -> ",root ->data);
	}
}
struct Queue* createQueue(struct Node* root)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	if(queue == NULL)
	{
		printf("\t\t\t\tQueue Didn't Difined !\n");
	}
	else
	{
		queue -> capasity = root -> size ;
		queue -> rear = -1 ;
		queue -> front = -1;
		queue -> arr = (struct Node**)malloc(sizeof(struct Node*) * (queue->capasity));
		return queue;
	}
}
//
//int getTreeLevel(struct BST* root)
//{
//	int max1 = 0 ;
//	int max2 = 0 ;
//
//	while()
//}

void insertQueue(struct Queue* queue ,struct Node* root)
{
	if(queue -> rear != queue->capasity)
	{
		(queue->rear)++;
		queue->arr[queue->rear] = root;
	}
}

struct Node* peek(struct Queue* queue)
{
	return queue->arr[(queue->front+1)];
}

void BFS(struct Node* root)
{
	if(root == NULL)
	{
		printf("\t\t\t\t\tThere Is No Node In Tree \n");
	}
	else
	{
		struct Queue* ptr = createQueue(root);

		insertQueue(ptr,root);

		while(ptr -> front != ptr -> rear)
		{
			struct Node* currentNode = peek(ptr);

			printf("\t|  %d  | \n",currentNode->data);
			if(currentNode->leftNode != NULL && currentNode->rightNode != NULL)
			{
				if(currentNode->leftNode != NULL)
				{
					insertQueue(ptr,currentNode->leftNode);
				}
				if(currentNode->rightNode != NULL)
				{
					insertQueue(ptr,currentNode->rightNode);
				}
			}
			
			(ptr->front)++;
		}
	}
}


void displayTree(struct Node* root)
{
	int ch ;
	do
	{	
		printf("\n\t\tChoose Traversal : \n");
		printf("\t\t\t\t1. Pre-Order \n");
		printf("\t\t\t\t2. In-Order \n");
		printf("\t\t\t\t3. Post-Order \n");
		printf("\t\t\t\t4. Breadth First Search \n");
		printf("\t\t\t\t0. Back \n");

		printf("\t\t\tEnter Traversal : ");
		scanf("%d",&ch); 
		printf("\n");

		switch(ch)
		{
			case 1:
				preOrder(root);
				break;
			case 2:
				inOrder(root);
				break;
			case 3:
				postOrder(root);
				break;
			case 4:
				BFS(root);
				break;
			default:
				printf("\t\t\t\tInvalid Choice !\n");
				break;
		}
	}while(ch != 0);
}

	

void main()
{
	struct Node* root = NULL;
	int choice ;
	do
	{

		printf("\tPlease Select choice : \n");
		printf("\t\t1 . Create Binary Search Tree \n");
		printf("\t\t2 . Traverse Binary Search Tree \n");
		printf("\t\t0 . Exit !\n");

		printf("\t\tPlease Enter choice : ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice){

		case 1 : 
			createBST(&root);
			break;
		case 2 :
			displayTree(root);
			break;
		default:
			printf("\t\t\tInvalid Choice !\n");
		}
	}while(choice != 0);
}
