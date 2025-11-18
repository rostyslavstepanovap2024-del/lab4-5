#include "Microphone.h"
#include <iostream>
#include <limits>

Microphone::Microphone() : SoundDevice() {
    rec.type = "Microphone";
}

Microphone::Microphone(const SoundRecord& r) : SoundDevice(r) {
    rec.type = "Microphone";
}

Microphone::~Microphone() {}

void Microphone::input() {
    std::cout << "Enter microphone name: ";
    std::getline(std::cin, rec.name);

    std::cout << "Enter sensitivity (mV/Pa): ";
    std::cin >> rec.param1;

    std::cout << "Enter min frequency (Hz): ";
    std::cin >> rec.param3;

    std::cout << "Enter max frequency (Hz): ";
    std::cin >> rec.param2;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Microphone::output() const {
    std::cout << "Type: Microphone"
        << " | Name: " << rec.name
        << " | Sensitivity: " << rec.param1
        << " | Freq min: " << rec.param3
        << " | Freq max: " << rec.param2 << "\n";
}
