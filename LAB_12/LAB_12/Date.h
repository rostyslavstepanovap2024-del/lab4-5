#ifndef DATE_H
#define DATE_H

#include <cstdint>
#include <string>

class Date {
public:
    Date(int day = 1, int month = 1, int year = 1970);

    // parse from string "DD-MM-YYYY"
    static Date fromString(const std::string& s);

    std::string toString() const; // "DD-MM-YYYY"

    // decrease by n days
    void decreaseDays(int n);

    // decrease by one day (helper)
    void decreaseOneDay();

    // convert to days since epoch (1970-01-01)
    int64_t toDays() const;

    // getters
    int day() const;
    int month() const;
    int year() const;

    // operators:
    // operator<= compares absolute difference from today (in days)
    friend bool operator<=(const Date& a, const Date& b);

    // Nonstandard operator==: decrease left operand by 1 day and return it.
    // Because operator== is binary in C++, we accept an int dummy as right operand.
    // Usage: d == 0; // decrease d by one day
    friend Date& operator==(Date& d, int /*dummy*/);

public:
    int d_;
    int m_;
    int y_;

    // helper: civil -> days conversion (Howard Hinnant algorithm)
    static int64_t days_from_civil(int y, unsigned m, unsigned d);

    // get today's days (since 1970-01-01)
    static int64_t today_days();
};

#endif // DATE_H
