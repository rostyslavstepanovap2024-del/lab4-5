#ifndef RADIO_H
#define RADIO_H

#include <array>
#include <string>
#include <iostream>

constexpr std::size_t SIZE = 10; // Максимальна кількість елементів у статичному масиві

struct relay_s_t {
    double coilVoltage;      // Напруга котушки (в вольтах)
    double maxSwitchCurrent; // Максимальний струм комутації (в амперах)
    int contactGroups;       // Кількість груп контактів
};

class RadioRelay {
private:
    std::array<relay_s_t, SIZE> relays;
    std::size_t count; // фактична кількість елементів, введених користувачем

    // Перевірка валідності полів
    bool validateVoltage(double v) const;
    bool validateCurrent(double i) const;
    bool validateContacts(int c) const;

public:
    // Конструктор та деструктор
    RadioRelay();
    ~RadioRelay();

    // Налаштування кількості записів (не більше SIZE)
    bool setCount(std::size_t n);

    // Додавання/ввід одного елементу за індексом (0..count-1)
    void inputRelay(std::size_t index);

    // Заповнення даних (покроково від 0 до count-1)
    void inputAll();

    // Вивід одного елемента
    void printRelay(std::size_t index) const;

    // Вивід усіх елементів
    void printAll() const;

    // Отримати count
    std::size_t getCount() const { return count; }
};

#endif // RADIO_H
