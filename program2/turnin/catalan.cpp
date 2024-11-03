#include <iostream>
#include <sstream>

int ProcessArgument(int index, char *argv[]) {
    std::istringstream iss(argv[index]);
    int val;
    if (iss >> val) { // conversion successful
        return val;
    } else {
        std::cerr << "Cannot be converted to integer!" << std::endl;
        return -1;
    }
}

int Catalan(float n) {
    if (n > 15) {
        return -1;
    }

    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    return 2 * (2 * n - 1) / (n + 1) * Catalan(n - 1);
}

int main(int argc, char *argv[]) {
    // breaks at n > 15
    int n = ProcessArgument(1, argv);
    int res = Catalan(n);

    if (res > 0) {
        std::cout << res << std::endl;
    } else {
        std::cout << "Illegal argument!" << std::endl;
    }
    return 0;
}