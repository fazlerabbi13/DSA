
import java.util.Scanner;

class Node {
    int data;
    Node prev, next;

    public Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    Node head, tail;

    // Insert at head
    public void insertAtHead(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
    }

    // Insert at last
    public void insertAtLast(int data) {
        Node newNode = new Node(data);
        if (tail == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    // Insert at middle (position)
    // public void insertAtMiddle(int data, int position) {
    //     if (position <= 1) {
    //         insertAtHead(data);
    //         return;
    //     }
    //     Node newNode = new Node(data);
    //     Node temp = head;
    //     int count = 1;
    //     while (temp != null && count < position - 1) {
    //         temp = temp.next;
    //         count++;
    //     }
    //     if (temp == null || temp.next == null) {
    //         insertAtLast(data);
    //     } else {
    //         newNode.next = temp.next;
    //         temp.next.prev = newNode;
    //         temp.next = newNode;
    //         newNode.prev = temp;
    //     }
    // }

    // Delete at head
    // public void deleteAtHead() {
    //     if (head == null) {
    //         System.out.println("List is empty.");
    //         return;
    //     }
    //     if (head == tail) {
    //         head = tail = null;
    //     } else {
    //         head = head.next;
    //         head.prev = null;
    //     }
    // }

    // Delete at last
    // public void deleteAtLast() {
    //     if (tail == null) {
    //         System.out.println("List is empty.");
    //         return;
    //     }
    //     if (head == tail) {
    //         head = tail = null;
    //     } else {
    //         tail = tail.prev;
    //         tail.next = null;
    //     }
    // }

    // Delete at middle (position)
    // public void deleteAtMiddle(int position) {
    //     if (position <= 1) {
    //         deleteAtHead();
    //         return;
    //     }
    //     Node temp = head;
    //     int count = 1;
    //     while (temp != null && count < position) {
    //         temp = temp.next;
    //         count++;
    //     }
    //     if (temp == null) {
    //         System.out.println("Invalid position.");
    //         return;
    //     }
    //     if (temp == tail) {
    //         deleteAtLast();
    //     } else {
    //         temp.prev.next = temp.next;
    //         temp.next.prev = temp.prev;
    //     }
    // }

    // Show linked list
    public void showList() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
}

public class TwoWayLinkedListMenu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyLinkedList dll = new DoublyLinkedList();
        int choice, data, pos;

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Insert at Head");
            System.out.println("2. Insert at Middle");
            System.out.println("3. Insert at Last");
            System.out.println("4. Delete at Head");
            System.out.println("5. Delete at Middle");
            System.out.println("6. Delete at Last");
            System.out.println("7. Show Linked List");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter data: ");
                    data = sc.nextInt();
                    dll.insertAtHead(data);
                    break;
                case 2:
                    System.out.print("Enter data: ");
                    data = sc.nextInt();
                    System.out.print("Enter position: ");
                    pos = sc.nextInt();
                    dll.insertAtMiddle(data, pos);
                    break;
                case 3:
                    System.out.print("Enter data: ");
                    data = sc.nextInt();
                    dll.insertAtLast(data);
                    break;
                case 4:
                    dll.deleteAtHead();
                    break;
                case 5:
                    System.out.print("Enter position: ");
                    pos = sc.nextInt();
                    dll.deleteAtMiddle(pos);
                    break;
                case 6:
                    dll.deleteAtLast();
                    break;
                case 7:
                    dll.showList();
                    break;
                case 8:
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}
