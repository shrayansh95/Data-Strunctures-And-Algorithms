#include<iostream>
using namespace std;
class Stack {
    int top;
public :
    int a[100];
    Stack() {
        top = -1;
    }
    void push(int x) {
        if (top >= 100) {
            cout << "\nStack OverFlow\n";
        }
        else {
            cout << "\nElement " << x << " Inserted\n";
            a[++top] = x;
        }
    }
    int pop() {
        if (top < 0) {
            cout << "\nStack is Empty : ";
            return -1;
        }
        else {
            cout << "\nPopping Element : ";
            return a[top--];
        }
    }
    bool isEmpty() {
        if (top < 0) {
            return true;
        }
        return false;
    }
};
int main() {
    Stack s1;
    s1.push(20);
    s1.push(30);
    s1.push(25);
    s1.push(91);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    return 0;
}