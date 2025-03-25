
#include <iostream>
#define SIZE 5  // Define the maximum size of the queue

using namespace std;

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to insert an element into the queue
    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Overflow! Insertion not possible." << endl;
            return;
        }
        if (front == -1) { // If queue is empty
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = value;
        cout << "Inserted " << value << " into the queue." << endl;
    }

    // Function to display the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    
    // Testing insertion
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); // Should insert successfully
    cq.enqueue(60); // Should give an overflow message

    // Display the queue
    cq.display();

    return 0;
}