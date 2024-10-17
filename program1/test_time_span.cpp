#define CATCH_CONFIG_MAIN
#include "time_span.h"
#include <catch2/catch_test_macros.hpp>

int giveone() {
    return 1;
}

TEST_CASE("Test Catch2 is working", "[giveone]") {
    REQUIRE( giveone() == 1);
}