#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at last
    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at middle (after given position)
    void insertAtMiddle(int pos, int value) {
        if (pos <= 1) {
            insertAtHead(value);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            insertAtLast(value);
        } else {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    // Delete at head
    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete at last
    void deleteAtLast() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Delete at middle (by position)
    void deleteAtMiddle(int pos) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos <= 1) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (temp == tail) {
            deleteAtLast();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // Show linked list
    void showList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function with menu
int main() {
    DoublyLinkedList dll;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Middle\n";
        cout << "3. Insert at Last\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Middle\n";
        cout << "6. Delete at Last\n";
        cout << "7. Show Linked List\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtHead(value);
                break;
            case 2:
                cout << "Enter position and value: ";
                cin >> pos >> value;
                dll.insertAtMiddle(pos, value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtLast(value);
                break;
            case 4:
                dll.deleteAtHead();
                break;
            case 5:
                cout << "Enter position: ";
                cin >> pos;
                dll.deleteAtMiddle(pos);
                break;
            case 6:
                dll.deleteAtLast();
                break;
            case 7:
                dll.showList();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}






