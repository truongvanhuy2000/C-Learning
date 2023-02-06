#include <iostream>
struct Node
{
    int data;
    Node* next;
};
class Stack
{
    int mMaxStack;
    int mCurrentStack;
    Node* mHeadNode = nullptr;
    public:
    Stack(int maxStack)
    {
        mMaxStack = maxStack;
    }
    ~Stack(){}
    void push(int dat)
    {
        if(isFull())
        {
            throw "Stack Full";
        }
        mCurrentStack++;
        Node* newNode = new Node{dat, mHeadNode};
        mHeadNode = newNode;
    }
    int pop()
    {
        Node* traverseNode = mHeadNode;
        int data = mHeadNode->data;
        if(isEmpty())
        {
            throw "Stack Empty";
        }
        mCurrentStack--;
        mHeadNode = mHeadNode->next;
        delete traverseNode;
        return data;
    }
    bool isEmpty()
    {
        if(mHeadNode == nullptr)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if(mCurrentStack == mMaxStack)
        {
            return true;
        }
        return false;
    }
    int top()
    {
        return mHeadNode->data;
    }
};
int main()
{
    Stack* newStack = new Stack(10);
    std::cout << "Stack Push: " << std::endl;
    for(int i = 0; i < 10; i++)
    {
        newStack->push(i);
        std::cout << newStack->top() << std::endl;
    }
    std::cout << "Stack Pop: " << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout << newStack->pop() << std::endl;
    }
    return 0;
}