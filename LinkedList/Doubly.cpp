#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// insert at first

void insertAtHead(int value){
    Node* newNode = new Node();
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}

 /*
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Insert at Head
void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at Last
void insertAtLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Middle (at given position)
void insertAtMiddle(int value, int pos) {
    if (pos == 1) {
        insertAtHead(value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete at Head
void deleteAtHead() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete at Last
void deleteAtLast() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

// Delete at Middle (at given position)
void deleteAtMiddle(int pos) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        deleteAtHead();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

// Show Linked List (Forward)
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main Menu
int main() {
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
                insertAtHead(value);
                break;
            case 2:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtMiddle(value, pos);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertAtLast(value);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtMiddle(pos);
                break;
            case 6:
                deleteAtLast();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
*/
