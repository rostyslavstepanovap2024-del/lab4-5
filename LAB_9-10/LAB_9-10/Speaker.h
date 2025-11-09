#ifndef SPEAKER_H
#define SPEAKER_H

#include "SoundDevice.h"

class Speaker : public SoundDevice {
private:
    string frequencyRange;

public:
    Speaker(string n = "Speaker", double p = 0, double i = 0, string f = "N/A");
    void setFrequencyRange(string f);
    string getFrequencyRange() const;

    void showInfo() const override;
};

#endif
