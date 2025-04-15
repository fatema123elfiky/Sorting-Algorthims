#include <iostream>
#include <vector>
using namespace std;

/**
 *
 * the idea about dividing it into layers
 * till the layer make the gaps difference is 1
 * and sort these layers as insertion , this optimized the insertion process
 * they are near to each other
 *
 * O(n^1.5)
 * in place
 * stable
 *https://chatgpt.com/c/67d078e8-cfd4-8002-b58b-9ce983494d5e
 * https://www.geeksforgeeks.org/shell-sort/
 * that links for the complexity
 * */


// near to gapped bubble sort
void ShellSort(vector<int>&v){

    for (int gap = v.size()/2; gap >0 ; gap/=2) {

        for (int i = gap; i <v.size() ; ++i) {
            int j=i;
            while (j>=gap&&v[j]<v[j-gap]){
                swap(v[j],v[j-gap]);
                j-=gap;
            }
        }
    }

}

// not gapped one
void ShellSort_2(vector<int>&v){

    for (int gap = v.size()/2; gap >0 ; gap/=2) {

        for (int i = gap; i <v.size() ; ++i) {
            int j=i;
            int key=v[i];
            while (j>=gap&&key<v[j-gap]){
                v[j]=v[j-gap];
                j-=gap;
            }
            v[j]=key;
        }
    }

}



int main(){}