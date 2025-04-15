#include <iostream>
#include <vector>
using namespace std;

/**
 * complexity of the code
 * is discussed by the tree in the slides and CB notes
 * O( n*log(n) )
 *  not inplace
 *  stable --> not sure
 * */
void Sort(vector<int>&v,int l , int r, int mid){

    vector<int>L,R;
    for (int i = l; i <=mid ; ++i)
        L.push_back(v[i]);

    for (int i = mid+1; i <=r ; ++i)
        R.push_back(v[i]);


    int i=0,j=0,k=l;
    while (i<L.size()&&j<R.size()){

        if(L[i]<=R[j])
            v[k++]=L[i++];
        else
            v[k++]=R[j++];

    }

    while (i<L.size())
        v[k++]=L[i++];

    while (j<R.size())
        v[k++]=R[j++];


}



void mergeSort(vector<int>&v,int l,int r){

    if(l>=r)return;
    int mid=(l+r)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    Sort(v,l,r,mid);
}

int main(){}