//
// Created by Fatma on 3/9/2025.
//
#include <iostream>
#include <vector>
using namespace std;


/// small note the avg , worst , every cases are for the comparisons and moves also
/// in any sorting algo


/**
 *
 * in place
 * stable
 *
 * first approach :
 *
 * its idea is looping n-1 to ensure
 * that every position has the max value as selection but in opposite direction
 * first max , second max but in the back
 *
 *  and for checking for that  and moving we check for each adjacent and swap if the order is wrong
 *  the outer loop is n-1 as the first element will be of course sorted
 *  the inner one is n-1-i as each iteration from the outer ensures that the last and before the last and so on is sorted
 *
 *  for some optimizing if there are no swaps so sorted so break and stop
 *  for average , worst --> O(n^2)
 *  for best  --> O(n)
 *
 * in selection we do one swap
 * but here we swap when the condition is achieved
 *
 * second approach :
 *
 *  the idea ensures that every position takes the smallest one from the begining to the back
 *  similar for the first approach
 *
 *
 *  outer -->  n-1
 *  inner -->  n-1 -> i narrowing
 *            n-1 , n-2 ,....., 1 --> n(n-1)/2
 *
 *  comparison -->  n(n-1)/2 --> every case
 *  swap--> depend on the data so not
 *          always done as in selection (movement)
 *          depends on the condition
 *
 *          best case -> o(1)
 *          worst case -> o(n(n-1)/2)
 *          average case -> o(n(n-1)/2)
 *
 * */

void BubbleSort(vector<int>&v){

    // first approach
    { //bool flag =true; i see better to be in will be more optimized
        // that case will declare it --> 20 30 40 100 50 60 90
        for (int i = 0; i < v.size() - 1; ++i) {// as of course the first element will be organized

            bool flag = true;
            for (int j = 0; j < v.size() - i - 1; ++j) {// as of course the array is being organized from the
                //  back to the begining , so the last and before last are organized
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    flag = false;
                }
            }
            if (flag)
                break;
        }
    }

    // second approach
    {
        for (int i = 0; i <v.size()-1; ++i) {// هنا ضامنة ان اكيد اخر عنصر هيبقي مرتب
            for (int j = v.size()-1; j >i ; --j) {//هنا بضمن اصغر حاجة اللي بترجع ورا عكس اللي فوق
                if(v[j]<v[j-1])                   // كنت بضمن فوق ان اكبر حاجة هتترمي في الاخر
                    swap(v[j],v[j-1]);
            }
        }
    }

}