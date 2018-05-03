#include <stdio.h>
#include <iostream>
using namespace std;

int swap(int arr[], int num1, int num2)
{
    int temp = arr[num1];
    arr[num1] = arr[num2];
    arr[num2] = temp;
}

void per(int arr[], int size, int start)
{
    if (start == size) {
        // print
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i];
        }
    }
    
    for (int i = start; i < size ; i++) {
        swap(arr, start, i);
        per(arr, size, start + 1);
        swap(arr, start, i);
    }

}


int main() {
    int arr[] = {1, 2, 3, 4};
    per(arr, sizeof(arr)/ sizeof(arr[0]), 0);
    return 0;
}
