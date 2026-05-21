#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Q5.1: Queue Using Linked List
class QueueLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue Elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Q5.2: Circular Queue Using Array
class CircularQueue {
private:
    int arr[6];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % 6 == front;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << val << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % 6;
        }
        arr[rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 6;
        }
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Circular Queue Elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % 6;
        }
        cout << endl;
    }
};

// Q6: Evaluate Postfix Expression
/*
 This function evaluates postfix expressions using stack.
 When a digit appears, it is pushed into the stack.
 When an operator appears, the top two elements are removed.
 The operation is performed and the result is pushed back.
 At the end, the final result remains on top of the stack.
*/
int evaluatePostfix(string expr) {
    stack<int> s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            s.push(ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (s.size() < 2) return -1; // Safety check
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/':
                    if (val1 == 0) {
                        cout << "Division by Zero is Not Allowed!" << endl;
                        return -1;
                    }
                    s.push(val2 / val1);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    cout << "----- Linked List Queue -----" << endl;
    QueueLinkedList q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.display();

    q1.dequeue();
    q1.dequeue();
    q1.display();

    cout << "\n----- Circular Queue -----" << endl;
    CircularQueue q2;
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);
    q2.display();

    // Overflow check
    q2.enqueue(7);

    q2.dequeue();
    q2.dequeue();

    q2.enqueue(7);
    q2.enqueue(8);
    q2.display();

    cout << "\n----- Postfix Evaluation -----" << endl;
    cout << "23+ = " << evaluatePostfix("23+") << endl;
    cout << "53*2+ = " << evaluatePostfix("53*2+") << endl;
    cout << "842/* = " << evaluatePostfix("842/*") << endl; // Fixed test case expression to match standard division logic

    return 0;
}
