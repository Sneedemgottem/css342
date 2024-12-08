#include <iostream>
#include <vector>
#include <string>
using std::string;
#include<sys/time.h>
#include "sorts.h"

int Elapsed(const timeval &start, const timeval &end);
void InitVector(std::vector<int> &item_vector, int size);

int main(int argc, char *argv[]) {
    int size = 0;
    string sort_name = "";
    bool print_out = false;

    if ((argc != 3) && (argc != 4)) {
        std::cerr << "Usage: Sorter Algorithm Size [Print]" << std::endl;
        return EXIT_FAILURE;
    }

    sort_name = string(argv[1]);
    size = atoi(argv[2]);

    if (size <= 0) {
        std::cerr << "Vector size must be positive" << std::endl;
        return EXIT_FAILURE;
    }

    if (argc == 4) {
        string print_arr = string(argv[3]);
        if (print_arr == "Print") {
            print_out = true;
        } else {
            std::cerr << "Usage: Sorter Algorithm Size [Print]" << std::endl;
            return EXIT_FAILURE;
        }
    }

    srand(1);
    std::vector<int> items(size);
    InitVector(items, size);
    if (print_out) {
        std::cout << "Initial: ";
        PrintVector(items, 0, size - 1);
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, 0);

    if (sort_name == "BubbleSort") {
        BubbleSort(items, 0, size - 1);
    } else if (sort_name == "InsertionSort") {
        InsertionSort(items, 0, size - 1);
    } else if (sort_name == "MergeSort") {
        MergeSort(items, 0, size - 1);
    } else if (sort_name == "IterativeMergeSort") {
        IterativeMergeSort(items, 0, size - 1);
    } else if (sort_name == "QuickSort") {
        QuickSort(items, 0, size - 1);
    } else if (sort_name == "ShellSort") {
        ShellSort(items, 0, size - 1);
    }
    gettimeofday(&end_time, 0);

    if (print_out) {
        std::cout << "Sorted: ";
        PrintVector(items, 0, size - 1);
    }
    std::cout << "time elapsed (microseconds): " << Elapsed(start_time, end_time) << std::endl;
    return EXIT_SUCCESS;
}

void InitVector(std::vector<int> &item_vector, int rand_max) {
    if (rand_max < 0) {
        return;
    }
    
    std::vector<int> pool(rand_max);
    for (int i = 0; i < rand_max; i++) {
        pool[i] = i;
    }

    int spot;
    for (int i = 0; i < rand_max; i++) {
        spot = rand() % (pool.size());
        item_vector[i] = pool[spot];
        pool.erase(pool.begin() + spot);
    }
}

int Elapsed(const timeval &start, const timeval &end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}