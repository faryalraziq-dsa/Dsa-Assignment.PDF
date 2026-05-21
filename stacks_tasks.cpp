#include <iostream>
using namespace std;

// Q2.1: Stack Implementation Using Array
class StackArray {
private:
    int arr[10];
    int top;

public:
    StackArray() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 9;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack Elements (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Q2.2: Stack Implementation Using Linked List
class StackLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack Elements (Top to Bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor memory free karne ke liye
    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Q2.3: Main Function Demonstration
int main() {
    cout << "----- Array Stack -----" << endl;
    StackArray s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();

    cout << "Popping 2 values..." << endl;
    s1.pop();
    s1.pop();
    s1.display();
    cout << "Peek Value: " << s1.peek() << endl;

    cout << "\n----- Linked List Stack -----" << endl;
    StackLinkedList s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    s2.display();

    cout << "Popping 2 values..." << endl;
    s2.pop();
    s2.pop();
    s2.display();
    cout << "Peek Value: " << s2.peek() << endl;

    cout << "\n----- Demonstrating Underflow -----" << endl;
    StackArray emptyStack;
    emptyStack.pop(); 

    return 0;
}
