#ifndef CHANNELMANAGER_H
#define CHANNELMANAGER_H

#include <vector>
#include "Channel.h"

class ChannelManager {
private:
    std::vector<ChannelRecord> records;

public:
    ChannelManager();
    ~ChannelManager();

    void addRadio();
    void addFiber();
    void removeAt(size_t index);
    void listAll() const;
    void computeStats() const;

    const std::vector<ChannelRecord>& getRecords() const;
};

#endif // CHANNELMANAGER_H
