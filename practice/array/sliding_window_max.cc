#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

void 
sliding_win(int arr[], int size, int k)
{

    deque<int> dq(3);

    int i;
    for (i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (; i < size; i++) {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() < i-k) {
            dq.pop_front();
        }
    
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
     
        dq.push_back(i);

    }


    cout << arr[dq.front()] << " ";
}


int main() 
{

    int arr[] = {2, 3, 5, 7, 8, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    sliding_win(arr, size, 3);
    return 0;
}
