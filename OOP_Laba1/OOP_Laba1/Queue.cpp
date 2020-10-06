#include "Queue.h"
#include "Error.h"

Queue::Queue() = default;

Queue::Queue(const int& size): _sizeArr(size), _arr(new int[_sizeArr]) {}

Queue::~Queue() {
    delete[] _arr; // Очистка памяти
}

void Queue::push(const int& data) {
    if (_count != _sizeArr) { // Чтобы новый элемент не выходил за размеры очереди
        if (_tail == _sizeArr - 1) { // Когда Хвост в конце очереди 
            _tail = -1;
        }
        *(_arr + (++_tail)) = data; // Добавление элемента в Хвост
        _count++; // Кол-во элементов в очереди
    } else {
        throw Error("Очередь переполнена"); // Ошибкинс
    }
}

void Queue::pop() {
    if (_count > 0) { // Существует ли элемент в очереди 
        _head++; // Сдвиг Головы  ( типо удаление )
        if (_head == _sizeArr) { // Когда Голова в конце массива 
            _head = 0;
        }
        _count--; // Уменьшение кол-ва элементов в очереди
    } else {
        throw Error("Нельзя удалить элемент - очередь пустая"); // Ошибкинс
    }
}

bool Queue::isEmpty() const {
    if (_count > 0) { // Существует ли элемент в очереди 
    } else {
        throw Error("Очередь пустая"); // Ошибкинс
    }
}

int Queue::front() const {
    if (_count > 0) { // Существует ли элемент в очереди 
        return *(_arr + _head); // Возращение Головы ( сам элемент )
    } else {
        throw Error("В очереди нет элементов"); // Ошибкинс
    }
}
