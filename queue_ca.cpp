#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* front = nullptr;
    Node* rear = nullptr;

public:
    Queue() = default;

    Queue(T data) {
        front = rear = new Node(data);
    }

    Queue* enqueue(T data) {
        Node* temp = new Node(data);
        if (!rear) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        return this;
    }

    Queue* dequeue() {
        if (!front) {
            std::cout << "Queue is empty!" << std::endl;
            return this;
        }

        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;

        std::cout << "Dequeued: " << temp->data << std::endl;
        delete temp;
        return this;
    }

    Queue* traverse() {
        std::cout << "\nQueue:\n";
        Node* temp = front;
        while (temp) {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
        return this;
    }

    Queue* requeue() {
        if (!front || !front->next) {
            std::cout << "Too few elements!" << std::endl;
            return this;
        }

        Node* temp = front;
        front = front->next;
        rear->next = temp;
        temp->next = nullptr;
        rear = temp;

        return this;
    }

    bool empty() const {
        return front == nullptr;
    }
    
    T front_value() const {
        if (front == nullptr) {
            throw std::runtime_error("Queue is empty!");
        }
        return front->data;
    }    

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};
