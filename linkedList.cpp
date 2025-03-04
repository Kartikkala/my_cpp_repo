#include <iostream>
#include <stdlib.h>

struct node{
    node *prev;
    int data;
    node *next;
};

class LinkedList{
    private:
        struct node *list = nullptr;
    public:
        LinkedList(int data)
        {
            this->list = (node*) malloc(sizeof(node));
            this->list->prev = nullptr;
            this->list->next = nullptr;
            this->list->data = data;
        }

        LinkedList* addNodeLast(int data)
        {
            node *temp = this->list;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = (node *)malloc(sizeof(node));
            temp->next->prev = temp;
            temp->next->data = data;
            temp->next->next = nullptr;
            return this;
        }

        LinkedList* addNodeStart(int data)
        {
            this->list->prev = (node *)malloc(sizeof(node));
            this->list->prev->prev = nullptr;
            this->list->prev->next = this->list;
            this->list->prev->data = data;
            this->list = this->list->prev;
            return this;
        }

        LinkedList *insertAtPosition(int data, int position)
        {
            if(position < 0)
            {
                return this;
            }
            int currPosi = 0;
            node *temp = this->list;

            while (currPosi < position-1 && temp->next !=nullptr)
            {
                temp = temp->next;
                currPosi++;
            }
            node *nextNode = temp->next;
            node *newNode = (node *)malloc(sizeof(node));
            temp->next = newNode;
            temp->next->next = nextNode;
            temp->next->data = data;
            temp->next->prev = temp;
            return this;
        }

        LinkedList* displayAllElements()
        {
            node *temp = this->list;
            while(temp!=nullptr)
            {
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
            return this;
        }
};

int main(void)
{
    LinkedList l1(2);

    l1.addNodeLast(5)->addNodeLast(8)->addNodeLast(10)->addNodeLast(25)->insertAtPosition(25, 3)->addNodeStart(1)->displayAllElements();
}