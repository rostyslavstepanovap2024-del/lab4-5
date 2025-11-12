#include "Speaker.h"
#include <iostream>

Speaker::Speaker(string n, double p, double i, string f)
    : SoundDevice(n, p, i), frequencyRange(f) {
}

void Speaker::setFrequencyRange(string f) {
    frequencyRange = f;
}

string Speaker::getFrequencyRange() const {
    return frequencyRange;
}

void Speaker::showInfo() const {
    cout << "=== Speaker ===" << endl;
    SoundDevice::showInfo();
    cout << "Frequency range: " << frequencyRange << " Hz" << endl;
}
