#include <iostream>
struct Node
{
    int data;
    Node* next;
};
class Queue
{
    Node* front = nullptr;
    Node* rear = nullptr;
    public:
    Queue(){}
    ~Queue(){}
    void enQueue(int dat)
    {
        Node* insertNode = new Node{dat, nullptr};
        Node* traverseNode = rear;
        if(isEmpty())
        {
            front = insertNode;
            rear = insertNode;
        }
        rear->next = insertNode;
        rear = insertNode;
    }
    int deQueue()
    {
        Node* traverseNode = front;
        int data;
        if(isEmpty())
        {
            throw "Empty Queue";
        }
        front = front->next;
        data = traverseNode->data;
        delete traverseNode;
        return data;
    }
    bool isEmpty()
    {
        if(front == nullptr)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue* newQueue = new Queue;
    for(int i = 0; i < 10; i++)
    {
        newQueue->enQueue(i);
    }
    std::cout << "De Queue: " << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout << newQueue->deQueue() << std::endl;
    }
    return 0;
}