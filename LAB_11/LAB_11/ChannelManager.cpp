#include "ChannelManager.h"
#include "RadioChannel.h"
#include "FiberChannel.h"
#include <iostream>
#include <limits>

ChannelManager::ChannelManager() {}

ChannelManager::~ChannelManager() {}

void ChannelManager::addRadio() {
    RadioChannel rc;
    rc.input();
    records.push_back(rc.getRecord());
}

void ChannelManager::addFiber() {
    FiberChannel fc;
    fc.input();
    records.push_back(fc.getRecord());
}

void ChannelManager::removeAt(size_t index) {
    if (index < records.size()) {
        records.erase(records.begin() + index);
        std::cout << "Record removed.\n";
    }
    else {
        std::cout << "Invalid index.\n";
    }
}

void ChannelManager::listAll() const {
    if (records.empty()) {
        std::cout << "No records.\n";
        return;
    }

    for (size_t i = 0; i < records.size(); i++) {
        const auto& r = records[i];
        std::cout << "[" << i << "] "
            << r.type << " | "
            << r.name << " | BW: " << r.bandwidth
            << " | Latency: " << r.latency
            << " | Param: " << r.noiseOrLoss
            << "\n";
    }
}

void ChannelManager::computeStats() const {
    if (records.empty()) {
        std::cout << "No data for statistics.\n";
        return;
    }

    double maxBW = records[0].bandwidth;
    double minBW = records[0].bandwidth;
    double sumBW = 0.0;

    for (const auto& r : records) {
        if (r.bandwidth > maxBW) maxBW = r.bandwidth;
        if (r.bandwidth < minBW) minBW = r.bandwidth;
        sumBW += r.bandwidth;
    }

    double avgBW = sumBW / records.size();

    std::cout << "Max BW: " << maxBW << " Mbps\n";
    std::cout << "Min BW: " << minBW << " Mbps\n";
    std::cout << "Avg BW: " << avgBW << " Mbps\n";
}

const std::vector<ChannelRecord>& ChannelManager::getRecords() const {
    return records;
}
