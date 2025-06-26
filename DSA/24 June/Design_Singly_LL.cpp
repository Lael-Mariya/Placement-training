#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

//insert_at_start
void insert_at_start(int val) {
    Node* newNode=new Node{val, head};
    head = newNode;
}

//insert_at_end
void insert_at_end(int val) {
    Node* newNode=new Node{val, NULL};
    if (!head) {
        head=newNode;
        return;
    }
    Node* temp=head;
    while (temp->next) temp = temp->next;
    temp->next=newNode;
}

//insert_at_index
void insert_at_index(int index, int val) {
    if (index == 0) {
        insert_at_start(val);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp; i++) temp = temp->next;
    if (!temp) {
        cout << "Index out of bounds\n";
        return;
    }
    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;
}

//delete_at_start
void delete_at_start() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

//delete_at_end
void delete_at_end() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

//delete_at_index
void delete_at_index(int index) {
    if (index == 0) {
        delete_at_start();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp; i++) temp = temp->next;
    if (!temp || !temp->next) {
        cout << "Invalid Index\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// delete_value
void delete_value(int val) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (head->data == val) {
        delete_at_start();
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) {
        cout << "Not found\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Singly Linked List ---\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at index\n";
        cout << "4. Delete at start\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at index\n";
        cout << "7. Delete by value\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int val, index;
        switch (choice) {
            case 1:
                cout << "Enter no. to insert at start: ";
                cin >> val;
                insert_at_start(val);
                break;
            case 2:
                cout << "Enter no. to insert at end: ";
                cin >> val;
                insert_at_end(val);
                break;
            case 3:
                cout << "Enter index and no. to insert: ";
                cin >> index >> val;
                insert_at_index(index, val);
                break;
            case 4:
                delete_at_start();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                cout << "Enter index to delete: ";
                cin >> index;
                delete_at_index(index);
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                delete_value(val);
                break;
            case 8:
                display();
                break;
            case 9:
                cout << "Done\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }

    } while (choice != 9);

    return 0;
}
