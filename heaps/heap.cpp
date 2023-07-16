#include<iostream>
#include<climits>
using namespace std;

class MinHeap {
    int *heapArray;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity);
    void MinHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
    int getMin();
};

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    heapArray = new int[cap];
}

void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    heapArray[i] = k;

    while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val) {
    heapArray[i] = new_val;
    while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin() {
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return heapArray[0];
    }

    int root = heapArray[0];
    heapArray[0] = heapArray[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && heapArray[l] < heapArray[i])
        smallest = l;
    if (r < heap_size && heapArray[r] < heapArray[smallest])
        smallest = r;
    if (smallest != i) {
        swap(heapArray[i], heapArray[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::parent(int i) {
    return (i - 1) / 2;
}

int MinHeap::left(int i) {
    return (2 * i + 1);
}

int MinHeap::right(int i) {
    return (2 * i + 2);
}

int MinHeap::getMin() {
    if (heap_size <= 0)
        return INT_MAX;

    return heapArray[0];
}


int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}