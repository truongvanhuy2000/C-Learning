#include <iostream>
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
class SingleLinkedList
{
    Node* mHeadNode;
    public:
    SingleLinkedList(Node *headNode) : mHeadNode(headNode){}
    ~SingleLinkedList()
    {
        delete mHeadNode;
        mHeadNode = nullptr;
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
        traverseNode = nullptr;
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
        //modify the node
        node->prev = traverseNode;
        node->next = nullptr;
        //insert to list
        traverseNode->next = node;
        traverseNode = nullptr;
    }
    void addNode(Node *insertNode, int pos)
    {
        int count = 0;
        Node *traverseNode1 = mHeadNode;
        if(pos == 0)
        {
            //modify the node
            insertNode->next = traverseNode1;
            insertNode->prev = nullptr;
            //insert to list
            traverseNode1->prev = insertNode;
            mHeadNode = insertNode;
            return;
        }
        if(pos > getListLength())
        {
            throw "position exceed list length";
            return;
        }
        while(count != pos)
        {
            traverseNode1 = traverseNode1->next;
            count++;
        }
        //modify insert node next and prev
        insertNode->prev = traverseNode1->prev;
        insertNode->next = traverseNode1;
        //inserting node to the list
        traverseNode1->prev->next = insertNode;
        traverseNode1->prev = insertNode;
        traverseNode1 = nullptr;
    }
    void removeNode()
    {
        Node* traverseNode = mHeadNode;
        while(traverseNode->next != nullptr)
        {
            traverseNode = traverseNode->next;
        }
        //remove from list
        traverseNode->prev->next = nullptr;
        //modify the last node
        traverseNode->next = nullptr;
        traverseNode->prev = nullptr;
        delete traverseNode;
        traverseNode = nullptr;
    }
    void removeNode(int pos)
    {
        int count = 0;
        Node *traverseNode1 = mHeadNode;
        if(pos > getListLength())
        {
            throw "position exceed list length";
            return;
        }
        if(pos == 0)
        {
            //remove from list
            traverseNode1->next->prev = nullptr;
            mHeadNode = traverseNode1->next;
            //modify the node
            traverseNode1->next = nullptr;
            traverseNode1->prev = nullptr;

        }
        while(count != pos)
        {
            count++;
            traverseNode1 = traverseNode1->next;
        }
        //remove from list
        traverseNode1->prev->next = traverseNode1->next;
        traverseNode1->next->prev = traverseNode1->prev;
        //modify the node
        traverseNode1->next = nullptr;
        traverseNode1->prev = nullptr;
        delete traverseNode1;
        traverseNode1 = nullptr;
    }
    void printList()
    {
        int count = 0;
        Node *traverseNode = mHeadNode;
        std::cout << "Linked List: " << std::endl;
        while(count <= getListLength())
        {
            if(traverseNode->next != nullptr && traverseNode->prev != nullptr)
            {
                std::cout << "Node " << count << " data: " << traverseNode->data <<" prev: " << traverseNode->prev->data << " next: " << traverseNode->next->data << std::endl;
            }
            else
            {
                std::cout << "Node " << count << " data: " << traverseNode->data << std::endl;
            }
            traverseNode = traverseNode->next;
            count++;
        }
        traverseNode = nullptr;
    }
};
Node* node1 = new Node{5, nullptr, nullptr};
Node* node2 = new Node{10, nullptr, nullptr};
Node* node3 = new Node{20, nullptr, nullptr};
Node* node4 = new Node{13, nullptr, nullptr};
Node* node5 = new Node{8, nullptr, nullptr};
Node* node6 = new Node{6, nullptr, nullptr};
Node* node7 = new Node{4, nullptr, nullptr};
Node* addNode1 = new Node{155, nullptr, nullptr};
Node* addNode2 = new Node{195, nullptr, nullptr};
Node* newHeadNode = new Node{200, nullptr, nullptr};
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
    return 0;
}