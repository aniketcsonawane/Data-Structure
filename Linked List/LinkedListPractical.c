#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char* name[100];
    int marks;
    struct Node* next;
};

struct Node* createNode()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL)
    {
        printf("Memory Not Allocated\n");
    }
    else
    {
        char name1[100] ="" ;
        int marks;
        printf("\n\t Enter The Name ");
        fgets(newNode->name,sizeof(newNode->name),stdin);
        printf("\n\t Enter The Marks ");
        scanf("%d",&marks);

        
        newNode -> marks = marks;
        newNode -> next = NULL;

        return newNode;

    }
}

void createLinkedList(struct Node** head)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* currentNode = *head;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while(currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }

}

void displayLinkedList(struct Node* head)
{
    if(head == NULL)
    {
        printf("\n\t List Is Empty");
    }
    else
    {
        while(head !=NULL)
        {
            if(head->next != NULL)
                printf("[ %c| %d | %u ]", head->name, head ->marks, head->next);
            else
                printf("[ %s| %d | NULL ]", head->name, head ->marks);

            head = head->next;
        }
    }

}


void main()
{
    struct Node* First = (struct Node*)malloc(sizeof(struct Node));
    int ch;
    do{
    printf(" Please Select The Following Choices : \n");
    printf("\t 1. Create Linked List \n\t 2. Display Linked List \n\t 0. Exit \n");
    printf("\t Please Enter Your Choice : \n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            createLinkedList(&First);
            break;
        case 2:
            displayLinkedList(First);
            break;
        default:
            printf("\n\t Invalid Choice");
    }

    }while(ch!=0);

}