#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> harr;
    int capacity;
    int heapSize;
public:
    MinHeap(int cap) {
        heapSize = 0;
        this->capacity = cap;
        harr.resize(cap);
    }
    
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    int left(int i) {
        return ((2 * i) + 1);
    }
    
    int right(int i) {
        return ((2 * i) + 2);
    }
    
    void insertKey(int key) {
        if (heapSize == capacity) {
            cout << "\nOverFlow : Could not insert key\n";
            return;
        }
        int i = heapSize;
        harr[i] = key;
        ++heapSize;
        while (i != 0 and harr[i] < harr[parent(i)]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heapSize and harr[smallest] > harr[l])
            smallest = l;
        if (r < heapSize and harr[smallest] > harr[r]) 
            smallest = r;
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    
    int extractMin() {
        if (heapSize == 0) 
            return INT_MAX;
        if (heapSize == 1) {
            --heapSize;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heapSize - 1];
        --heapSize;
        MinHeapify(0);
    }
    
    void decreaseKey(int i, int newVal) {
        harr[i] = newVal;
        while (i != 0 and harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    
    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    
    int getMin() {
        if (heapSize == 0)
            return -1;
        return harr[0];
    }
};

int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << "\n";
    cout << h.getMin() << "\n";
    h.decreaseKey(2, 1);
    cout << h.getMin() << "\n";
    return 0;
}