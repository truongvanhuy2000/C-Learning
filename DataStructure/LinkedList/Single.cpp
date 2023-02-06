#include <iostream>
struct Node
{
    int data;
    Node* next;
};
class SingleLinkedList
{
    Node* mHeadNode;
    public:
    SingleLinkedList(Node *headNode) : mHeadNode(headNode){}
    ~SingleLinkedList()
    {
        delete mHeadNode;
    }
    int getListLength()
    {
        int count = 0;
        Node* traverseNode = mHeadNode;
        while(traverseNode->next != nullptr)
        {
            count++;
            traverseNode = traverseNode->next;
        }
        return count;
    }
    bool isEmpty()
    {
        if(mHeadNode->next = nullptr)
        {
            return true;
        }
        return false;
    }
    void addNode(Node *node)
    {
        Node* traverseNode = mHeadNode;
        while(traverseNode->next != nullptr)
        {
            traverseNode = traverseNode->next;
        }
        traverseNode->next = node;
        node->next = nullptr;
    }
    void addNode(Node *insertNode, int pos)
    {
        int count = 0;
        Node *traverseNode1 = mHeadNode;
        Node *traverseNode2 = mHeadNode;
        if(pos == 0)
        {
            mHeadNode = insertNode;
            mHeadNode->next = traverseNode1;
            return;
        }
        if(pos > getListLength())
        {
            throw "position exceed list length";
            return;
        }
        while(count != pos)
        {
            traverseNode2 = traverseNode1;
            traverseNode1 = traverseNode1->next;
            count++;
        }
        traverseNode2->next = insertNode;
        insertNode->next = traverseNode1;
    }
    void removeNode()
    {
        int count = 0;
        Node* traverseNode = mHeadNode;
        while(count < getListLength() - 1)
        {
            count++;
            traverseNode = traverseNode->next;
        }
        delete traverseNode->next;
        traverseNode->next = nullptr;
    }
    void removeNode(int pos)
    {
        int count = 0;
        Node *traverseNode1 = mHeadNode;
        Node *traverseNode2 = mHeadNode;
        if(pos > getListLength())
        {
            throw "position exceed list length";
            return;
        }
        if(pos == 0)
        {
            mHeadNode = mHeadNode->next;
        }
        while(count != pos)
        {
            count++;
            traverseNode2 = traverseNode1;
            traverseNode1 = traverseNode1->next;
        }
        traverseNode2->next = traverseNode1->next;
        delete traverseNode1;
    }
    void printList()
    {
        int count = 0;
        Node *traverseNode = mHeadNode;
        std::cout << "Linked List: " << std::endl;
        while(count <= getListLength())
        {
            if(traverseNode->next != nullptr)
            {
                std::cout << "Node " << count << " data: " << traverseNode->data << " next: " << traverseNode->next->data << std::endl;
                traverseNode = traverseNode->next;
            }
            else
            {
                std::cout << "Node " << count << " data: " << traverseNode->data << std::endl;
            }
            count++;
        }
    }
};
Node* node1 = new Node{5, nullptr};
Node* node2 = new Node{10, nullptr};
Node* node3 = new Node{20, nullptr};
Node* node4 = new Node{13, nullptr};
Node* node5 = new Node{8, nullptr};
Node* node6 = new Node{6, nullptr};
Node* node7 = new Node{4, nullptr};
Node* addNode1 = new Node{155, nullptr};
Node* addNode2 = new Node{195, nullptr};
Node* newHeadNode = new Node{200, nullptr};
int main()
{
    SingleLinkedList linkedList1(node1);
    linkedList1.addNode(node2);
    linkedList1.addNode(node3);
    linkedList1.addNode(node4);
    linkedList1.addNode(node5);
    linkedList1.addNode(node6);
    linkedList1.addNode(node7);
    linkedList1.getListLength();
    linkedList1.printList();
    linkedList1.addNode(addNode1, 5);
    linkedList1.addNode(addNode2);
    linkedList1.printList();
    linkedList1.removeNode(6);
    linkedList1.removeNode();
    linkedList1.printList();
    linkedList1.addNode(newHeadNode, 1);
    linkedList1.printList();
    linkedList1.removeNode(1);
    linkedList1.printList();
    linkedList1.removeNode(6);
    linkedList1.printList();
    return 0;
}