#ifndef FIBERCHANNEL_H
#define FIBERCHANNEL_H

#include "Channel.h"

class FiberChannel : public Channel {
public:
    FiberChannel();
    FiberChannel(const ChannelRecord& r);
    virtual ~FiberChannel();
    virtual void input() override;
    virtual void output() const override;

    double estimatedMaxDistanceKm() const;
};

#endif // FIBERCHANNEL_H
