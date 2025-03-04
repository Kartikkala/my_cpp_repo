#include <iostream>
#define MAX 5 
using namespace std;

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
bool isEmpty() {
    if(rear == -1 && front == -1)
        return true;
    return false;
}

// Function to check if the queue is full
bool isFull() 
{
    if(rear >= MAX)
        return true;
    return false;
}

void enqueue(int value) 
{
    if(rear == MAX-1)
        return;
    if(front == -1 && rear == -1)
    {
        front++;
    }
    rear++;
    queue[rear] = value;
    std::cout << "Rear: " << rear << " Front: " << front << std::endl;
}


void dequeue() 
{
    if(front==-1 && rear == -1)
    {
        std::cout << "Nothing in queue!";
        return;
    }
    queue[front] = 0;
    front++;
    if(front >= rear)
    {
        front = -1;
        rear = -1;
    }
    std::cout << "Rear: " << rear << " Front: " << front << std::endl;
}


void TravrseQueue() 
{
    if(front == -1 && rear == -1)
    {
        cout << "Underflow!";
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        std::cout << queue[i]<<std::endl;
    }
}

void SearchQueue(int value)
{
    if(front == -1 && rear == -1)
    {
        cout << "Underflow!";
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        if(queue[i] == value)
        {
            cout << "Present";
            return;
        }
    }
    std::cout << "Not present!";
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse \n";
	    cout << "4. Search\n";
        cout << "5. IsEmpty\n";
        cout << "6. IsFull\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                TravrseQueue();
                break;
            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                SearchQueue(value);
                break;
            case 5:
                cout << isEmpty();
                break;
            case 6:
                cout << isFull();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}