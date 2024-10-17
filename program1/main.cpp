#include <iostream>
#include "time_span.h"

int main() {
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan ts = ts1 + ts2 + ts3 + ts4;
    std::cout << ts << std::endl;

    return 0;
}