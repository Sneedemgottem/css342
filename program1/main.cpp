#include <iostream>
#include "timespan.h"

int main() {
    TimeSpan ts1(12);
    ts1.tell_time();

    TimeSpan ts2(11);
    ts2.tell_time();

    return 0;
}