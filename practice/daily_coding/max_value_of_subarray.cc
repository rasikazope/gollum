/*Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
 *
 * For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:
 *
 * 10 = max(10, 5, 2)
 * 7 = max(5, 2, 7)
 * 8 = max(2, 7, 8)
 * 8 = max(7, 8, 7)
 * Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
 */

#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


void
max_value_of_subarray(vector <int> arr, int k) 
{
    deque <int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << endl;
    dq.pop_front();

    for (int i = k; i < arr.size(); i++) {
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        cout << arr[dq.front()] << endl;
        if (dq.front() <= i - k) {
            dq.pop_front();
        }
    }

}

int main() {
    // vector <int> arr =  {10, 5, 7, 8, 7};  
    vector <int> arr =  {2, 1, 8, 10, 5, 7, 8, 7};  
    max_value_of_subarray(arr, 3);
    return 0;
}


