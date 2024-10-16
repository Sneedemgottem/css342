#include <iostream>
#include <iosfwd>
#include "time_span.h"

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

// conditional operator overloads
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


// arithmetic operator overloads

TimeSpan TimeSpan::operator+(const TimeSpan &rhs) const {
    return TimeSpan(this->hours_+rhs.hours_, this->minutes_+rhs.minutes_, this->seconds_+rhs.seconds_);
}

TimeSpan TimeSpan::operator-(const TimeSpan &rhs) const {
    return TimeSpan(this->hours_-rhs.hours_, this->minutes_-rhs.minutes_, this->seconds_-rhs.seconds_);
}

TimeSpan TimeSpan::operator-() const {
    return TimeSpan(-(this->hours_), -(this->minutes_), -(this->seconds_));
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &rhs) {
    this->set_time(this->hours_ + rhs.hours_, this->minutes_ + rhs.minutes_, this->seconds_ + rhs.seconds_);
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &rhs) {
    this->set_time(this->hours_ - rhs.hours_, this->minutes_ - rhs.minutes_, this->seconds_ - rhs.seconds_);
    return *this;
}


// I/O operators

std::ostream& operator<<(std::ostream &out, const TimeSpan &ts) {
    out << "Hours: " << ts.hours_ << ",Minutes: " << ts.minutes_ << ",Seconds: " << ts.seconds_;
    return out;
}

std::istream& operator>>(std::istream &in, TimeSpan &ts) {
    double hours;
    double minutes;
    double seconds;

    in >> hours >> minutes >> seconds;

    if (in) {
        ts = TimeSpan(hours, minutes, seconds);
    }

    return in;
}