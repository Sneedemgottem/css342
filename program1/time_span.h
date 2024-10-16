#pragma once

#include <iosfwd>

class TimeSpan {
    public:
        // Constructors
        TimeSpan();
        TimeSpan(const double &hours, const double &minutes, const double &seconds);
        TimeSpan(const double &minutes, const double &seconds);
        TimeSpan(const double &seconds);

        // Getters-setters
        int hours() const;
        int minutes() const;
        int seconds() const;

        // public methods
        void set_time(const int &hours, const int &minutes, const int &seconds);

        // comparison operator overloads
        bool operator==(const TimeSpan &rhs) const;
        bool operator!=(const TimeSpan &rhs) const;
        bool operator<(const TimeSpan &rhs) const;
        bool operator<=(const TimeSpan &rhs) const;
        bool operator>(const TimeSpan &rhs) const;
        bool operator>=(const TimeSpan &rhs) const;

        // math operator overloads
        TimeSpan operator+(const TimeSpan &rhs) const;
        TimeSpan operator-(const TimeSpan &rhs) const;
        TimeSpan operator-() const;
        TimeSpan& operator+=(const TimeSpan &rhs);
        TimeSpan& operator-=(const TimeSpan &rhs);

        // I/O operator overloads
        friend std::ostream& operator<<(std::ostream &out, const TimeSpan &ts);
        friend std::istream& operator>>(std::istream &in, TimeSpan &ts);

    private:
        int hours_;
        int minutes_;
        int seconds_;

        void normalize_time_(const double &hours, const double &minutes, const double &seconds);
};