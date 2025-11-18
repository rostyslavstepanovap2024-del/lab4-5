#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "SoundDevice.h"

class Microphone : public SoundDevice {
public:
    Microphone();
    Microphone(const SoundRecord& r);
    virtual ~Microphone();
    virtual void input() override;
    virtual void output() const override;
};

#endif
