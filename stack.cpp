#include <iostream>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

class Stack{
    private:
        struct node *stack = nullptr;
        int top = -1;
    public:

        Stack()
        {
            this->stack = new struct node;
            this->stack->data = 0;
            this->stack->next = nullptr;
            this->stack->prev = nullptr;
            this->top++;
        }
        Stack(int data)
        {
            this->stack = new struct node;
            this->stack->data = data;
            this->stack->next = nullptr;
            this->stack->prev = nullptr;
            this->top++;
        }

        struct node *get_curr()
        {
            return this->stack;
        }

        Stack *push(int data)
        {
            this->stack->next = new struct node;
            this->stack->next->data = data;
            this->stack->next->prev = this->stack;
            this->stack = this->stack->next;
            this->top++;
            return this;
        }

        Stack *pop()
        {
            this->stack = this->stack->prev;
            delete this->stack->next;
            this->stack->next = nullptr;
            this->top--;
            return this;
        }

        int search(int key)
        {
            struct node *temp = this->stack;
            int index = this->top;
            while(temp !=nullptr)
            {
                if(temp -> data == key)
                {
                    return index;
                }
                temp = temp->prev;
                index--;
            }
            return -1;
        }

        void print_all()
        {
            struct node *temp = this->stack;
            while(temp !=nullptr)
            {
                std::cout << temp->data << std::endl;
                temp = temp->prev;
            }
        }

        int get_top()
        {
            return this->top;
        }
};

int main(void)
{
    Stack s(2);
    s.push(3)->push(30)->push(40)->push(50)->push(180);
    // s.print_all();

    std::cout << s.search(40);
    // std::cout << s.get_curr()->data;
}