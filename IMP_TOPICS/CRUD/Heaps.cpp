#include <iostream>
using namespace std;

#define MAX_SIZE 100

class MinHeap
{
    int heap[MAX_SIZE];
    int size;

public:
    MinHeap() : size(0) {}
    void insert(int val);
    void deleteMin();
    void update(int index, int newValue);
    void display();
    void heapify(int i);
};

class MaxHeap
{
    int heap[MAX_SIZE];
    int size;

public:
    MaxHeap() : size(0) {}
    void insert(int val);
    void deleteMax();
    void update(int index, int newValue);
    void display();
    void heapify(int i);
};

void MinHeap::insert(int val)
{
    if (size >= MAX_SIZE)
        return;

    heap[size] = val;
    int i = size++;
    while (i > 0 && heap[i] < heap[(i - 1) / 2])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MaxHeap::insert(int val)
{
    if (size >= MAX_SIZE)
        return;

    heap[size] = val;
    int i = size++;
    while (i > 0 && heap[i] > heap[(i - 1) / 2])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::deleteMin()
{
    if (size == 0)
        return;
    heap[0] = heap[--size];
    heapify(0);
}

void MaxHeap::deleteMax()
{
    if (size == 0)
        return;
    heap[0] = heap[--size];
    heapify(0);
}

void MinHeap::update(int index, int newValue)
{
    if (index < 0 || index >= size)
        return;

    heap[index] = newValue;
    while (index > 0 && heap[index] < heap[(index - 1) / 2])
    {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    heapify(index);
}

void MaxHeap::update(int index, int newValue)
{
    if (index < 0 || index >= size)
        return;

    heap[index] = newValue;
    while (index > 0 && heap[index] > heap[(index - 1) / 2])
    {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    heapify(index);
}

void MinHeap::heapify(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

void MaxHeap::heapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void MinHeap::display()
{
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void MaxHeap::display()
{
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    MinHeap minHeap;
    MaxHeap maxHeap;
    int n, value, index, newValue;

    cout << "Enter number of elements for MinHeap: ";
    cin >> n;

    cout << "Enter elements for MinHeap:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        minHeap.insert(value);
    }

    cout << "MinHeap: ";
    minHeap.display();

    cout << "Enter index to update in MinHeap and new value: ";
    cin >> index >> newValue;
    minHeap.update(index, newValue);
    cout << "MinHeap after update: ";
    minHeap.display();

    cout << "Enter number of elements for MaxHeap: ";
    cin >> n;

    cout << "Enter elements for MaxHeap:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        maxHeap.insert(value);
    }

    cout << "MaxHeap: ";
    maxHeap.display();

    cout << "Enter index to update in MaxHeap and new value: ";
    cin >> index >> newValue;
    maxHeap.update(index, newValue);
    cout << "MaxHeap after update: ";
    maxHeap.display();

    return 0;
}

