#include "Queue.h"
#include "Error.h"

Queue::Queue() = default;

Queue::Queue(const int& size): _sizeArr(size), _arr(new int[_sizeArr]) {}

Queue::~Queue() {
    delete[] _arr;
}

void Queue::push(const int& data) {
    if (_tail == _sizeArr - 1) {
        _tail = -1;
        _useItem = 0;
    }
    _arr[++_tail] = data;
    _useItem++;
}

void Queue::pop() {
    _head++;
    if (_head == _sizeArr) {
        _head = 0;
    }
    _useItem--;
}

bool Queue::isEmpty() const {
    return !_useItem;
}

int Queue::front() const {
    if (!_head && (_tail != -1)) {
        return *(_arr + _head);
    } else {
        throw Error("Ёлемент не существует!");
    }
}