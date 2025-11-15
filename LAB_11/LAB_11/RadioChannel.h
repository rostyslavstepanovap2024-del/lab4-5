#ifndef RADIOCHANNEL_H
#define RADIOCHANNEL_H

#include "Channel.h"

class RadioChannel : public Channel {
public:
    RadioChannel();
    RadioChannel(const ChannelRecord& r);
    virtual ~RadioChannel();
    virtual void input() override;
    virtual void output() const override;

    double estimatedRangeKm() const;
};

#endif // RADIOCHANNEL_H
