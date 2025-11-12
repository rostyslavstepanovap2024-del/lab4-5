#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "SoundDevice.h"

class Microphone : public SoundDevice {
private:
    double sensitivity; 

public:
    Microphone(string n = "Microphone", double p = 0, double i = 0, double s = 0);
    bool setSensitivity(double s);
    double getSensitivity() const;

    void showInfo() const override; 
};

#endif
