//
// Created by Fatma on 4/15/2025.
//

#include "SortingAlgos.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <type_traits>
using namespace std;

void* Array;
string choice_sorting;
bool isFile= false;


//Helper functions
string check_menu(const string& menuText ,const string choices[],int size ){
    string currentAnswer;

    while(true){
        cout << menuText ;
        if(isFile)
            return "";
        getline(cin, currentAnswer);
        if(currentAnswer.size() != 1 || find(choices,choices+size, currentAnswer) == choices+size)
            cout << "Try again !!\n\n" ;
        else
            break;
    }
    cin.ignore(0, '\n');

    return currentAnswer;
}

bool isDigit(const string& number){

    for(char digit :number)
        if(!isdigit(digit))
            return false;

    return true;
}



// Methods of the class
template<typename T>
void SortingAlgos<T> :: viewMenu(){


    again:

    // choosing the type of sorting algo
    string text ="Select a sorting algorithm: \n1. Insertion Sort \n"
                 "2. Selection Sort \n"
                 "3. Bubble Sort \n"
                 "4. Shell Sort \n"
                 "5. Merge Sort \n"
                 "6. Quick Sort \n"
                 "7. Count Sort (Only for integers) \n"
                 "8. Radix Sort (Only for integers) \n"
                 "9. Bucket Sort \n"
                 "Enter your choice : ";
    string choices[9]={"1","2","3","4","5","6","7","8","9"};
    string choice;
    if(!isFile)
        choice=check_menu(text,choices,9);
    else
        choice=choice_sorting;





    if(choice=="1") {

        cout<<"Sorting using insertion ... \n";
        cout<<"Initial data : ";
        displayData();
        cout<<'\n';
        measureSortTime(&SortingAlgos<T>::insertionSort);

    }
    else if(choice=="2") {

        cout<<"Sorting using selection ... \n";
        cout<<"Initial data : ";
        displayData();
        cout<<'\n';
        measureSortTime(&SortingAlgos<T>::selectionSort);

    }
    else if(choice=="3") {

        cout<<"Sorting using bubbleSort ... \n";
        cout<<"Initial data : ";
        displayData();
        cout<<'\n';
        measureSortTime(&SortingAlgos<T>::bubbleSort);

    }
    else if(choice=="4") {

        cout<<"Sorting using shellSort ... \n";
        cout<<"Initial data : ";
        displayData();
        cout<<'\n';
        measureSortTime(&SortingAlgos<T>::shellSort);

    }
    else if(choice=="5") {

        cout<<"Sorting using merge sort ... \n";
        cout<<"Initial data : ";
        displayData();
        cout<<'\n';
        measureSortTime(&SortingAlgos<T>::mergeSort,0,size-1);

    }
    else if(choice=="6") {
        cout<<"Sorting using quicksort ... \n";
        cout<<"Initial data : ";
        displayData();
        cout<<'\n';
        measureSortTime(&SortingAlgos<T>::quickSort,0,size-1);
    }
    else if(choice=="7"){

        if constexpr (is_integral<T>::value) {
            cout<<"Sorting using count sort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingAlgos<T>::countSort);

        }else {
            cout << "Sorry ,Try again!!\n\n";
            goto again;
        }

    }else if(choice=="8"){

        if constexpr (is_integral<T>::value) {
            cout<<"Sorting using radix sort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingAlgos<T>::radixSort);

        }else {
            cout << "Sorry ,Try again!!\n\n";
            goto again;
        }

    }else {

        if constexpr (is_arithmetic<T>::value) {
            cout<<"Sorting using bucket sort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingAlgos<T>::bucketSort);

        }else {
            cout << "Sorry ,Try again!!\n\n";
            goto again;
        }
    }




}

template <typename T>
void SortingAlgos<T>::displayData() {

    cout<<"[";
    for (int index = 0; index < size-1; ++index)
        cout<<data[index]<<", ";
    cout<<data[size-1]<<"]\n";

}

template <typename T>
SortingAlgos<T>::SortingAlgos(int n):size(n) {

    if(n<=0)
        size=1;

    // setting data with values
    if(!isFile) {
        data = new T[size];
        int counter=0;
        while (counter<size) {
            cout << "Enter data " << counter+1 << ": ";
            cin>>data[counter++];
        }
    }
    else
        data=static_cast<T*>(Array);

    viewMenu();
}

template <typename T>
SortingAlgos<T>::~SortingAlgos() {
    delete [] data ;
}

template <typename T>
void SortingAlgos<T>::measureSortTime(void (SortingAlgos<T>::*sortFunc)()) {

    // instant time
    auto start= chrono::high_resolution_clock ::now();
    // function is executed
    (this->*sortFunc)();
    // instant time
    auto end=chrono::high_resolution_clock ::now();

    cout<<"\n\n"<<"Sorted data : ";
    displayData();

    //difference between the instants
    chrono:: duration<double> Duration = end-start;
    cout<<"Sorting Time: "<<Duration.count()<<" seconds\n"
        <<"------------------------------------------------------\n\n\n";

}

template<typename T>
void SortingAlgos<T>::measureSortTime(void (SortingAlgos<T>::*sortFunc)(int, int), int left, int right) {

    // instant time
    auto start= chrono::high_resolution_clock ::now();
    // function is executed
    (this->*sortFunc)(left,right);
    // instant time
    auto end=chrono::high_resolution_clock ::now();

    cout<<"\n\n"<<"Sorted data : ";
    displayData();

    //difference between the instants
    chrono:: duration<double> Duration = end-start;
    cout<<"Sorting Time: "<<Duration.count()<<" seconds\n"
        <<"------------------------------------------------------\n\n\n";
}



template<typename T>
void SortingAlgos<T>::insertionSort() {

    /**iterating on each element to set it in right position*/
    for (int index = 1,sub_index; index < size ; ++index) {

        T key=data[index];
        /**setting the key in the right position in the sorted subarray*/
        for ( sub_index = index-1; sub_index >=0 ; --sub_index) {
            if(data[sub_index]>key)
                data[sub_index+1]=data[sub_index];
            else
                break;
        }
        data[sub_index+1]=key;

        cout<<"Iteration "<<index<<" : ";
        displayData();

    }

}

template<typename T>
void SortingAlgos<T>::selectionSort() {


    /**iterating on each position and find the best value matches that position*/
    for (int index = 0,least; index < size; ++index) {

        least=index;

        /**getting the index of the least value in the second part of
        the array to set it in that position*/
        for (int pointer = index+1; pointer < size ; ++pointer) {
            if(data[least]>data[pointer])
                least=pointer;
        }
        swap(data[least],data[index]);

        cout<<"Iteration "<<index+1<<" : ";
        displayData();

    }


}

template<typename T>
void SortingAlgos<T>::bubbleSort() {

    /**it is about shuffling the numbers until it reaches the correct position.
     as we shuffle every two adjacent elements.*/
    for (int index = 0; index < size-1; ++index) {

        for (int sub_index = 0; sub_index < size-index-1; ++sub_index) {
            if(data[sub_index]>data[sub_index+1])
                swap(data[sub_index],data[sub_index+1]);
        }

        cout<<"Iteration "<<index+1<<" : ";
        displayData();
    }


}

template<typename T>
void SortingAlgos<T>::shellSort() {

    /**dividing it into gaps by dividing two each time until it becomes 0 then stops*/
    for (int gap = size/2; gap > 0; gap/=2) {

        cout<<"After gap of size "<<gap<<" : ";

        /** that loop responsible for iterating on each element to sort it in its gap
         * we sort it by insertion and that way decreases the process of sorting by insertion at the end*/
        for (int index = gap; index < size ; ++index) {

            int gaped_index=index;
            while (gaped_index>=gap&&data[gaped_index]<data[gaped_index - gap ])
                swap(data[gaped_index],data[gaped_index - gap ]),gaped_index-=gap;

        }
        displayData();

    }


}

template<typename T>
void SortingAlgos<T>::mergeSort(int left, int right) {

    if(left>=right)
        return;

    int mid=(left+right)/2;

    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);

}

template<typename T>
void SortingAlgos<T>::merge(int left, int mid, int right) {

    int size_1 = mid-left+1 , size_2 = right-mid;

    T*part_1=new T[size_1];
    T*part_2=new T[size_2];

    /**taking the left sorted part from the given subarray and the right sorted part
     * from the given subarray and putting each of them in seperated array*/
    for (int index = left,index_2=0; index <= mid; ++index,index_2++)
        part_1[index_2]=data[index];
    for (int index = mid+1,index_2=0; index <= right; ++index,index_2++)
        part_2[index_2]=data[index];


    /**sorting that subarray by iterating on the two sub-arrays of the subarray and insert
     in the subarray by comparing the two sub-arrays*/
    int pointer_1=0,pointer_2=0,pointer=left;
    while (pointer_1<size_1 && pointer_2<size_2){
        if(part_1[pointer_1]<=part_2[pointer_2])
            data[pointer++]=part_1[pointer_1++];
        else
            data[pointer++]=part_2[pointer_2++];
    }

    /**for inserting elements if there are some not inserted */
    while (pointer_1<size_1)
        data[pointer++]=part_1[pointer_1++];
    while (pointer_2<size_2)
        data[pointer++]=part_2[pointer_2++];

    cout<<"Sorted part of size "<<size_1+size_2<<" : [";
    for (int index = left; index <right ; ++index)
        cout<<data[index]<<',';
    cout<<data[right]<<"]\n";

    delete [] part_1;
    delete [] part_2;

}

template<typename T>
void SortingAlgos<T>::quickSort(int left, int right) {

    if(left>=right)
        return;
    int pivot = partition(left,right);


    cout<<"Pivot: "<<data[pivot]<<" -->";
    if(pivot!=left){
        cout<<" [";
        for (int index = left; index < pivot - 1; ++index)
            cout << data[index] << ", ";
        cout << data[pivot - 1] << "] " << data[pivot] << " [";
    }else
        cout<<data[pivot]<< " [";
    for (int index = pivot+1; index < right ; ++index)
        cout<<data[index]<<", ";
    cout<<data[right]<<"]\n";


    quickSort(left,pivot-1);
    quickSort(pivot+1,right);
}

template <typename T>
int SortingAlgos<T>::partition(int low, int high) {

    T pivot = data[low];
    int pointer_1=low;

    /**after choosing the pivot separating the array into two ones in the same array one is less than the pivot
    the other greater than te pivot and the quick sort divide from that pivot and organize that recursively*/
    for (int pointer_2 = low+1; pointer_2 <= high ; ++pointer_2)
        if(data[pointer_2]<pivot)
            swap(data[++pointer_1],data[pointer_2]);


    swap(data[pointer_1],data[low]);
    return pointer_1;

}





template <typename T>
void SortingAlgos<T>::countSort() {

    //Zero-Based
    T * sorted_array = new T [size];

    int max = *( max_element(data , data+size) );
    int * freq_array = new int [max+1];

    // the idea about counting the repeating times of certain number and accumulating that array
    for (int index = 0; index <= max; ++index)
        freq_array[index]=0;
    cout<<"Number of times of appearing that numbers : \n\n";
    for (int index = 0; index < size; ++index)
        freq_array[data[index]]++;
    for (int index = 0; index < size; ++index)
        cout<<data[index]<<" appears in --> "<<freq_array[data[index]]<<" times\n";
    for (int index = 1; index <=max ; ++index)
        freq_array[index]+=freq_array[index-1];


    // positioning the elements sorted
    for (int index = size-1; index >=0 ; --index) {
        int new_position = --freq_array[ data[index] ];
        sorted_array[new_position]=data[index];
    }

    delete[] freq_array , delete [] data;
    data=sorted_array;
}

template<typename T>
void SortingAlgos<T>::radixSort() {

    T * sorted_array= new T[size];
    int * freq_array  = new int [10];
    int max = * (max_element(data,data+size));

    // same idea of counting sort but extra external loop to sort according to digits
    for (int divisor = 1; max/divisor > 0 ; divisor*=10) {

        // the idea about counting the repeating times of certain digit and accumulating that array
        cout<<"After sorting according to "<<divisor<<"th : ";
        for (int index = 0; index < 10; ++index)
            freq_array[index]=0;
        for (int index = 0; index < size; ++index) {
            int digit= (data[index] / divisor) % 10 ;
            freq_array[digit]++;
        }
        for (int index = 1; index < 10; ++index)
            freq_array[index]+=freq_array[index-1];

        // positioning the elements sorted
        for (int index =size-1; index >=0 ; --index) {
            int digit= (data[index] / divisor) % 10 ;
            int new_position=--freq_array[digit];
            sorted_array[new_position]=data[index] ;
        }
        swap(sorted_array,data);
        displayData();
        cout<<'\n';
    }
    delete [] sorted_array;
    delete [] freq_array;
}

template<typename T>
void SortingAlgos<T>::bucketSort() {


    T maxValue= *max_element(data,data+size);
    T minValue= *min_element(data,data+size);

    // in case of equality , it is sorted and to avoid the zero case
    if(minValue==maxValue) {
        cout<<"It is already sorted\n";
        return;
    }

    double Bucket_Width;
    int* counts = new int [size]();

    if constexpr (is_arithmetic<T>::value){

        /**getting the bucket width as we do in stat to know width range as to make array of size 'size'
         and fit that values which may be greater than the size itself*/
        if constexpr (is_integral<T>::value)
        Bucket_Width=  double(maxValue - minValue + 1) / size;
        else
        Bucket_Width=  double(maxValue - minValue) / size;


        /**here we rescale the value itself according to the bucket width and the size of the bucket
         we count also the number of occurrences of each value to know the allocated array for that value
         in the bucket (it is about memory management)*/
        for (int pointer = 0; pointer < size; pointer++) {
            int index = min( (int) floor ((data[pointer] - minValue) / Bucket_Width) , size - 1);
            counts[index]++;
        }

    }

    //we allocate here by the counts we calculated
    T** buckets = new T*[size];
    for (int index = 0; index < size; index++)
        buckets[index] = new T[counts[index]];

    // resetting it as when we set values set them by increasing the pointer
    // (they will play the role of pointers)
    for (int index = 0; index < size; index++)
        counts[index] = 0;

    if constexpr (is_arithmetic<T>::value) {

        // assigning the values in the correct place in the buckets
        for (int pointer = 0; pointer < size; pointer++) {
            int index = min((int) floor((data[pointer] - minValue) / Bucket_Width), size - 1);
            buckets[index][counts[index]++] = data[pointer];
        }
    }

    cout<<"Before sorting \n\n";
    for (int index = 0; index < size; ++index) {
        if(counts[index]){
            cout<<"Bucket number : "<<index<<" contains --> ";
            for (int pointer = 0; pointer < counts[index]-1; ++pointer)
                cout<<buckets[index][pointer]<<", ";
            cout<<buckets[index][counts[index]-1]<<'\n';
        }
    }

    // sort that buckets
    for (int index = 0; index < size; index++)
        if (counts[index] > 0)
            sort(buckets[index], buckets[index] + counts[index]);


    cout<<"After sorting \n\n";
    for (int index = 0; index < size; ++index) {
        if(counts[index]){
            cout<<"Bucket number : "<<index<<" contains --> ";
            for (int pointer = 0; pointer < counts[index]-1; ++pointer)
                cout<<buckets[index][pointer]<<", ";
            cout<<buckets[index][counts[index]-1]<<'\n';
        }
    }

    // integrating the sorted buckets in the data array
    int position = 0;
    for (int index_row = 0; index_row < size; index_row++)
        for (int index_column = 0; index_column < counts[index_row]; index_column++)
            data[position++] = buckets[index_row][index_column];

    for (int index = 0; index < size; index++)
        delete[] buckets[index];

    delete[] buckets;
    delete[] counts;




}
