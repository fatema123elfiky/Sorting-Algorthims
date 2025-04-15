#include <iostream>
#include <vector>
using namespace std;

/**
 * Insertion sort
 * time complexity--> say the three cases and if not say every case
 *                    and its time
 *
 * best case --> O(n) (sorted)
 * moves --> 2n of the key and the assignment of the key
 * comparison --> n of inner loop
 *
 * worst case --> O(n^2) (reversed in the sort)
 * comparisons --> O(n(n-1)/2) as 1, 2 , 3 ,.... , n-1
 * moves --> O(n(n-1)/2 + n-1 + n-1 )
 *
 * average case --> O(n^2) (semi)
 * similar to worst but divided by two for the comparisons
 * and one of the moves that in the comparisons loop
 *
 * in-place
 * stable
 *
 * the idea is shifting the elements to the right in case if the element we compare with
 * is larger and we stop when we find the smaller or equal
 * we treat that every part we make in the array is sorted from the previous cases
 *
 *
 * */

void Insertion_Sort(vector<int>& v){

    for (int i = 0,j; i < v.size(); ++i) {// if start 0 or one same

        int key = v[i];// saving the value that we put in right place

        for ( j = i-1; j >=0 ; --j) {

            // shifting right
            if(v[j]>key)
               v[j+1]=v[j];
            else // stopping case as if the key is the smallest one
                break;

        }
        v[j+1]=key;// so we made it out not in the loop

    }

}


//trial
// it is near to the bubble one
void Insertion_Sort_2(vector<int>& v){

    for (int i = 0,j; i < v.size(); ++i) {// if start 0 or one same


        for ( j = i-1; j >=0 ; --j) {

            // shifting right
            if(v[j]>v[j+1])
                swap (v[j+1],v[j]);
            else // stopping case as if the key is the smallest one
                break;

        }

    }

}



int main() {return 0;}
