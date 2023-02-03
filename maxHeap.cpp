#include <iostream>
#include <vector>

/* This file contains the implementation of max heap data structure.
 A heap is a complete binary tree. A max heap is a heap where the parent node is greater.
 than its child nodes (or equal to its child nodes if duplicate elements are allowed).

Note: This implementation of max heap is not comprehensive and meant for educational purposes.
It lacks some standard operations such as inserting a node or extracting max element out of the heap.
This implementation shows how to build a max heap out of an array of distorted elements.

The most two important operations: 'shif down' and 'sift up' were implemented.
The names are just conventional. There are other terms for 'sift-down' operation such as 'bubble down', 'sink', 'heapify'
and the same goes for 'sift-up' operation.

These operations are required to maintain the heap property.
In general a heap has two properties
 - Heap property - For a max heap, the parent node must be greater than or equal to its children
 - Shape property - A heap must be a complete binary tree

 the heap proprety meaks it easy to extract the maximum element from a heap in O(1) time
 due to that fact that the maximum element is always at the root.

 the shape property makes it easy to insert and delete a node in O(log n) time.
 This is because the height of a complete binary tree with n nodes is O(log n).

Heap data structure has different applications such as implemention a priority queue,
heap sort algorithm, implementing some graph algorithms

*/

// Some helper functions
int parentIndex(int index)
{
    return (index - 1) / 2;
}

int leftChildIndex(int index)
{
    return 2 * index + 1;
}

int rightChildIndex(int index)
{
    return 2 * index + 2;
}

// Swap a parent node with its greatest child node if it breaks the heap property
void siftDown(std::vector<int> &arr, int size, int index)
{
    int largest = index;
    int leftChild = leftChildIndex(index);
    int rightChild = rightChildIndex(index);
    if (leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != index)
    {
        std::swap(arr[index], arr[largest]);
        siftDown(arr, size, largest);
    }
}

// Swap a child node with its parent node it it breaks the heap property
void siftUp(std::vector<int> &arr, int index)
{
    if (index && arr[parentIndex(index)] < arr[index])
    {
        std::swap(arr[parentIndex(index)], arr[index]);
        siftUp(arr, parentIndex(index));
    }
}

// Build max heap in bottom-up manner
void maxHeap(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        siftDown(arr, size, i);
}

// Build max heap in top-down manner (slower than the bottom-up manner)
void maxHeap2(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        siftUp(arr, i);
    }
}

// heap Sort algorithm
void heapSort(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = arr.size() - 1; i > 0; i--)
    {
        std::swap(arr[i], arr[0]);
        size--;
        siftDown(arr, size, 0);
    }
}

// test the maxHeap function
void test(std::vector<int> &arr)
{
    maxHeap(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// test the maxHeap2 function
void test2(std::vector<int> &arr)
{
    maxHeap2(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// test heap sort
void testHeapSort(std::vector<int> &arr)
{
    maxHeap(arr);
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {3, 5, 1, 2, 2, 1, 1, 1, 58};
    std::vector<int> arr2 = {5, 2, 7, 3, 6, 1, 4};
    std::vector<int> arr3 = {3, 5, 1, 2, 7, 8, 9, 11, 23, 4, 89, 34, 21, 56, 365, 76, 88, 45, 165, 274, 58, 1};
    test(arr);
    test2(arr2);
    testHeapSort(arr2);

    return 0;
}