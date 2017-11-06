#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int
subarray(vector <short int> myarr, long target)
{
    long sum = myarr[0];
    int counter = 0, left = 0, right = 1;

    while (right < myarr.size() && left <= right) {
       
        if (sum == target) {
            counter = counter + 1;
            left++;
            right = left + 1;
        } else if (sum < target) {
            sum = sum + myarr[right];
            right++;
        } else {
            sum = sum - myarr[left];
            left++;
        }
    }
    return counter;
}


int main() {

    vector <short int> myarr = {1, 1, 1, 1};
    cout<< "Counter " << subarray(myarr, 2) << endl;
    return 0;
}
