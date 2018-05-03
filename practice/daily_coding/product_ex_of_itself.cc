#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;


//Note to self: We can use only one result array and probably run the loop only only two.
//MY mistake i > = 0

vector <int>
sum_to_k(vector <int> arr) {

    vector <int> arr_before(arr.size());
    vector <int> arr_after(arr.size());
    
    arr_before[0] = 1;
    for (int i = 1; i < arr.size(); i++) {
        arr_before[i] = arr_before[i - 1] * arr[i-1];
    }

    arr_after[arr.size() - 1] = 1;
    for (int i = arr.size() - 2; i >= 0; i--) {
        arr_after[i] = arr[i+1] *arr_after[i+1];
    }

    for (auto itr : arr_before) {
        cout << itr << "  ";
    }

    cout << endl;
    for (auto itr : arr_after) {
        cout << itr << "  ";
    }
    cout << endl;


    for (int i = 0; i < arr.size(); i++) {
        arr[i] = arr_before[i] * arr_after[i];
    }

    return arr;

}


int main() {

    vector <int> arr = {2, 3, 4};
    vector <int> result = sum_to_k(arr);
    for (auto itr:  result) {
        cout << itr << " ";
    }
    return 0;
}
