#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

struct ChannelRecord {
    std::string type;
    std::string name;
    double bandwidth;
    double latency;
    double noiseOrLoss;
};

class Channel {
protected:
    ChannelRecord rec;
public:
    Channel();
    Channel(const ChannelRecord& r);
    virtual ~Channel();
    virtual void input() = 0;
    virtual void output() const = 0;
    const ChannelRecord& getRecord() const;
};

#endif // CHANNEL_H
