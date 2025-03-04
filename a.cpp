#include <iostream>
#include <string>

struct node
{
    int data;
    node *next;
};




int main(void)
{
    int a = 10;
    node *node_1 = (node*)malloc(sizeof(node));
    node_1->data = 1;
    node_1->next = (node*)malloc(sizeof(node));
    node_1->next->data = 2;
    return 0;
}