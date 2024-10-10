#include <iostream>
#include "timespan.h"

TimeSpan::TimeSpan() {
    this->hours_ = 0;
    this->minutes_ = 0;
    this->seconds_ = 0;
}

TimeSpan::TimeSpan(const double &hours, const double &minutes, const double &seconds) {
    normalize_time_(hours, minutes, seconds);
}

TimeSpan::TimeSpan(const double &minutes, const double &seconds) {
    normalize_time_(0, minutes, seconds);
}

TimeSpan::TimeSpan(const double &seconds) {
    normalize_time_(0, 0, seconds);
}

void TimeSpan::set_time(const int &hours, const int &minutes, const int &seconds) {
    normalize_time_(hours, minutes, seconds);
}

void TimeSpan::normalize_time_(const double &hours, const double &minutes, const double &seconds) {
    int temp = 0; // convert everything to seconds
    temp += hours * 3600;
    temp += minutes * 60;
    temp += seconds;

    this->hours_ = temp / 3600;
    temp = temp % 3600;
    this->minutes_ = temp / 60;
    temp = temp % 60;
    this->seconds_ = temp;
}

void TimeSpan::tell_time() const {
    std::cout << "Hours: " << this->hours_ << std::endl;
    std::cout << "Minutes: " << this->minutes_ << std::endl;
    std::cout << "Seconds: " << this->seconds_ << std::endl;
}

// Operator overloads
bool TimeSpan::operator==(const TimeSpan &rhs) const {
    if (this->hours_ == rhs.hours_ && this->minutes_ == rhs.minutes_ && this->seconds_ == rhs.seconds_) {
        return true;
    }

    return false;
}

bool TimeSpan::operator!=(const TimeSpan &rhs) const {
    return !(*this == rhs);
}

bool TimeSpan::operator<=(const TimeSpan &rhs) const {
    if (!(this->hours_ <= rhs.hours_)) {
        return false;
    }
    if (!(this->minutes_ <= rhs.minutes_)) {
        return false;
    }
    if (!(this->seconds_ <= rhs.seconds_)) {
        return false;
    }
    return true;
}
bool TimeSpan::operator<(const TimeSpan &rhs) const {
    if (!(*this == rhs) && *this <= rhs) {
        return true;
    }
    return false;
}

bool TimeSpan::operator>(const TimeSpan &rhs) const {
    if (!(*this == rhs) && !(*this <= rhs)) {
        return true;
    }
    return false;
}

bool TimeSpan::operator>=(const TimeSpan &rhs) const {
    if (*this == rhs || *this > rhs) {
        return true;
    }
    return false;
}

