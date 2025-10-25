#include "radio.h"
#include <limits>

RadioRelay::RadioRelay() {
    std::cout << "Obiekt klasu RadioRelay stvoreno.\n";
}

RadioRelay::~RadioRelay() {
    std::cout << "Obiekt klasu RadioRelay znyshcheno.\n";
}

// ========================
// Dodavannia novoho elementa
// ========================
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
    std::cout << "✅ Radiorle uspishno dodano!\n";
}

// ========================
// Vstavka elementa za indeksom
// ========================
void RadioRelay::insertRelay() {
    if (relays.empty()) {
        std::cout << "Spysok porozhnii, vykorystayte dodavannia!\n";
        return;
    }

    size_t index;
    std::cout << "Vvedit indeks (1 - " << relays.size() << ") pered yakym vstavyty novyi element: ";
    std::cin >> index;

    if (index == 0 || index > relays.size() + 1) {
        std::cout << "Pomylka: nekorektnyi indeks!\n";
        return;
    }

    RadioRelayData r;
    std::cout << "\n=== Vstavka radiorle ===\n";
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

    relays.insert(relays.begin() + (index - 1), r);
    std::cout << "✅ Element vstavleno u spysok!\n";
}

// ========================
// Vyvedennia vsykh elementiv
// ========================
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

// ========================
// Vydalennia elementa
// ========================
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
    std::cout << "✅ Element vydaleno!\n";
}

// ========================
// Ochystka vektora
// ========================
void RadioRelay::clearRelays() {
    relays.clear();
    std::cout << "✅ Spysok ochyshcheno!\n";
}

// ========================
// Obmin dvokh elementiv
// ========================
void RadioRelay::swapRelays() {
    if (relays.size() < 2) {
        std::cout << "Nedostatno elementiv dlia obminu!\n";
        return;
    }

    size_t i1, i2;
    std::cout << "Vvedit indeks pershoho elementa: ";
    std::cin >> i1;
    std::cout << "Vvedit indeks druhoho elementa: ";
    std::cin >> i2;

    if (i1 == 0 || i2 == 0 || i1 > relays.size() || i2 > relays.size()) {
        std::cout << "Pomylka: nekorektni indeksy!\n";
        return;
    }

    std::swap(relays[i1 - 1], relays[i2 - 1]);
    std::cout << "✅ Elementy obminiano!\n";
}
