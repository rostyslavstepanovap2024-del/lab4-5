#include "SoundDevice.h"

SoundDevice::SoundDevice() {
    rec = { "Unknown", "", 0, 0, 0 };
}

SoundDevice::SoundDevice(const SoundRecord& r) : rec(r) {}

SoundDevice::~SoundDevice() {}

const SoundRecord& SoundDevice::getRecord() const {
    return rec;
}
