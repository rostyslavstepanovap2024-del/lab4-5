#include "radio.h"
#include <limits>

RadioRelay::RadioRelay() {
    std::cout << "Obiekt klasu RadioRelay stvoreno.\n";
}

RadioRelay::~RadioRelay() {
    std::cout << "Obiekt klasu RadioRelay znyshcheno.\n";
}

void RadioRelay::addRelay() {
    RadioRelayData r;
    std::cout << "\n=== Dodavannia novoho radiorle ===\n";

    std::cout << "Vvedit napruhu kotushky (V): ";
    std::cin >> r.voltage;
    if (!validateVoltage(r.voltage)) {
        std::cout << "Pomylka: napruha mae buty bilsha za 0!\n";
        return;
    }

    std::cout << "Vvedit maksymalnyi strum komutatsii (A): ";
    std::cin >> r.current;
    if (!validateCurrent(r.current)) {
        std::cout << "Pomylka: strum mae buty bilshyi za 0!\n";
        return;
    }

    std::cout << "Vvedit kilkist hrup kontaktiv: ";
    std::cin >> r.contacts;
    if (!validateContacts(r.contacts)) {
        std::cout << "Pomylka: kilkist kontaktiv mae buty bilsha za 0!\n";
        return;
    }

    relays.push_back(r);
    std::cout << " Radiorle uspishno dodano!\n";
}

void RadioRelay::showRelays() const {
    if (relays.empty()) {
        std::cout << "Spysok porozhnii.\n";
        return;
    }

    std::cout << "\n=== Spysok radiorle ===\n";
    for (size_t i = 0; i < relays.size(); ++i) {
        std::cout << i + 1 << ") Napruha kotushky: " << relays[i].voltage << " V, "
            << "Max. strum: " << relays[i].current << " A, "
            << "Kilkist kontaktiv: " << relays[i].contacts << "\n";
    }
}

void RadioRelay::deleteRelay() {
    if (relays.empty()) {
        std::cout << "Spysok porozhnii.\n";
        return;
    }

    size_t index;
    std::cout << "Vvedit nomer elementa dlia vydalennia: ";
    std::cin >> index;

    if (index == 0 || index > relays.size()) {
        std::cout << "Pomylka: nekorektnyi nomer!\n";
        return;
    }

    relays.erase(relays.begin() + index - 1);
    std::cout << "Element vydaleno!\n";
}

void RadioRelay::clearRelays() {
    relays.clear();
    std::cout << "Spysok ochyshcheno!\n";
}
