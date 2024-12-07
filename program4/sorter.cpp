#include <iostream>
#include <vector>
#include "sorts.h"

int main() {
    std::vector<int> vec;
    vec.push_back(38);
    vec.push_back(27);
    vec.push_back(43);
    vec.push_back(10);
    vec.push_back(2);
    PrintVector(vec, 0, vec.size() - 1);
    ShellSort(vec, 0, vec.size() - 1);
    PrintVector(vec, 0, vec.size() - 1);
    return EXIT_SUCCESS;
}