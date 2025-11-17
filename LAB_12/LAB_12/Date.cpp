#pragma warning(disable:4146)
#include "Date.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <stdexcept>


// Constructor
Date::Date(int day, int month, int year) : d_(day), m_(month), y_(year) {
    // minimal validation
    if (m_ < 1 || m_ > 12) throw std::invalid_argument("month out of range");
    if (d_ < 1 || d_ > 31) throw std::invalid_argument("day out of range");
}

// parse DD-MM-YYYY
Date Date::fromString(const std::string& s) {
    std::istringstream iss(s);
    int dd, mm, yy;
    char sep1, sep2;
    if (!(iss >> dd >> sep1 >> mm >> sep2 >> yy)) {
        throw std::invalid_argument("bad date format");
    }
    if (sep1 != '-' || sep2 != '-') throw std::invalid_argument("bad separators");
    return Date(dd, mm, yy);
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << d_ << '-'
        << std::setw(2) << std::setfill('0') << m_ << '-'
        << std::setw(4) << std::setfill('0') << y_;
    return oss.str();
}

int Date::day() const { return d_; }
int Date::month() const { return m_; }
int Date::year() const { return y_; }

// decrease by n days
void Date::decreaseDays(int n) {
    int64_t days = toDays();
    days -= n;
    // convert back to civil date - use inverse of days_from_civil
    // Use Howard Hinnant inverse:
    int64_t z = days + 719468;
    int64_t era = (z >= 0 ? z : z - 146096) / 146097;
    unsigned doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
    unsigned yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;  // [0, 399]
    int y = static_cast<int>(yoe) + static_cast<int>(era) * 400;
    unsigned doy = doe - (365 * yoe + yoe / 4 - yoe / 100);                // [0, 365]
    unsigned mp = (5 * doy + 2) / 153;                                   // [0, 11]
    unsigned d = doy - (153 * mp + 2) / 5 + 1;                             // [1, 31]
    unsigned m = mp + (mp < 10 ? 3 : -9);                            // [1, 12]
    y += (m <= 2);
    d_ = static_cast<int>(d);
    m_ = static_cast<int>(m);
    y_ = y;
}

void Date::decreaseOneDay() {
    decreaseDays(1);
}

int64_t Date::days_from_civil(int y, unsigned m, unsigned d) {
    // returns days since 1970-01-01
    y -= m <= 2;
    const int64_t era = (y >= 0 ? y : y - 399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
    const unsigned doy = (153 * (m + (m > 2 ? -3u : 9u)) + 2) / 5 + d - 1; // [0, 365]
    const unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;        // [0, 146096]
    return era * 146097 + static_cast<int64_t>(doe) - 719468;
}

int64_t Date::toDays() const {
    return days_from_civil(y_, static_cast<unsigned>(m_), static_cast<unsigned>(d_));
}

int64_t Date::today_days() {
    std::time_t t = std::time(nullptr);
    std::tm local_tm;
#if defined(_MSC_VER)
    localtime_s(&local_tm, &t);
#else
    localtime_r(&t, &local_tm);
#endif
    int y = local_tm.tm_year + 1900;
    int m = local_tm.tm_mon + 1;
    int d = local_tm.tm_mday;
    return days_from_civil(y, static_cast<unsigned>(m), static_cast<unsigned>(d));
}

// operator<= compares absolute difference from today
bool operator<=(const Date& a, const Date& b) {
    int64_t today = Date::today_days();
    int64_t da = std::llabs(a.toDays() - today);
    int64_t db = std::llabs(b.toDays() - today);
    return da <= db;
}

// Nonstandard operator==: decrease left operand by 1 day (right operand ignored)
Date& operator==(Date& d, int /*dummy*/) {
    d.decreaseOneDay();
    return d;
}
