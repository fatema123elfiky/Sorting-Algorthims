//
// Created by Fatma on 4/15/2025.
//

#ifndef SORTING_ALGORTHIMS_SORTINGALGOS_H
#define SORTING_ALGORTHIMS_SORTINGALGOS_H

template<typename  T>
class SortingAlgos {
    private:

        T* data;
        int size;

        void merge(int left , int mid , int right );// Merge Sort helper function
        int partition(int low , int high);// Quick Sort helper function


    public:
        SortingAlgos(int n);
        ~SortingAlgos();

        void insertionSort();
        void selectionSort();
        void bubbleSort();
        void shellSort();
        void quickSort(int left , int right);
        void mergeSort(int left , int right);
        void countSort();
        void radixSort();
        void bucketSort();

        void displayData();
        void measureSortTime(void (SortingAlgos<T>::*sortFunc) () );
        void measureSortTime(void (SortingAlgos<T>::*sortFunc) (int left , int right) , int left ,int right );
        void viewMenu();
};


#endif //SORTING_ALGORTHIMS_SORTINGALGOS_H
