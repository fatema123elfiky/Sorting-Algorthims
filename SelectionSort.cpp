//
// Created by Fatma on 3/9/2025.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * the algorithm is "every case" as
 * the best = worst = average
 * it does not depend on the data
 * so O(N^2) --> as the inner loop +outer loop
 *              n(n-1)/2 as loops from n-1 , n-2 ,n-3 ,... 1
 *  not stable
 *  inplace
 *
 *  comparisons : n(n-1)/2
 *  swaps : n-1
 *  moves : 3 (n-1) (as movement is the swap)
 *
 *  we can make small optimize to check if it is sorted or not before entering the function
 *
 * */

void SelectionSort(vector<int>& v){

    for (int i = 0,j,least; i < v.size()-1; ++i) {// till n or n-1 no difference
                                   //------> n-1

        // three Ptrs one for searching for the minimum one , the other
        // one for the first, second,... positions and the third one for comparing
        for ( j = i+1,least=i; j <v.size() ; ++j) {//------> n-1 , n-2 , ....,1 (n*(n-1)/2)
            if(v[j]<v[least])// no movement in that loop
                             // comparisons  n(n-1)/2
                least=j;
        }

        // n-1 (in selection the movement here is the swap , and n-1 but in insertion , the  movements were n(n-1)/2)
        swap(v[i],v[least]);// swaping to get the smallest one in the subarray
    }

}
