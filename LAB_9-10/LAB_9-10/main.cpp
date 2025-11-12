#include <iostream>
#include <vector>
#include "Microphone.h"
#include "Speaker.h"
using namespace std;

int main() {
    vector<SoundDevice*> devices;

    devices.push_back(new Microphone("AKG P120", 0.05, 200, 22.4));
    devices.push_back(new Speaker("JBL GO 3", 4.2, 8, "100-20000"));
    devices.push_back(new Speaker("Sony SRS-XB13", 5.0, 6, "80-18000"));

    cout << "\n--- Sound devices info ---" << endl;
    for (auto dev : devices) {
        dev->showInfo();
        cout << endl;
    }

    
    double totalPower = 0.0;
    for (auto dev : devices)
        totalPower += dev->getPower();

    double averagePower = totalPower / devices.size();

    cout << "--- Calculations ---" << endl;
    cout << "Total power: " << totalPower << " W" << endl;
    cout << "Average power: " << averagePower << " W" << endl;

    
    for (auto dev : devices)
        delete dev;

    return 0;
}
