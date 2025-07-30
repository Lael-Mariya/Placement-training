#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int element) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue Overflow\n";
        } else {
            if (front == -1)
                front = 0;
            arr[++rear] = element;
        }
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            int item = arr[front++];
            if (front > rear) {
                front = -1;
                rear = -1;
            }
            return item;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
        } else {
            for (int i = front; i <= rear; ++i)
                cout << arr[i] << "\t";
            cout << endl;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    int getSize() {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue q;
    int ch, data;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Front\n5. Is Empty\n6. Size\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                cout << "Deleted: " << q.dequeue() << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Front: " << q.getFront() << endl;
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 6:
                cout << "Size: " << q.getSize() << endl;
                break;
            case 7:
                break;
            default:
                cout << "Enter a valid choice\n";
        }
    } while (ch != 7);

    return 0;
}
