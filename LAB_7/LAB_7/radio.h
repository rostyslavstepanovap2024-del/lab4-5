#ifndef RADIO_H
#define RADIO_H

#include <iostream>
#include <vector>
#include <string>

struct RadioRelayData {
    double voltage;   
    double current;   
    int contacts;     
};

class RadioRelay {
private:
    std::vector<RadioRelayData> relays;

    bool validateVoltage(double v) const { return v > 0.0; }
    bool validateCurrent(double i) const { return i > 0.0; }
    bool validateContacts(int c) const { return c > 0; }

public:
    RadioRelay();   
    ~RadioRelay();  

    void addRelay();       
    void showRelays() const; 
    void deleteRelay();    
    void clearRelays();    
};

#endif
