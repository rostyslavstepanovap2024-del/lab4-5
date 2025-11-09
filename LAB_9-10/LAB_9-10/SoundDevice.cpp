#include "SoundDevice.h"

SoundDevice::SoundDevice(string n, double p, double i)
    : name(n), power(p), impedance(i) {
}

SoundDevice::~SoundDevice() {}

bool SoundDevice::setPower(double p) {
    if (p > 0) {
        power = p;
        return true;
    }
    cout << "Error: power must be positive!" << endl;
    return false;
}

bool SoundDevice::setImpedance(double i) {
    if (i > 0) {
        impedance = i;
        return true;
    }
    cout << "Error: impedance must be positive!" << endl;
    return false;
}

void SoundDevice::setName(string n) {
    name = n;
}

string SoundDevice::getName() const { return name; }
double SoundDevice::getPower() const { return power; }
double SoundDevice::getImpedance() const { return impedance; }

void SoundDevice::showInfo() const {
    cout << "Device: " << name
        << "\nPower: " << power << " W"
        << "\nImpedance: " << impedance << " Ohm" << endl;
}
