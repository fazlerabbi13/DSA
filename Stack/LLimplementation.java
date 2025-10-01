class Node {
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}

class myStack {
    Node top;

    int count;

    myStack() {
        top = null;
        count = 0;
    }

    // push operation
    void push(int x){
        Node temp = new Node(x);
        temp.next = top;
        top = temp;

        count++;
    }

    int pop(){
        if(top == null){
            System.out.println("Stack Underflow");
            return -1;
        }
        Node temp = top;
        top = top.next;
        int val = temp.data;

        count--;
        return val;
    }
    
}