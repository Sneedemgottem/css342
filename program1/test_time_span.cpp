#define CATCH_CONFIG_MAIN
#include "time_span.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check TimeSpan Constructors", "[TimeSpan::Timespan()]") {
    SECTION("Check Regular Constructors With No Conversion") {
        {
            TimeSpan ts;
            REQUIRE(ts.hours()==0);
            REQUIRE(ts.minutes()==0);
            REQUIRE(ts.seconds()==0);
        }

        {
            TimeSpan ts(10, 5, 4);
            REQUIRE(ts.hours()==10);
            REQUIRE(ts.minutes()==5);
            REQUIRE(ts.seconds()==4);
        }

        {
            TimeSpan ts(7, 3);
            REQUIRE(ts.hours()==0);
            REQUIRE(ts.minutes()==7);
            REQUIRE(ts.seconds()==3);
        }

        {
            TimeSpan ts(8);
            REQUIRE(ts.hours()==0);
            REQUIRE(ts.minutes()==0);
            REQUIRE(ts.seconds()==8);
        }
    }

    SECTION("Check Constructors With Conversion") {
        {
            TimeSpan ts(1.5, 4, -10);
            REQUIRE(ts.hours()==1);
            REQUIRE(ts.minutes()==33);
            REQUIRE(ts.seconds()==50);
        }

        {
            TimeSpan ts(7, -3);
            REQUIRE(ts.hours()==0);
            REQUIRE(ts.minutes()==6);
            REQUIRE(ts.seconds()==57);
        }

        {
            TimeSpan ts(-190);
            REQUIRE(ts.hours()==0);
            REQUIRE(ts.minutes()==-3);
            REQUIRE(ts.seconds()==-10);
        }

        {
            TimeSpan ts(3, -90, 120);
            REQUIRE(ts.hours()==1);
            REQUIRE(ts.minutes()==32);
            REQUIRE(ts.seconds()==0);
        }

        {
            TimeSpan ts(127.86);
            REQUIRE(ts.hours()==0);
            REQUIRE(ts.minutes()==2);
            REQUIRE(ts.seconds()==8);
        }

        {
            TimeSpan ts(8, -23, 0);
            REQUIRE(ts.hours()==7);
            REQUIRE(ts.minutes()==37);
            REQUIRE(ts.seconds()==0);
        }

        {
            TimeSpan ts(-3, 73, 2);
            REQUIRE(ts.hours()==-1);
            REQUIRE(ts.minutes()==-46);
            REQUIRE(ts.seconds()==-58);
        }
    }
}

TEST_CASE("Check TimeSpan Operators", "[TimeSpan::operator]") {
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    SECTION("Arithmetic Operators") {
        TimeSpan add = ts1 + ts2 + ts3 + ts4;
        TimeSpan sub = ts1 - ts2 - ts3 - ts4;
        REQUIRE(add.hours()==4);
        REQUIRE(add.minutes()==7);
        REQUIRE(add.seconds()==5);
    }
}