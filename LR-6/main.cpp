#include "radio.h"
#include <iostream>

int main() {
    
    RadioRelay rr;

    std::size_t n;
    std::cout << "Лабораторна робота №6 — Радіореле (варіант 20)\n";
    std::cout << "Максимальна кількість елементів у масиві: " << SIZE << "\n";

    while (true) {
        std::cout << "Введіть кількість елементів для збереження (1.." << SIZE << "): ";
        if (!(std::cin >> n)) {
            std::cout << "Невірний ввід. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (rr.setCount(n)) break;
        std::cout << "Кількість має бути від 1 до " << SIZE << ". Спробуйте ще раз.\n";
    }

    // Заповнення даних з перевірками
    rr.inputAll();

    // Вивід результатів
    rr.printAll();

    std::cout << "Програма завершена.\n";
    return 0;
}
