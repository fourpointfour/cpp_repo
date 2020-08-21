#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
class MaxHeap
{
    int *harr;
    int heap_size;
    int heap_capacity;

    public:
        MaxHeap(int);
        void insertKey(int k);
        int parent(int);
        int left_child(int);
        int right_child(int);
        int deleteKey();
        void MaxHeapify(int);
};
// Declaring a constructor for creating a max heap
MaxHeap::MaxHeap(int c)
{
    cout<<"Heap declared successfully...\n";
    heap_capacity = c;
    harr = new int[heap_capacity];
    heap_size = 0;
}

// Defining function to get the parent key's index
int MaxHeap::parent(int i)
{
    return (i-1)/2;
}

//Defining function to return left child's index
int MaxHeap::left_child(int i)
{
    return (2 * i + 1);
}

int MaxHeap::right_child(int i)
{
    return (2 * i + 2);
}

void MaxHeap::insertKey(int k)
{
    if(heap_capacity == heap_size)
    {
        cout<<"Overflow!\nCan't insert more elements.";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while(i != 0 && harr[parent(i)] < harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::MaxHeapify(int i)
{
    int left = left_child(i);
    int right = right_child(i);
    int largest = i;
    if(left < heap_size && harr[left] > harr[largest])
        largest = left;
    if(right < heap_size && harr[right] > harr[largest])
        largest = right;
    if(largest != i)
    {
        swap(harr[i], harr[largest]);
        MaxHeapify(largest);
    }
}

int main()
{
    MaxHeap hp(10);
    hp.insertKey(1);
    hp.insertKey(2);
    hp.insertKey(3);
    hp.insertKey(4);
    hp.insertKey(7);
    hp.insertKey(9);
    hp.insertKey(99);
    return 0;
}