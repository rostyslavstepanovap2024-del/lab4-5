#include "radio.h"


RadioRelay::RadioRelay() : coilVoltage(0.0), maxCurrent(0.0), contactGroups(0) {}


RadioRelay::RadioRelay(double v, double c, int g) {
    setCoilVoltage(v);
    setMaxCurrent(c);
    setContactGroups(g);
}


RadioRelay::~RadioRelay() {
    cout << "RadioRelay object destroyed." << endl;
}


void RadioRelay::setCoilVoltage(double v) {
    if (v > 0)
        coilVoltage = v;
    else
        cout << "Error: voltage must be positive!" << endl;
}

void RadioRelay::setMaxCurrent(double c) {
    if (c > 0)
        maxCurrent = c;
    else
        cout << "Error: current must be positive!" << endl;
}

void RadioRelay::setContactGroups(int g) {
    if (g > 0)
        contactGroups = g;
    else
        cout << "Error: number of contact groups must be positive!" << endl;
}


double RadioRelay::getCoilVoltage() const {
    return coilVoltage;
}

double RadioRelay::getMaxCurrent() const {
    return maxCurrent;
}

int RadioRelay::getContactGroups() const {
    return contactGroups;
}


void RadioRelay::display() const {
    cout << "Coil voltage: " << coilVoltage << " V" << endl;
    cout << "Max switching current: " << maxCurrent << " A" << endl;
    cout << "Number of contact groups: " << contactGroups << endl;
}


void increaseCurrent(RadioRelay& relay, double addValue) {
    cout << "\nChanging current via reference..." << endl;
    double newCurrent = relay.getMaxCurrent() + addValue;
    relay.setMaxCurrent(newCurrent);
}
