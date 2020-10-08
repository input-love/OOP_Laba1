#include "Queue.h"
#include "Error.h"

Queue::Queue(): _sizeArr(15), _arr(new int[_sizeArr]) {}

Queue::Queue(const int size): _sizeArr(size), _arr(new int[_sizeArr]) {}

Queue::Queue(const Queue& data) {
    _arr = new int[data._sizeArr];
    for (int i = 0; i < data._sizeArr; ++i) {  // Можно использовать std::copy()
        *(_arr + i) = *(data._arr + i);
    }
    _sizeArr = data._sizeArr;
    _head = data._head;
    _tail = data._tail;
    _count = data._count;
}

Queue::~Queue() {
    delete[] _arr;
}

void Queue::push(const int data) {
    if (_count != _sizeArr) {
        if (_tail == _sizeArr - 1) { 
            _tail = -1;
        }
        *(_arr + (++_tail)) = data;
        _count++;
    } else {
        throw Error("Очередь переполнена");
    }
}

void Queue::pop() {
    if (_count > 0) { 
        _head++;
        if (_head == _sizeArr) { 
            _head = 0;
        }
        _count--;
    } else {
        throw Error("Нельзя удалить элемент - очередь пустая");
    }
}

bool Queue::isEmpty() const {
    if (_count > 0) {
        return !_count;
    } else {
        throw Error("Очередь пустая");
    }
}

int Queue::front() const {
    if (_count > 0) { 
        return *(_arr + _head);
    } else {
        throw Error("В очереди нет элементов");
    }
}
