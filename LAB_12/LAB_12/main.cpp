#include <iostream>
#include <vector>
#include <algorithm>
#include "Date.h"

int main() {
    try {
        // Example: create a vector of dates (format DD-MM-YYYY)
        std::vector<Date> arr;
        arr.push_back(Date::fromString("15-11-2025"));
        arr.push_back(Date::fromString("01-01-2025"));
        arr.push_back(Date::fromString("10-11-2025"));
        arr.push_back(Date::fromString("18-11-2025"));

        std::cout << "Original dates:\n";
        for (const auto& d : arr) std::cout << d.toString() << '\n';

        // Sort by ascending absolute difference from today (using operator<=)
        // std::sort needs a strict-weak-order comparator; we will use
        // comparator based on absolute difference from today (ascending).
        auto cmp = [](const Date& a, const Date& b) {
            // use same logic as operator<= but strict
            int64_t today = Date::today_days();
            int64_t da = std::llabs(a.toDays() - today);
            int64_t db = std::llabs(b.toDays() - today);
            return da < db;
            };
        std::sort(arr.begin(), arr.end(), cmp);

        std::cout << "\nSorted by abs(days difference from today) ascending:\n";
        for (const auto& d : arr) std::cout << d.toString() << '\n';

        // Decrease each date by N days (example N = 5)
        int N = 5;
        for (auto& d : arr) d.decreaseDays(N);

        std::cout << "\nAfter decreasing each date by " << N << " days:\n";
        for (const auto& d : arr) std::cout << d.toString() << '\n';

        // Demonstrate operator== used as "decrease by one day" (nonstandard)
        Date x = Date::fromString("20-11-2025");
        std::cout << "\nBefore operator== decrease: " << x.toString() << '\n';
        x == 0; // decrease x by 1 day using our nonstandard overload
        std::cout << "After x == 0 : " << x.toString() << '\n';

    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}
