#include "Interface.h"

Interface::Interface() = default;

void Interface::run() {
    setlocale(LC_ALL, "Russian");

    int sizeList;
    do {
        std::cout << "������� ��������� � �������?: ";
        std::cin >> sizeList;
    } while (sizeList <= 0);

    Queue _queue(sizeList);

    while (true) {
        int check;
        std::cout << "1. ������� ��������� �����\n2. ���������� �� ������� � �������" << std::endl;
        std::cout << "3. ������� ������ ������� �� �������\n4. �������� �������\n5. �����" << std::endl;
        std::cin >> check;
        try {
            switch (check) {
            case 1:
                std::cout << "���� �����: " << _queue.front() << std::endl;
                break;
            case 2:
                if (!_queue.isEmpty()) {
                    std::cout << "������� �� ������" << std::endl;
                } else {
                    std::cout << "������� ������" << std::endl;
                }
                break;
            case 3:
                _queue.pop();
                break;
            case 4:
                int Element;
                std::cin >> Element;
                _queue.push(Element);
                break;
            case 5:
                return;
            }
        } catch (const std::exception& except) {
            std::cout << except.what() << std::endl;
        }
    }
}