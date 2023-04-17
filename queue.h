#ifndef QUEUE_H
#define QUEUE_H

//class for queue function
class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size = 10);
    ~Queue();
    void enqueue(int item);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
};

#endif
