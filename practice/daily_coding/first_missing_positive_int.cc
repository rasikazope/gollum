#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


void swap (int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}


int
first_missing_pos_num(vector <int> arr)
{
    // Note: don't increment i in this loop
    for (int i = 0; i < arr.size();) {
        if (arr[i] < 0 && arr[i] > arr.size()) {
            i++;
        } else {
            int index = arr[i];
            swap(arr[i], arr[index-1]);
            i++;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != i+1) {
            return i + 1;
        }
    }
    return arr.size() + 1;
}


int main() {

    vector <int> arr =  {1, 3, 4, 2 , -4, -6};
    cout << first_missing_pos_num(arr) << endl;
    return 0;
}
