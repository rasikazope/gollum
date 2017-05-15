#include <stdio.h>
#include <iostream>

using namespace std;

    
int
lis(int A[], int size)
{
    int cache[size];
    cache[size - 1] = 1;

    for (int i = size-2; i >=0; i--) {
        int max = 0;
        for (int j = i+1; j < size; j++) {
            if (A[i] < A[j] && cache[j] > max) {
                max = cache[j];
            }
        }
        cache[i] = 1 + max;
    }

    int max = 0;
    for (int i = 0; i < size; i++) {
        // cout << cache[i] << " ";
        if (cache[i] > max) {
            max = cache[i];
        }
    }
    cout << endl;
    return max; 
}

// To print the length of longest increasing subsequence.
// To print the subsequence you need to consider the first number in the
// array that is equal to numeber -1. This I think should take care of duplicates

int main()
{

    int arr[] =  {-7, 10, 9, 2, 3, 8, 8, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << lis(arr, size) << endl;
    return 0;
}



