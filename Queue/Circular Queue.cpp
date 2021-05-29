#include<iostream>
#define SIZE 5
using namespace std;
class Cqueue {
    int a[SIZE], front, rear;
public:
    Cqueue() {
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
        if (front == rear + 1)
            return true;
        return false;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full.\n";
            return;
        }
        if (front == -1)
            ++front;
        rear = (rear + 1) % SIZE;
        a[rear] = val;
        cout << "Inserted " << val << "\n";
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return -1;
        }
        int val = a[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE;
        cout << "Deleting " << val << "\n";
        return val;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % SIZE)
            cout << a[i] << " ";
        cout << a[rear] << "\n";
    }
};
int main() {
    Cqueue q;

    // Fails because front = -1
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enqueue(6);

    q.display();

    int elem = q.dequeue();
    q.display();

    q.enqueue(7);

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enqueue(8);

    return 0;
}