#include <iostream>
using namespace std;

class Cqueue {
public:
    static const int SIZE = 8;
    int arr[SIZE];
    int front = -1;
    int rear = -1;

    void push(int val) {
        // Queue Full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full\n";
            return;
        }

        // First element
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = val;
    }

    void pop() {
        if (empty()) {
            cout << "Queue Empty\n";
            return;
        }

        // Last element removed
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

    void printFront() {
        if (empty()) {
            cout << "Queue Empty\n";
        }
        else {
            cout << arr[front] << '\n';
        }
    }

    bool empty() {
        return front == -1;
    }
};

int main() {
    Cqueue cq;

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.push(6);
    cq.push(7);
    cq.push(8);

    cq.push(9); // Queue Full

    cq.printFront(); // 1

    cq.pop();
    cq.printFront(); // 2

    cq.pop();
    cq.printFront(); // 3

    return 0;
}