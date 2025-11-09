#ifndef SOUNDDEVICE_H
#define SOUNDDEVICE_H

#include <iostream>
#include <string>
using namespace std;

class SoundDevice {
protected:
    string name;
    double power;
    double impedance;

public:
    SoundDevice(string n = "Unknown", double p = 0.0, double i = 0.0);
    virtual ~SoundDevice();

    bool setPower(double p);
    bool setImpedance(double i);
    void setName(string n);

    string getName() const;
    double getPower() const;
    double getImpedance() const;

    virtual void showInfo() const; // virtual function
};

#endif
