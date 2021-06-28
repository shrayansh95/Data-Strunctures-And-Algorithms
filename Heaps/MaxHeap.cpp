#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
    vector<int> harr;
    int heapSize;
    int capacity;
public:
    MaxHeap(int cap){
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
            cout << "\nOverFlow : Could Not Inset Key\n";
            return;
        }
        int i = heapSize;
        harr[i] = key;
        ++heapSize;
        while (i != 0 and harr[i] > harr[parent(i)]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    
    void MaxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heapSize and harr[largest] < harr[l])
            largest = l;
        if (r < heapSize and harr[largest] < harr[r])
            largest = r;
        if (largest != i) {
            swap(harr[i], harr[largest]);
            MaxHeapify(largest);
        }
    }
    
    int extractMax() {
        if (heapSize == 0)
            return INT_MAX;
        if (heapSize == 1) {
            --heapSize;
            return harr[0];
        }
        int val = harr[0];
        harr[0] = harr[heapSize - 1];
        --heapSize;
        MaxHeapify(0);
        return val;
    }
    
    void increaseKey(int i, int newVal) {
        harr[i] = newVal;
        while (i != 0 and harr[parent(i)] < harr[i]) {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
    
    void deleteKey(int i) {
        increaseKey(i, INT_MAX);
        extractMax();
    }
    
    int getMax() {
        if (heapSize == 0) {
            return -1;
        }
        return harr[0];
    }
};

int main()
{
    MaxHeap h(10);
    h.insertKey(10);
    h.insertKey(7);
    h.insertKey(11);
    h.insertKey(21);
    h.insertKey(6);
    cout << h.getMax() << "\n";
    h.increaseKey(2, 34);
    cout << h.extractMax() << "\n";
    cout << h.extractMax() << "\n";
    cout << h.getMax() << "\n";
    return 0;
}
