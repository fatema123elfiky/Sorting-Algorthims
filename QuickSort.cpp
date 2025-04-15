//
// Created by Fatma on 3/23/2025.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * the idea of quick sort
 * choosing a pivot to sort around it
 * and the part before it sort it in that way recursively
 * and also the second part similar
 *
 * this is done through pointer for the last one which is smaller than the pivot
 * and another pointer that iterate through the array
 * as we iterate on the array this costs O(N)
 *
 * pivot is always the first one for simplicity
 * we make partition and get the new position of the pivot
 * then make quick sort for the first part and for the second part recursively
 *
 * the case of making 4 pivot and looks like that
 * 2 1 3   4   5 6 7 8   ---> the first part as binary tree , the second part is longer
 *                            as 2 halves                     no halves it is minus one only
 *
 *  in best cases as: 2 halves and so on --> each level makes n but no. of levels are logn
 *                                             so complexity of nlogn
 *
 * in worst cases (ordered array) : n-1 , n-2 , n-3 , so on --> N^2
 *
 * in avg case : 0.1n ,0.9n    0.01n,0.09n  0.09n,0.81n  all of that so n in each level
 *               and log n to base 10 as splitted in 1/10,9/10 so we divide on 10
 *
 * so it depends on the choice of the pivot--> middle , median , first
 *  1 4 6 0 7 8 9
 *  if we say the middle always better that case will make that zero at the begining and the rest on one side
 *  so not good --> the middle is good in case tha array is sorted whether ascend or descend
 *
 *  with some proof that even if there are some makes the array 0, n-1 and some n/2, n/2 --. will be nlogn so all cases are nlogn except worst
 *  choose pivot index random --> as will not every time make the condition of 0,n-1
 *
 *  in case of randomized could be not stable--> we will get the pivot in the middle at the begining and solve as we do , but first element could be stable
 *  randomized quick sort better than merge --> as no extra memory allocated+ nlogn
 *  emplace--> no extra memo
 *  stable
 *
 *  Average case takes O(n log(n)) time
 *  Worst case takes O(n2) time
 *  O(1) space
 * */

int partition(vector<int>&v,int l, int r){

    int pivot = v[l];
    int j=l;

    for (int i = l+1; i <=r ; ++i) {
        if(v[i]<pivot)
            swap(v[++j],v[i]);
    }
    swap(v[j],v[l]);
    return j;

}

void Quicksort(vector<int>&v,int l, int r){

    if(l>=r)
        return;

    int pivot = partition(v,l,r);
    Quicksort(v,l,pivot-1);
    Quicksort(v,pivot+1,r);
}



int main(){

    vector<int>v{4,2,3,1,5,6,8,7,-1};
    Quicksort(v,0,8);
    for (int i = 0; i < 9; ++i) {
        cout<<v[i]<<' ';
    }
}
