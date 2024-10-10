#pragma once

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
        void tell_time() const;

        // comparison operator overloads
        bool operator==(const TimeSpan &rhs) const;
        bool operator!=(const TimeSpan &rhs) const;
        bool operator<(const TimeSpan &rhs) const;
        bool operator<=(const TimeSpan &rhs) const;
        bool operator>(const TimeSpan &rhs) const;
        bool operator>=(const TimeSpan &rhs) const;

        // TODO: other operators

    private:
        int hours_;
        int minutes_;
        int seconds_;

        void normalize_time_(const double &hours, const double &minutes, const double &seconds);
};