#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int *
stockspan(int arr[], int size) {
    stack <int> st;

    int *ret_arr = new int[size];
    for (int i = 0; i < size; i++) {

        if (i != 0) {
            while (!st.empty() && (arr[st.top()] < arr[i])) {
                st.pop();
            }
            cout << i - st.top() << " ";
            ret_arr[i] = i - st.top(); 
        }
        st.push(i);
    }
    return ret_arr;
}


int main() {

    int arr[] = { 100, 80, 60, 70, 60, 75, 85};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    int *ret_arr = stockspan(arr, size);
    
    for (int i = 0; i < size; i++) {
        cout << ret_arr[i] <<  " " ;
    }

    return 0;
}
