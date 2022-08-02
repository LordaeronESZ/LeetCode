#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> Q;
    int rear, front;
    bool fullFlag;
public:
    MyCircularQueue(int k) {
        Q.assign(k, 0);
        front = 0;
        rear = 0;
        fullFlag = false;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        Q[rear] = value;
        rear = (rear + 1) % Q.size();
        fullFlag = true;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % Q.size();
        fullFlag = false;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return Q[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return Q[(rear - 1 + Q.size()) % Q.size()];
    }

    bool isEmpty() {
        if (front == rear && !fullFlag) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (front == rear && fullFlag) {
            return true;
        }
        return false;
    }
};

int main() {
    MyCircularQueue circularQueue(6);
    cout << circularQueue.enQueue(6) << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.enQueue(5) << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.Front() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.deQueue() << endl;
}
