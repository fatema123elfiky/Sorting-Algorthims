//
// Created by Fatma on 3/23/2025.
//
#include <iostream>
#include <vector>
using namespace std;

///Linear sorting
/**
 *
 * the idea of it initialize array c to zeros
 * make freq array for the elements
 * accumulate the array as prefix sum
 * as this says at each value how many elements are smaller than me or equal to me
 * so in that way i will know my index
 * then we iterate from the back to the begin as ohh that three which is repeated twice
 * so takes index .. and when go to the first will take index less and that to maintains the concept of
 * stability
 *
 * complexity of O(n+k)--> k for biggest element
 * problem of algo is the memory+ if nums are negative , decimals
 *
 * no comparison is done
 * i think radix sort solved that issue(memory issue)
 *
 * not in-place , stable
 * */

vector<int> countingSort(vector<int>&v){

    if(!v.size()||v.size()==1)
        return v;

    vector<int>b(v.size()+1);

    int maxi=v[0];
    for (int i = 0; i < v.size(); ++i)
        maxi=max(maxi,v[i]);

    vector<int>c(maxi+1);
    for (int i = 0; i < c.size(); ++i)
        c[i]=0;

    for (int i = 0; i < v.size(); ++i)
        c[v[i]]++;
    for (int i = 1; i <=maxi ; ++i)
        c[i]+=c[i-1];
    for (int i = v.size()-1; i >=0; --i)
        b[c[v[i]]--]=v[i];

    return {b.begin()+1,b.end()};


}

int main(){}