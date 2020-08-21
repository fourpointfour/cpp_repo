#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[], int heap_size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < heap_size && arr[left] > arr[largest])
        largest = left;
    if(right < heap_size && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, heap_size, largest);
    }
}
void heap_sort(int arr[], int array_size)
{
    for(int i = array_size/2 - 1; i >= 0; --i)
        heapify(arr, array_size, i);
    cout<<"\nArray after heapify:\n";
    for(int i = 0; i < array_size; ++i)
        cout<<arr[i]<<' ';
    cout<<endl;
    for(int i = array_size - 1; i >= 0; --i)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {2, 1, 4, 23, 34, 14, 9, 10, 6, 43};
    cout<<"Array before heap sort:\n";
    for(int x : arr)
        cout<<x<<' ';
    heap_sort(arr, 10);
    cout<<"\nArray after heap sort:\n";
    for(int x : arr)
        cout<<x<<' ';    
    cout<<endl;
    return 0;
}