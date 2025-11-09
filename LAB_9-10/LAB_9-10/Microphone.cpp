#include "Microphone.h"
#include <iostream>

Microphone::Microphone(string n, double p, double i, double s)
    : SoundDevice(n, p, i), sensitivity(s) {
}

bool Microphone::setSensitivity(double s) {
    if (s > 0) {
        sensitivity = s;
        return true;
    }
    cout << "Error: sensitivity must be positive!" << endl;
    return false;
}

double Microphone::getSensitivity() const {
    return sensitivity;
}

void Microphone::showInfo() const {
    cout << "=== Microphone ===" << endl;
    SoundDevice::showInfo();
    cout << "Sensitivity: " << sensitivity << " mV/Pa" << endl;
}
