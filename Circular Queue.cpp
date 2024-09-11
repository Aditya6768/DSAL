#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int front, rear, size, capacity;

public:
    
    CircularQueue(int capacity) {
        this->capacity = capacity;
        this->queue = new int[capacity];
        this->front = this->rear = this->size = 0;
    }

    
    ~CircularQueue() {
        delete[] queue;
    }

    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

private:
    
    bool isFull() {
        return size == capacity;
    }

    
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

	cq.dequeue();
	cq.display();
	
	cq.enqueue(90);
	cq.display();
	
	   
    return 0;
}

