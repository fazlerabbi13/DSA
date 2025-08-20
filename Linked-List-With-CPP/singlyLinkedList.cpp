#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at Head
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at Last
    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at Middle (at position)
    void insertAtMiddle(int value, int pos) {
        if (pos == 1) {
            insertAtHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position!\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at Head
    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at Last
    // void deleteAtLast() {
    //     if (head == nullptr) {
    //         cout << "List is empty!\n";
    //         return;
    //     }
    //     if (head->next == nullptr) {
    //         delete head;
    //         head = nullptr;
    //         return;
    //     }
    //     Node* temp = head;
    //     while (temp->next->next != nullptr) {
    //         temp = temp->next;
    //     }
    //     delete temp->next;
    //     temp->next = nullptr;
    // }

    // Delete at Middle (position)
    // void deleteAtMiddle(int pos) {
    //     if (head == nullptr) {
    //         cout << "List is empty!\n";
    //         return;
    //     }
    //     if (pos == 1) {
    //         deleteAtHead();
    //         return;
    //     }
    //     Node* temp = head;
    //     for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
    //         temp = temp->next;
    //     }
    //     if (temp == nullptr || temp->next == nullptr) {
    //         cout << "Invalid position!\n";
    //         return;
    //     }
    //     Node* delNode = temp->next;
    //     temp->next = delNode->next;
    //     delete delNode;
    // }

    // Display Linked List
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, pos;

    while (true) {
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
                list.insertAtHead(value);
                break;
            case 2:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertAtMiddle(value, pos);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtLast(value);
                break;
            case 4:
                list.deleteAtHead();
                break;
            case 5:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtMiddle(pos);
                break;
            case 6:
                list.deleteAtLast();
                break;
            case 7:
                list.display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}



