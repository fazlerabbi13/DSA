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

    int peek(){
        if(top == null){
            System.out.println("Stack is empty");
            return -1;
        }
        return top.data;
    }

    boolean isEmpty(){
        return top == null;
    }

    int size(){
        return count;
    }

    
}

class LLimplementation{
    public static void main(String[] args) {
        myStack st = new myStack();

        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        System.out.println("popped: "+ st.pop());

        System.out.println("Top element: " + st.peek());

    }
}