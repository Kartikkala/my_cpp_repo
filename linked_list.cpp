#include <iostream>

struct node{
    node *rear;
    int data;
    int priority;
    node *next;
};

node *front = nullptr;
node *rear = nullptr;

void enqueue(int data)
{
    if(rear == nullptr)
    {
        rear = (node *)malloc((sizeof(node)));
        rear->next = nullptr;
        rear->data = data;
        front = rear;
        return;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = rear; 
    newNode->data = data;
    rear = newNode; // New node became latest rear node
    return;
}

node *get_second(node *rear)
{
    while(rear->next->next !=nullptr)
    {
        rear = rear->next;
    }
    return rear;
}

void dequeue()
{
    if(front == nullptr)
    {
        return;
    }
    node *second = get_second(rear);
    free(front);
    front = second;
    second->next = nullptr;
    return;
}

void traverse(node *rear)
{
    std::cout <<std::endl;
    std::cout <<std::endl;
    while(rear !=nullptr)
    {
        std::cout << rear->data<<std::endl;
        rear = rear->next;
    }
}

int search(node *temp, int key)
{
    int posi = 0;
    while(temp !=nullptr)
    {
        if(temp->data == key)
        {
            return posi;
        }
        temp = temp->next;
        posi++;
    }
    return -1;
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    traverse(rear);

    dequeue();
    

    traverse(rear);

    // std::cout << search(front, 90);
}