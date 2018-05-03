#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


void print_subsets(int arr[], int n, int dec[], int start) 
{


    if (start == n) {
        for (int i = 0; i < n; i++) {
            if (dec[i] == 1) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    dec[start] = 0;
    print_subsets(arr, n, dec, start + 1);
    dec[start] = 1;
    print_subsets(arr, n, dec, start + 1);
}

void print_subsets_main(int arr[], int n) 
{
    int dec[n];
    for (int i = 0; i < n; i++) {
        dec[i] = 0;
    }
    print_subsets(arr, n, dec, 0);

}


int main()
{

    int arr[] = {1, 2, 3, 4};
    print_subsets_main(arr, sizeof(arr)/sizeof(arr[0]));
    // print_subsets_main(arr, 4);
    return 0;
}
