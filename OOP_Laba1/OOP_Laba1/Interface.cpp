#include "Interface.h"

Interface::Interface() = default;

void Interface::run() {
    setlocale(LC_ALL, "Russian");

    int sizeList;
    do {
        std::cout << "Сколько элементов в очереди?: ";
        std::cin >> sizeList;
    } while (sizeList <= 0);

    Queue queue(sizeList);

    while (true) {
        int check;
        std::cout << "1. Вывести последнее число\n2. Существует ли элемент в очереди" << std::endl;
        std::cout << "3. Удалить первый элемент из очереди\n4. Добавить элемент\n5. Выход" << std::endl;
        std::cin >> check;
        try {
            switch (check) {
            case 1:
                std::cout << "Ваше число: " << queue.front() << std::endl;
                break;
            case 2:
                if (!queue.isEmpty()) {
                    std::cout << "Очередь не пустая" << std::endl;
                } else {
                    std::cout << "Очередь пустая" << std::endl;
                }
                break;
            case 3:
                queue.pop();
                break;
            case 4:
                int Element;
                std::cin >> Element;
                queue.push(Element);
                break;
            case 5:
                return;
            }
        } catch (const std::exception& exept) {
            std::cout << exept.what() << std::endl;
        }
    }
}