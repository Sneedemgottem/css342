#pragma once

// This file implements all required sorting algorithms needed

#include <vector>
#include <iostream>

template <class T>
void PrintVector(const std::vector<T> &vec) {
    std::cout << "[";
    for (T data : vec) {
        std::cout << " " << data;
    }
    std::cout << " ]\n";
}

template <class T>
void BubbleSort(std::vector<T> &vec, int start, int end);