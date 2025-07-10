class LinkedList {
    Node head;

    class Node {
        int data;
        Node next;

        Node(int data) { this.data = data; this.next = null; }
    }

    void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) head = newNode;
        else {
            Node temp = head;
            while (temp.next != null) temp = temp.next;
            temp.next = newNode;
        }
    }
}
