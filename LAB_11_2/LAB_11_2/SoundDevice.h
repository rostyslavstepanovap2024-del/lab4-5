#ifndef SOUNDDEVICE_H
#define SOUNDDEVICE_H

#include <string>

struct SoundRecord {
    std::string type;      // "Microphone" or "Speaker"
    std::string name;
    double param1;         // sensitivity or power
    double param2;         // freq range max or impedance
    double param3;         // freq range min (only for microphone)
};

class SoundDevice {
protected:
    SoundRecord rec;
public:
    SoundDevice();
    SoundDevice(const SoundRecord& r);
    virtual ~SoundDevice();
    virtual void input() = 0;
    virtual void output() const = 0;
    const SoundRecord& getRecord() const;
};

#endif
