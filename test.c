#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Changes: 
/*  1. Now nodes are freed before nullifying.
    2. Removed the delete at any pos fuction (too dangerous)
    3. Lot of fixes are required.


    Recommendations:
    
    1. Try not to make global variables. If this program was made for test then it is ok, otherwise, foe e.g. head in this program was global (which should not be done.)
    2. If u wont make global variables, then you need to make functions which take arguments.
    3. Don't make dangerous functions like that insert at any pos.
    4. Free the node before nullifying them.
    5. Try using another structure or variable for storing stating and ending pos of linked list. That would be much efficient. Time complexity for delete operation will be reduced to O(1) from O(n).
*/

void display();
void insertAtBeginning();
void insertAtEnd();
void deleteAtBeginning();
void deleteAtEnd();
void deleteByValue();

struct node
{ 
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

int main()
{       
    insertAtBeginning();
    display();           
    insertAtBeginning(); 
    display();
    deleteByValue();
    display();

 return 0;
}

void display()
{
    struct node *temp = head;

    printf("NULL ->");
    while(temp != NULL)
    {
        printf(" %d -> ",temp->data);
        temp = temp->next; 
    }   
    printf("NULL\n");
}

void insertAtBeginning()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter The Data To Insert At Beginning: ");
    scanf("%d",&newNode->data);

    if(head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
    printf("Insertion At Beginning Done.\n");
}

void deleteByValue()
{
    struct node *temp = head;
    int val;
    printf("\nEnter the value: ");
    scanf("%d", &val);
    while (temp->data != val && temp->next !=NULL)
    {
        temp = temp->next;
    }
    printf("%d",temp->data);
    if (temp->prev == NULL) //  deletion At Beginning
    {
        head = temp->next;
        free(temp);
        temp = NULL;
    }
    else if (temp->next == NULL) // At End
    {
        temp->prev->next = NULL;
        free(temp); // last node
        // temp = NULL;
    }
    else // Anywhere
    {
        struct node *ptr = temp->prev;      //Storing Current Node (which is equal to value)
        ptr->next = temp->next;             //Next of node before temp = next of temp 
        temp->next->prev = ptr;             
        free(temp);
    }
}

void insertAtEnd()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter The Data To Insert At End: ");
    scanf("%d",&newNode->data);

    if(head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        struct node *temp = head;
        while(temp->next != NULL)
        {
           temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}


void deleteAtBeginning()
{
     if(head == NULL)   // List Empty
     {
        printf("\nUnderflow, Cannot Delete, List Empty.\n");
     }
     else if(head->next == NULL)    // One Node
     {
        head = NULL;
        free(head);
     }
     else // More than One Node
     {
        struct node *temp = head;    
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("\nDeletion At Beginnig Done.\n");
     }
}

void deleteAtEnd()
{
    if(head == NULL) // NO Node
    {
        printf("Underflow, Cannot Delete, List Empty");
    }
    else if(head->next == NULL)    // One Node
    {
        free(head);         //First free
        head = NULL;        //Then nullify
        printf("\nDeletion At End Done by cond 2\n");
    }
    else  
    {
        struct node *temp = head;
        while(temp->next->next != NULL)     //Iteration until temp->next->next is not NULL
        {
            temp = temp->next;
        }
        free(temp->next);                   //Freed the next node
        temp->next = NULL;                  //Nullify the next node after freeing
        printf("\nDeletion At End Done\n");

    }
}