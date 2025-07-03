#include <iostream>
using namespace std;
class Stack {
    int size;
    int top;
    int *arr;
public:
    Stack(int s) {
        size=s;
        top=-1;
        arr=new int[size];
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int x) {
        if(top==size-1) {
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    int pop() {
        if(top==-1) {
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }
        int x=arr[top];
        top--;
        return x;
    }
    int getSize() {
        return top+1;
    }
    int getTop() {
        if(top==-1) {
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return arr[top];
    }
    int peep(int index) {
        if(index<0||index>top) {
            cout<<"Invalid Index!"<<endl;
            return -1;
        }
        return arr[index];
    }
};
int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.getTop() << endl;     // 30
    cout << "Stack size: " << s.getSize() << endl;     // 3
    cout << "Element at index 1: " << s.peep(1) << endl;  // 20
    cout << "Popped element: " << s.pop() << endl;             // 30
    cout << "New top: " << s.getTop() << endl;         // 20
    return 0;
}
