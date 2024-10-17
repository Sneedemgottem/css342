#include <iostream>
#include <iosfwd>
#include <cmath>
#include "time_span.h"

TimeSpan::TimeSpan() {
    this->hours_ = 0;
    this->minutes_ = 0;
    this->seconds_ = 0;
}

TimeSpan::TimeSpan(const double &hours, const double &minutes, const double &seconds) {
    NormalizeTime(hours, minutes, seconds);
}

TimeSpan::TimeSpan(const double &minutes, const double &seconds) {
    NormalizeTime(0, minutes, seconds);
}

TimeSpan::TimeSpan(const double &seconds) {
    NormalizeTime(0, 0, seconds);
}

void TimeSpan::set_time(const int &hours, const int &minutes, const int &seconds) {
    NormalizeTime(hours, minutes, seconds);
}

void TimeSpan::NormalizeTime(const double &hours, const double &minutes, const double &seconds) {
    double temp = 0; // convert everything to seconds
    temp += hours * 3600;
    temp += minutes * 60;
    temp += seconds;

    int total_seconds = static_cast<int>(round(temp));
    this->total_seconds_ = total_seconds; // this will be used for easy comparison

    this->hours_ = total_seconds / 3600;
    total_seconds = total_seconds % 3600;
    this->minutes_ = total_seconds / 60;
    total_seconds = total_seconds % 60;
    this->seconds_ = total_seconds;
}

// getters - setters
int TimeSpan::hours() const {
    return this->hours_;
}

int TimeSpan::minutes() const {
    return this->minutes_;
}

int TimeSpan::seconds() const {
    return this->seconds_;
}

// conditional operator overloads
bool TimeSpan::operator==(const TimeSpan &rhs) const {
    return this->total_seconds_ == rhs.total_seconds_;
}

bool TimeSpan::operator!=(const TimeSpan &rhs) const {
    return this->total_seconds_ != rhs.total_seconds_;
}

bool TimeSpan::operator<(const TimeSpan &rhs) const {
    return this->total_seconds_ < rhs.total_seconds_;
}

bool TimeSpan::operator<=(const TimeSpan &rhs) const {
    return this->total_seconds_ <= rhs.total_seconds_;
}

bool TimeSpan::operator>(const TimeSpan &rhs) const {
    return this->total_seconds_ > rhs.total_seconds_;
}

bool TimeSpan::operator>=(const TimeSpan &rhs) const {
    return this->total_seconds_ >= rhs.total_seconds_;
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