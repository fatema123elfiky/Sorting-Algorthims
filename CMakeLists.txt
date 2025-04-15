cmake_minimum_required(VERSION 3.27)
project(Sorting_Algorthims)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sorting_Algorthims
        BubbleSort.cpp
        BucketSort.cpp
        CountingSort.cpp
        InsertionSort.cpp
        MergeSort.cpp
        QuickSort.cpp
        RadixSort.cpp
        SelectionSort.cpp
        ShellSort.cpp
        SortingAlgos.cpp
        SortingAlgos.h
)
