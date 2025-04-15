//
// Created by Fatma on 3/23/2025.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * sort according to the digits but sort by counting sort for each digit
 * they are 7 numbers of 3 digits
 * so i make count sort for 7 numbers of first digit(units)
 * then count sort for 7 numbers of second digit(tens)
 * then count sort for 7 numbers of third digit (hundreds)
 *
 * منطقي ارتب الواحدات و بعدها المؤثر الاكبر العشرات و بعدها اكبر مؤثر الميات
 *
 *
 * so complexity is O(digits*(n+9)) k-> max(9)
 * O(D*N)
 * */

vector<int> RadixSort(vector<int>&v){

    if(v.size()<=1)
        return v;

    vector<int>b(v.size());
    int maxi=v[0];
    for (int i = 0; i < v.size(); ++i)
        maxi= max(maxi,v[i]);

    for (int exp = 1; maxi/exp >0 ; exp*=10) {//iterate on each digit
        vector<int>c(10,0);



        for (int j = 0; j < v.size(); ++j)
            c[ v[j]/exp %10 ]++;
        for (int i = 1; i <=9 ; ++i)
            c[i]+=c[i-1];

        for (int i = v.size()-1; i >=0; --i)
            b[--c[v[i]/exp %10]]=v[i];

        v=b;
    }

    return v;


}

int main(){}