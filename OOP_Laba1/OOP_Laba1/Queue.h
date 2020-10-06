#pragma once

class Queue {
public:
    Queue();

    Queue(const int& size);

    ~Queue();

    void push(const int& data);

    void pop();

    bool isEmpty() const;

    int front() const;

private:
    int* _arr = nullptr;
    int _sizeArr;
    int _head = 0;
    int _tail = -1;
    int _count = 0;

};