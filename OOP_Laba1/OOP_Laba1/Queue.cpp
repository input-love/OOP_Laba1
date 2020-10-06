#include "Queue.h"
#include "Error.h"

Queue::Queue() = default;

Queue::Queue(const int& size): _sizeArr(size), _arr(new int[_sizeArr]) {}

Queue::~Queue() {
    delete[] _arr; // ������� ������
}

void Queue::push(const int& data) {
    if (_count != _sizeArr) { // ����� ����� ������� �� ������� �� ������� �������
        if (_tail == _sizeArr - 1) { // ����� ����� � ����� ������� 
            _tail = -1;
        }
        *(_arr + (++_tail)) = data; // ���������� �������� � �����
        _count++; // ���-�� ��������� � �������
    } else {
        throw Error("������� �����������"); // ��������
    }
}

void Queue::pop() {
    if (_count > 0) { // ���������� �� ������� � ������� 
        _head++; // ����� ������  ( ���� �������� )
        if (_head == _sizeArr) { // ����� ������ � ����� ������� 
            _head = 0;
        }
        _count--; // ���������� ���-�� ��������� � �������
    } else {
        throw Error("������ ������� ������� - ������� ������"); // ��������
    }
}

bool Queue::isEmpty() const {
    if (_count > 0) { // ���������� �� ������� � ������� 
    } else {
        throw Error("������� ������"); // ��������
    }
}

int Queue::front() const {
    if (_count > 0) { // ���������� �� ������� � ������� 
        return *(_arr + _head); // ���������� ������ ( ��� ������� )
    } else {
        throw Error("� ������� ��� ���������"); // ��������
    }
}
