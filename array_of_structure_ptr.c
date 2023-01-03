#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    char character;
}node;



int main(void)
{
    node *structure_ptr1 = (node *)malloc(sizeof(node));        //First pointer to structure
    node *structure_ptr2 = (node *)malloc(sizeof(node));        //Second pointer to structure 
    node *structure_ptr3 = (node *)malloc(sizeof(node));        //Third pointer to structure 
    node *structure_ptr4 = (node *)malloc(sizeof(node));        //Fourth pointer to structure 


    //Initializing structure pointers

    structure_ptr1->number = 100;
    structure_ptr1->character = 'a';

    structure_ptr2->number = 200;
    structure_ptr2->character = 'b';  

    structure_ptr3->number = 300;
    structure_ptr3->character = 'c';  

    structure_ptr4->number = 400;
    structure_ptr4->character = 'd';  

    //Declaring the array dynamically for structure pointers

    node ***structure_array = (node ***)malloc(sizeof(node ***) * 2);  //Note that double pointer is used for pointer to pointer
    for(int i=0;i<2;i++)
    {
        structure_array[i] = (node **)malloc(sizeof(node**));
    }


    //Initializing the array of structure pointers

    structure_array[0][0] = structure_ptr1;
    structure_array[0][1] = structure_ptr2;
    structure_array[1][0] = structure_ptr3;
    structure_array[1][1] = structure_ptr4;

    //Printing the values of these structure pointers from array


    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%c - ", structure_array[i][j]->character);
            printf("%d\t\t", structure_array[i][j]->number);
        }
        printf("\n");
    }

    printf("%lu",sizeof(structure_array[1][1]));

}

    
    
    
    // for(int i=0;i<4;i++)
    // {
    //     printf("%c - ", structure_array[i]->character);
    //     printf("%d\t\t", structure_array[i]->number);
    //     printf("\n");
    // }