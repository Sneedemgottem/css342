#define CATCH_CONFIG_MAIN
#include "time_span.h"
#include <catch2/catch_test_macros.hpp>

void CheckTimeSpanValues(const TimeSpan &ts, const int &hours, const int &minutes, const int &seconds) {
    REQUIRE(ts.hours() == hours);
    REQUIRE(ts.minutes() == minutes);
    REQUIRE(ts.seconds() == seconds);
}

TEST_CASE("Check TimeSpan Constructors", "[TimeSpan::Timespan()]") {
    SECTION("Check Regular Constructors With No Conversion") {
        {
            TimeSpan ts;
            CheckTimeSpanValues(ts, 0, 0, 0);
        }

        {
            TimeSpan ts(10, 5, 4);
            CheckTimeSpanValues(ts, 10, 5, 4);
        }

        {
            TimeSpan ts(7, 3);
            CheckTimeSpanValues(ts, 0, 7, 3);
        }

        {
            TimeSpan ts(8);
            CheckTimeSpanValues(ts, 0, 0, 8);
        }
    }

    SECTION("Check Constructors With Conversion") {
        {
            TimeSpan ts(1.5, 4, -10);
            CheckTimeSpanValues(ts, 1, 33, 50);
        }

        {
            TimeSpan ts(7, -3);
            CheckTimeSpanValues(ts, 0, 6, 57);
        }

        {
            TimeSpan ts(-190);
            CheckTimeSpanValues(ts, 0, -3, -10);
        }

        {
            TimeSpan ts(3, -90, 120);
            CheckTimeSpanValues(ts, 1, 32, 0);
        }

        {
            TimeSpan ts(127.86);
            CheckTimeSpanValues(ts, 0, 2, 8);
        }

        {
            TimeSpan ts(8, -23, 0);
            CheckTimeSpanValues(ts, 7, 37, 0);
        }

        {
            TimeSpan ts(-3, 73, 2);
            CheckTimeSpanValues(ts, -1, -46, -58);
        }
    }
}

TEST_CASE("Check TimeSpan Operators", "[TimeSpan::operator]") {
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    SECTION("Arithmetic Operators") {
        TimeSpan add = ts1 + ts2 + ts3 + ts4;
        TimeSpan sub = ts1 - ts2 - ts3 - ts4;

        CheckTimeSpanValues(add, 4, 7, 5);

        CheckTimeSpanValues(sub, -4, -7, -5);

        TimeSpan ts(5, 5, 5);
        TimeSpan ts_negative = -ts;
        CheckTimeSpanValues(ts_negative, -5, -5, -5);

        ts += ts4;
        CheckTimeSpanValues(ts, 9, 5, 5);

        ts -= ts4;
        REQUIRE(ts.hours()==5);
        REQUIRE(ts.minutes()==5);
        REQUIRE(ts.seconds()==5);
    }

    SECTION("Comparison Operators") {
        TimeSpan ts(5);
        REQUIRE(ts2 == ts);
        REQUIRE(ts1 != ts);
        REQUIRE((ts1 < ts4));
        REQUIRE(ts2 <= ts);
        REQUIRE(ts2 <= ts3);
        REQUIRE(ts3 > ts2);
        REQUIRE(ts2 >= ts);
        REQUIRE(ts3 >= ts2);
    }
}

TEST_CASE("Check set_time method", "[TimeSpan::set_time]") {
    TimeSpan ts;

    SECTION("Normal Time Set Without Conversion") {
        ts.set_time(0,0,0);
        CheckTimeSpanValues(ts, 0, 0, 0);

        ts.set_time(1, 5, 6);
        CheckTimeSpanValues(ts, 1, 5, 6);
    }

    SECTION("Normal Set Time With Conversion") {
        ts.set_time(0, 7, -3);
        CheckTimeSpanValues(ts, 0, 6, 57);

        ts.set_time(0, 0, -190);
        CheckTimeSpanValues(ts, 0, -3, -10);
    }
}