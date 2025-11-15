#include "Channel.h"

Channel::Channel() {
    rec = { "Unknown", "", 0.0, 0.0, 0.0 };
}

Channel::Channel(const ChannelRecord& r) : rec(r) {}

Channel::~Channel() {}

const ChannelRecord& Channel::getRecord() const {
    return rec;
}
