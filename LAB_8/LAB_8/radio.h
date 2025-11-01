#ifndef RADIO_H
#define RADIO_H

#include <iostream>
#include <string>
using namespace std;

class RadioRelay {
private:
    double coilVoltage;    
    double maxCurrent;     
    int contactGroups;     

public:
    
    RadioRelay();

    
    RadioRelay(double v, double c, int g);

    ~RadioRelay();

    void setCoilVoltage(double v);
    void setMaxCurrent(double c);
    void setContactGroups(int g);

    
    double getCoilVoltage() const;
    double getMaxCurrent() const;
    int getContactGroups() const;

    
    void display() const;
};


void increaseCurrent(RadioRelay& relay, double addValue);

#endif
