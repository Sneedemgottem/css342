#pragma once

// This file implements all required sorting algorithms needed

#include <vector>
#include <iostream>

template <class T>
void PrintVector(const std::vector<T> &vec, int start, int end) {
    std::cout << "[";
    for (int i = start; i <= end; i++) {
        std::cout << " " << vec[i];
    }
    std::cout << " ]\n";
}

template <class T>
void BubbleSort(std::vector<T> &vec, int start, int end);

template <class T>
void InsertionSort(std::vector<T> &vec, int start, int end);

template <class T>
void MergeSort(std::vector<T> &vec, int start, int end);

template <class T>
void IterativeMergeSort(std::vector<T> &vec, int start, int end);

template <class T>
void QuickSort(std::vector<T> &vec, int start, int end);

template <class T>
void ShellSort(std::vector<T> &vec, int start, int end);

// Implementations of the sorting algorithms

template <class T>
void BubbleSort(std::vector<T> &vec, int start, int end) {
    for (int i = start; i <= end; i++) {
        for (int j = start + 1; j <= end; j++) {
            if (vec[j - 1] > vec[j]) { // check if left is bigger than right. If it is, swap them
                T temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = temp;
            }
        }
    }
}



template <class T>
void InsertionSort(std::vector<T> &vec, int start, int end) {
    for (int i = start; i <= end; i++) {
        T target = vec[i];
        int j;
        for (j = i - 1; j >= start; j--) {
            if (vec[j] > target) {
                vec[j + 1] = vec[j];
            } else {
                break;
            }
        }
        // j should be at the index right before the insert
        vec[j + 1] = target;
    }
}

template <class T>
void Merge(std::vector<T> &vec, int start, int mid, int end) {
    // create temporary vectors with left and right sides
    std::vector<T> left, right;
    for (int i = start; i <= mid; i++) {
        left.push_back(vec[i]);
    }

    for (int i = mid + 1; i <= end; i++) {
        right.push_back(vec[i]);
    }

    int i = 0;
    int j = 0;
    int vec_index = start; // from start - end sort these numbers

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            vec[vec_index] = left[i];
            i++;
        } else {
            vec[vec_index] = right[j];
            j++;
        }
        vec_index++;
    }

    // these two may not be the same size so add whatever is left

    while (i < left.size()) {
        vec[vec_index] = left[i];
        i++;
        vec_index++;
    }

    while (j < right.size()) {
        vec[vec_index] = right[j];
        j++;
        vec_index++;
    }
}


template <class T>
void MergeSort(std::vector<T> &vec, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start)/2;
    MergeSort(vec, start, mid);
    MergeSort(vec, mid + 1, end);
    Merge(vec, start, mid, end);
}

template <class T>
void IterativeMerge(std::vector<T> &vec, std::vector<T> &temp, int from, int mid, int index) {
    int k = from, i = from, j = mid + 1;
    while (i <= mid && j <= index) {
        if (vec[i] < vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    // copy remaining elements
    while (i < vec.size() && i <= mid) {
        temp[k++] = vec[i++];
    }

    for (int i = from; i <= index; i++) {
        vec[i] = temp[i];
    }
}

template <class T>
void IterativeMergeSort(std::vector<T> &vec, int start, int end) {
    std::vector<T> temp; // copy vec to temp
    for (T data : vec) {
        temp.push_back(data);
    }

    for (int m = 1; m <= end - start; m = 2*m) {
        for (int i = start; i < end; i += 2 * m) {
            int from = i;
            int mid = i + m - 1;
            int index;

            if (i + 2*m - 1 < end) {
                index = i + 2*m - 1;
            } else {
                index = end;
            }

            IterativeMerge(vec, temp, from, mid, index);
        }
    }
}