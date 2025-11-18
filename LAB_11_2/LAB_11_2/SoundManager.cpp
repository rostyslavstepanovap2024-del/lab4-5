#include "SoundManager.h"
#include "Microphone.h"
#include "Speaker.h"
#include <iostream>

SoundManager::SoundManager() {}
SoundManager::~SoundManager() {}

void SoundManager::addMicrophone() {
    Microphone m;
    m.input();
    records.push_back(m.getRecord());
}

void SoundManager::addSpeaker() {
    Speaker s;
    s.input();
    records.push_back(s.getRecord());
}

void SoundManager::removeAt(size_t index) {
    if (index < records.size()) {
        records.erase(records.begin() + index);
        std::cout << "Record removed.\n";
    }
    else {
        std::cout << "Invalid index.\n";
    }
}

void SoundManager::showAll() const {
    if (records.empty()) {
        std::cout << "No records.\n";
        return;
    }

    for (size_t i = 0; i < records.size(); i++) {
        std::cout << "[" << i << "] ";
        if (records[i].type == "Microphone") {
            std::cout << "Mic | " << records[i].name
                << " | Sens: " << records[i].param1
                << " | Fmin: " << records[i].param3
                << " | Fmax: " << records[i].param2;
        }
        else {
            std::cout << "Speaker | " << records[i].name
                << " | Power: " << records[i].param1
                << " | Ohm: " << records[i].param2;
        }
        std::cout << "\n";
    }
}

void SoundManager::calcStats() const {
    double sumSens = 0;
    int micCount = 0;

    double maxPower = -1;

    for (auto& r : records) {
        if (r.type == "Microphone") {
            sumSens += r.param1;
            micCount++;
        }
        else if (r.type == "Speaker") {
            if (r.param1 > maxPower) maxPower = r.param1;
        }
    }

    std::cout << "=== Statistics ===\n";

    if (micCount > 0)
        std::cout << "Average microphone sensitivity: " << sumSens / micCount << "\n";
    else
        std::cout << "No microphones.\n";

    if (maxPower >= 0)
        std::cout << "Max speaker power: " << maxPower << " W\n";
    else
        std::cout << "No speakers.\n";
}
