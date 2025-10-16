#ifndef RADIO_H
#define RADIO_H

#include <array>
#include <string>
#include <iostream>

constexpr std::size_t SIZE = 10; // Maksymalna kilkist elementiv u statychnomu masyvi

struct relay_s_t {
    double coilVoltage;      // Napruha kotushky (v voltakh)
    double maxSwitchCurrent; // Maksymalnyi strum komutatsii (v amperakh)
    int contactGroups;       // Kilkist hrup kontaktiv
};

class RadioRelay {
private:
    std::array<relay_s_t, SIZE> relays;
    std::size_t count; // faktychna kilkist elementiv, vvedenykh korystuvachem

    // Perevirka validnosti poliv
    bool validateVoltage(double v) const;
    bool validateCurrent(double i) const;
    bool validateContacts(int c) const;

public:
    // Konstruktor ta destruktor
    RadioRelay();
    ~RadioRelay();

    // Nalashtuvannya kilkosti zapysiv (ne bilshe SIZE)
    bool setCount(std::size_t n);

    // Dodavannya/vvid odnoho elementu za indeksom (0..count-1)
    void inputRelay(std::size_t index);

    // Zapovnennya danikh (pokrokovo vid 0 do count-1)
    void inputAll();

    // Vyvid odnoho elementa
    void printRelay(std::size_t index) const;

    // Vyvid usikh elementiv
    void printAll() const;

    // Otrymaty count
    std::size_t getCount() const { return count; }
};

#endif // RADIO_H
