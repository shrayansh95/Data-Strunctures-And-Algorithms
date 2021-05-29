#include<iostream>
#define SIZE 5
using namespace std;
class Deque {
    int a[SIZE], front, rear;
public:
    Deque() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        if ((front == 0 and rear == SIZE - 1) || (front == rear + 1))
            return true;
        return false;
    }
    void insertfront(int val) {
        if (isFull()) {
            cout << "Deque is Full.\n";
            return;
        }
        if (front == -1) {
            ++front;
            ++rear;
        }
        else if (front == 0)
            front = SIZE - 1;
        else
            --front;
        a[front] = val;
    }
    void insertrear(int val) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }
        if (front == -1)
            ++front;
        rear = (rear + 1) % SIZE;
        a[rear] = val;
    }
    int deletefront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        int val = a[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE;
        return val;
    }
    int deleterear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        int val = a[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = SIZE - 1;
        else
            --rear;
        return val;
    }
    int getfront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return a[front];
    }
    int getrear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }
        return a[rear];
    }
};
int main() {
    Deque dq;
    dq.insertrear(5);
    dq.insertrear(11);

    cout << "rear element: "
         << dq.getrear() << endl;

    dq.deleterear();
    cout << "after deletion of the rear element, the new rear element: " << dq.getrear() << endl;

    cout << "insert element at front end \n";

    dq.insertfront(8);

    cout << "front element: " << dq.getfront() << endl;

    dq.deletefront();

    cout << "after deletion of front element new front element: " << dq.getfront() << endl;
}