#include<iostream>
#define SIZE 5
using namespace std;
class Queue {
    int a[SIZE], front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        if (front == -1)
            return true;
        return false;
    }
    bool isFull() {
        if (front == 0 and rear == SIZE - 1)
            return true;
        return false;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1)
            ++front;
        a[++rear] = val;
        cout << "Inserted " << val << "\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        int val = a[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        ++front;
        cout << "Deleting " << val << "\n";
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    Queue q;
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}