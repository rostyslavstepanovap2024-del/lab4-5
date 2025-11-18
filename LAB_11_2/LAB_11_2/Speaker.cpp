#include "Speaker.h"
#include <iostream>
#include <limits>

Speaker::Speaker() : SoundDevice() {
    rec.type = "Speaker";
}

Speaker::Speaker(const SoundRecord& r) : SoundDevice(r) {
    rec.type = "Speaker";
}

Speaker::~Speaker() {}

void Speaker::input() {
    std::cout << "Enter speaker name: ";
    std::getline(std::cin, rec.name);

    std::cout << "Enter power (W): ";
    std::cin >> rec.param1;

    std::cout << "Enter impedance (Ohm): ";
    std::cin >> rec.param2;

    rec.param3 = 0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Speaker::output() const {
    std::cout << "Type: Speaker"
        << " | Name: " << rec.name
        << " | Power: " << rec.param1
        << " | Impedance: " << rec.param2 << "\n";
}
