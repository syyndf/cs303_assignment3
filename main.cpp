//Samuel Yohannes
//syyndf@umsystem.edu

#include "queue.h"
#include <iostream>

using namespace std;

//this is to create the queue function
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }

    int item = arr[front];
    front = (front + 1) % capacity;
    count--;
    return item;
}

int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    return arr[front];
}

bool Queue::isEmpty() {
    return count == 0;
}

bool Queue::isFull() {
    return count == capacity;
}

int Queue::size() {
    return count;
}
