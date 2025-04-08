#include <iostream>
#include <string>

using namespace std;

struct node{
    struct node* next;
    string data;
};

class Queue{
    private:
        struct node *front = nullptr;
        struct node *rear = nullptr;
    public:
        Queue(string data){
            this->front = (node *)malloc(sizeof(node));
            this->rear = this->front;
            this->rear->data = data;
            this->rear->next = nullptr;
        }

        Queue *enqueue(string data)
        {
            struct node *temp = (node *)malloc(sizeof(node));
            temp->next = this->rear;
            this->rear = temp;
            temp->data = data;
            return this;
        }

        Queue *dequeue()
        {
            struct node *temp = this->rear;
            if(!this->front || !this->rear)
            {
                std::cout << "Queue is empty!"<<std::endl;
                return this;
            }
            if(temp->next !=nullptr){
                while(temp->next->next != nullptr)
                {
                    temp = temp->next;
                }
            }

            std::cout << "Dequeued :" << this->front->data<<std::endl;

            free(this->front);
            this->front = temp;
            temp->next = nullptr;
            return this;
        }

        Queue *traverse()
        {
            std::cout <<std::endl;
            struct node *temp = this->rear;
            while(temp !=nullptr)
            {
                std::cout << temp->data<<std::endl;
                temp = temp->next;
            }
            return this;
        }

        Queue *requeue()
        {
            if(this->rear == nullptr || this->rear->next == nullptr)
            {
                std::cout << "Too few elements!"<<std::endl;
                return this;
            }

            struct node *temp = this->rear;
            if(temp->next !=nullptr)
            {
                while(temp->next->next !=nullptr)
                {
                    temp = temp->next;
                }
            }
            this->front->next = this->rear;
            this->rear = this->front;
            this->front = temp;
            
            temp->next = nullptr;
            return this;
        }

};

int main(void)
{
    string data;
    int n = 4;
    Queue q("Elf");
    q.enqueue("Dwarf")->enqueue("Fairy")->enqueue("Goblin")->enqueue("Centaur");
    q.traverse();

    // Q2
    q.requeue()->requeue()->dequeue()->dequeue();
    q.traverse(); 
}