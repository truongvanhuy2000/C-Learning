#include <iostream>
enum HeapType
{
    MaxHeap,
    MinHeap
};
class Heap
{
    int* mArray;
    int mCount;
    int mCapacity;
    HeapType mHeapType;
    public:
    Heap(int cap, HeapType type)
    {
        mArray = new int[cap];
        mCapacity = cap;
        mCount = 0;
        mHeapType = type;
    }
    ~Heap(){}
    int getParent(int i) // i is position of node i
    {
        if(i<=0 || i >= mCount)
        {
            return -1;
        }
        return (i-1)/2;
    }
    int getLeftChild(int i) // i is position of node i
    {
        int left = 2*i + 1;
        if(left >= mCount)
        {
            return -1;
        }
        return left;
    }
    int getRightChild(int i) // i is position of node i
    {
        int right = 2*i + 2;
        if(right >= mCount)
        {
            return -1;
        }
        return right;
    }
    void sinkDown(int i)
    {
        int left,right,max, temp;
        left = getLeftChild(i);
        right = getRightChild(i);
        max = i;
        if(left != -1 && mArray[left] > mArray[max])
        {
            max = left;
        }
        if(right != -1 && mArray[right] > mArray[max])
        {
            max = right;
        }
        if(max != i)
        {
            temp = mArray[i];
            mArray[i] = mArray[max];
            mArray[max] = temp;
            sinkDown(max);
        }
    }
    void bubbleUp(int i)
    {
        int parent, temp;
        parent = getParent(i);
        if(parent != -1 && mArray[parent] < mArray[i])
        {
            temp = mArray[parent];
            mArray[parent] = mArray[i];
            mArray[i] = temp;
            bubbleUp(parent);
        }
    }
    void EnQueue(int data)
    {
        if(mCount == mCapacity)
        {
            throw "shit, a bug, fix later";
        }
        mCount++;
        mArray[mCount-1] = data;
        bubbleUp(mCount-1);
    }
    int DeQueue()
    {
        int returnValue = mArray[0];
        mArray[0] = mArray[mCount - 1];
        mArray[mCount - 1] = 0;
        sinkDown(0);
        mCount--;
        return returnValue;
    }
    void print()
    {
        for(int i = 0; i < mCount; i++)
        {
            std::cout << mArray[i] << ", ";
        }
    }
};
int main()
{
    Heap newHeap(20, MaxHeap);
    newHeap.EnQueue(9);
    newHeap.EnQueue(7);
    newHeap.EnQueue(6);
    newHeap.EnQueue(8);
    newHeap.EnQueue(1);
    newHeap.EnQueue(2);
    newHeap.EnQueue(5);
    newHeap.EnQueue(15);
    newHeap.EnQueue(12);
    newHeap.EnQueue(10);
    newHeap.print();
    std::cout << std::endl;
    newHeap.DeQueue();
    newHeap.print();
    return 0;
}