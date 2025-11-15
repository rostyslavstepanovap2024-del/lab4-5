#include "RadioChannel.h"
#include <iostream>
#include <limits>

RadioChannel::RadioChannel() : Channel() {
    rec.type = "Radio";
}

RadioChannel::RadioChannel(const ChannelRecord& r) : Channel(r) {
    rec.type = "Radio";
}

RadioChannel::~RadioChannel() {}

void RadioChannel::input() {
    std::cout << "Enter radio channel name: ";
    std::getline(std::cin, rec.name);

    std::cout << "Bandwidth (Mbps): ";
    std::cin >> rec.bandwidth;

    std::cout << "Latency (ms): ";
    std::cin >> rec.latency;

    std::cout << "SNR (dB): ";
    std::cin >> rec.noiseOrLoss;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void RadioChannel::output() const {
    std::cout << "Type: " << rec.type
        << "; Name: " << rec.name
        << "; Bandwidth: " << rec.bandwidth
        << "; Latency: " << rec.latency
        << "; SNR: " << rec.noiseOrLoss << "\n";
}

double RadioChannel::estimatedRangeKm() const {
    if (rec.noiseOrLoss <= 0.0) return 0.0;
    return rec.noiseOrLoss * 0.1 * (rec.bandwidth / 10.0);
}
