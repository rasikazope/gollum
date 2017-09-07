#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool
twosum(vector<int> arr, int sum) 
{
    int l = 0;
    int r = arr.size() - 1;

    
    sort(arr.begin(), arr.end());

    while (l < r) {
        if (arr[l] + arr[r] == sum) {
            return true;
        } else if (arr[l] + arr[r] < sum) {
            l++;
        } else {
            r--;
        }
    }

    return false;
}


int main() {

    vector<int> arr = {10, 5, 6, 7, 8};
    cout << twosum(arr, 10);
    return 0;
}
