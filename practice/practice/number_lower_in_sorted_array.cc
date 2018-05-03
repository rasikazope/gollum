#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int
floor_of_arr(vector <int> arr, int num)
{
    int start = 0;
    int end = arr.size() -1;

    int result = -1;
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == num) {
            return num;
        }
        if (num < arr[mid]) {
            end = mid - 1;
        } else {
            result = arr[mid];
            start = mid + 1;
        }
    }

    return result;
}


int main() {

    vector <int> arr =  {5, 8, 9, 10, 18};
    cout << floor_of_arr(arr, 8) << endl;
    return 0;
}
