#include "radio.h"
#include <limits>

RadioRelay::RadioRelay() : count(0) {}

RadioRelay::~RadioRelay() {}

bool RadioRelay::validateVoltage(double v) const {
    return v > 0.0;
}

bool RadioRelay::validateCurrent(double i) const {
    return i > 0.0;
}

bool RadioRelay::validateContacts(int c) const {
    return c > 0;
}

bool RadioRelay::setCount(std::size_t n) {
    if (n == 0 || n > SIZE) return false;
    count = n;
    return true;
}

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void RadioRelay::inputRelay(std::size_t index) {
    if (index >= count) return;

    double voltage;
    double current;
    int contacts;

    while (true) {
        std::cout << "Елемент [" << index + 1 << "/" << count << "]\n";

        std::cout << "  Введіть напругу котушки (V): ";
        if (!(std::cin >> voltage)) {
            std::cout << "  Помилка вводу. Спробуйте ще раз.\n";
            clearInput();
            continue;
        }
        if (!validateVoltage(voltage)) {
            std::cout << "  Некоректна напруга. Має бути > 0.\n";
            continue;
        }

        std::cout << "  Введіть макс. струм комутації (A): ";
        if (!(std::cin >> current)) {
            std::cout << "  Помилка вводу. Спробуйте ще раз.\n";
            clearInput();
            continue;
        }
        if (!validateCurrent(current)) {
            std::cout << "  Некоректний струм. Має бути > 0.\n";
            continue;
        }

        std::cout << "  Введіть кількість груп контактів (ціле число): ";
        if (!(std::cin >> contacts)) {
            std::cout << "  Помилка вводу. Спробуйте ще раз.\n";
            clearInput();
            continue;
        }
        if (!validateContacts(contacts)) {
            std::cout << "  Некоректна кількість контактів. Має бути > 0.\n";
            continue;
        }

        relays[index].coilVoltage = voltage;
        relays[index].maxSwitchCurrent = current;
        relays[index].contactGroups = contacts;

        clearInput();
        break;
    }
}

void RadioRelay::inputAll() {
    for (std::size_t i = 0; i < count; ++i) {
        inputRelay(i);
    }
}

void RadioRelay::printRelay(std::size_t index) const {
    if (index >= count) return;
    const relay_s_t &r = relays[index];
    std::cout << "Елемент [" << index + 1 << "]:" << '\n';
    std::cout << "  Напруга котушки (V): " << r.coilVoltage << '\n';
    std::cout << "  Макс. струм комутації (A): " << r.maxSwitchCurrent << '\n';
    std::cout << "  Кількість груп контактів: " << r.contactGroups << '\n';
}

void RadioRelay::printAll() const {
    std::cout << "=== ДАНІ РАДІОРЕЛЕ ===\n";
    for (std::size_t i = 0; i < count; ++i) {
        printRelay(i);
        if (i + 1 < count) std::cout << "-----------------------\n";
    }
    std::cout << "======================\n";
}
