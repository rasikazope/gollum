#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


#if 0

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

#endif

void wiggle_sort(vector<int>& myvec)
{
   vector <int> sorted(myvec); 
   sort(sorted.begin(), sorted.end());

   for (int i = 0, k = 0, j = myvec.size()/2; i < myvec.size(); i++) {
       if (i % 2 == 0) {
           myvec[i] = sorted[k];
           k++;
       } else {
           myvec[i] = sorted[j];
           j++;
       }
   }

}


int main() {

    vector <int> myvec = {1 ,3, 4, 5, 10, 2, 6 };
    wiggle_sort(myvec);

    for (auto itr: myvec) {
        cout << itr << " ";
    }

    return 0;
}
