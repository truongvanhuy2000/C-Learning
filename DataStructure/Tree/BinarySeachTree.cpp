#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class BinaryTree
{
    Node* mTreeRoot = nullptr;
    void recursiveInsert(int data, Node** root)
    {
        if(*root != nullptr)
        {
            if(data >= (*root)->data)
            {
                recursiveInsert(data, &(*root)->right);
                return;
            }
            recursiveInsert(data, &(*root)->left);
            return;
        }
        *root = new Node{data, nullptr, nullptr};
    }
    void case1Remove(Node** root) // no children
    {
        *root = nullptr;
    }
    void case2Remove(Node** root)  // either one of the child node present
    {
        if((*root)->left != nullptr)
        {
            *root = (*root)->left;
        }
        if((*root)->right != nullptr)
        {
            *root = (*root)->right;
        }
    }
    void case3Remove(Node** root) // both left node and right node present
    {
        Node** traverseNode = root;
        traverseNode = &(*traverseNode)->right;
        while((*traverseNode)->left != nullptr)
        {
            traverseNode = &(*traverseNode)->left;
        }
        (*root)->data = (*traverseNode)->data;
        *traverseNode = (*traverseNode)->right;
    }
    public:
    BinaryTree(){}
    ~BinaryTree(){}
    void recursiveInsert(int data)
    {
        Node* insertNode = nullptr;
        if(mTreeRoot == nullptr)
        {
            insertNode = new Node{data, nullptr, nullptr};
            mTreeRoot = insertNode;
            return;
        }
        recursiveInsert(data, &mTreeRoot);
    }
    void iterativeInsert(int data)
    {
        Node** traverseNode = &mTreeRoot;
        if(mTreeRoot == nullptr)
        {
            mTreeRoot = new Node{data, nullptr, nullptr};
            return;
        }
        while(*traverseNode != nullptr)
        {
            if(data >= (*traverseNode)->data)
            {
                traverseNode = &((*traverseNode)->right);
            }
            else
            {
                traverseNode = &((*traverseNode)->left);
            }
        }
        *traverseNode = new Node{data, nullptr, nullptr};
    }
    void removeNode(int data)
    {
        Node** node;
        node = seach(data);
        if((*node)->left != nullptr && (*node)->right != nullptr) // both left node and right node present
        {
            case3Remove(node);
            return;
        }
        if((*node)->left == nullptr && (*node)->right == nullptr) // no children
        {
            case1Remove(node);
            return;
        }
        if((*node)->left != nullptr || (*node)->right != nullptr) // either one of the child node present
        {
            case2Remove(node);
            return;
        }
    }
    Node** seach(int data)
    {
        Node** traverseNode = &mTreeRoot;
        while(*traverseNode != nullptr)
        {
            if(data > (*traverseNode)->data)
            {
                traverseNode = &(*traverseNode)->right;
            }
            else if(data < (*traverseNode)->data)
            {
                traverseNode = &(*traverseNode)->left;
            }
            else
            {
                return traverseNode;
            }
        }
        cout << "not exist" << endl;
        return nullptr;
    }
    void preOrderTraverse(Node* root)
    {
        if(root)
        {
            cout << root->data << endl;
            preOrderTraverse(root->left);
            preOrderTraverse(root->right);
        }
        return;
    }
    void inOrderTraverse(Node* root)
    {
        if(root)
        {
            inOrderTraverse(root->left);
            cout << root->data << endl;
            inOrderTraverse(root->right);
        }
        return;
    }
    void postOrderTraverse(Node* root)
    {
        if(root)
        {
            postOrderTraverse(root->left);
            postOrderTraverse(root->right);
            cout << root->data << endl;
        }
        return;
    }
    Node* getRootNode()
    {
        return mTreeRoot;
    }
    void printBT(const std::string& prefix, Node* node, bool isLeft)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            std::cout << node->data << std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }
    void printBT(Node* node)
    {
        printBT("", node, false);    
    }
};
int main()
{
    BinaryTree* newTree= new BinaryTree();
    newTree->recursiveInsert(10);
    newTree->recursiveInsert(4);
    newTree->recursiveInsert(12);
    newTree->recursiveInsert(3);
    newTree->recursiveInsert(2);
    newTree->recursiveInsert(15);
    newTree->recursiveInsert(14);
    newTree->recursiveInsert(2);
    newTree->recursiveInsert(3);
    newTree->recursiveInsert(24);
    newTree->recursiveInsert(1);
    newTree->recursiveInsert(8);
    newTree->recursiveInsert(7);
    newTree->recursiveInsert(6);
    newTree->recursiveInsert(3);
    newTree->recursiveInsert(5);
    newTree->recursiveInsert(9);
    newTree->printBT(newTree->getRootNode());
    newTree->removeNode(8);
    newTree->printBT(newTree->getRootNode());
    return 0;
}