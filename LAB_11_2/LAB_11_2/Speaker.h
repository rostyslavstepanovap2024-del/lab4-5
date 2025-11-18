#ifndef SPEAKER_H
#define SPEAKER_H

#include "SoundDevice.h"

class Speaker : public SoundDevice {
public:
    Speaker();
    Speaker(const SoundRecord& r);
    virtual ~Speaker();
    virtual void input() override;
    virtual void output() const override;
};

#endif
