#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <vector>
#include "SoundDevice.h"

class SoundManager {
private:
    std::vector<SoundRecord> records;

public:
    SoundManager();
    ~SoundManager();

    void addMicrophone();
    void addSpeaker();
    void removeAt(size_t index);
    void showAll() const;
    void calcStats() const;
};

#endif
