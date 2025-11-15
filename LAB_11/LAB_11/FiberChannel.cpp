#include "FiberChannel.h"
#include <iostream>
#include <limits>

FiberChannel::FiberChannel() : Channel() {
    rec.type = "Fiber";
}

FiberChannel::FiberChannel(const ChannelRecord& r) : Channel(r) {
    rec.type = "Fiber";
}

FiberChannel::~FiberChannel() {}

void FiberChannel::input() {
    std::cout << "Enter fiber channel name: ";
    std::getline(std::cin, rec.name);

    std::cout << "Bandwidth (Mbps): ";
    std::cin >> rec.bandwidth;

    std::cout << "Latency (ms): ";
    std::cin >> rec.latency;

    std::cout << "Loss (dB/km): ";
    std::cin >> rec.noiseOrLoss;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void FiberChannel::output() const {
    std::cout << "Type: " << rec.type
        << "; Name: " << rec.name
        << "; Bandwidth: " << rec.bandwidth
        << "; Latency: " << rec.latency
        << "; Loss(dB/km): " << rec.noiseOrLoss << "\n";
}

double FiberChannel::estimatedMaxDistanceKm() const {
    if (rec.noiseOrLoss <= 0.0) return 0.0;
    return 20.0 / rec.noiseOrLoss;
}
