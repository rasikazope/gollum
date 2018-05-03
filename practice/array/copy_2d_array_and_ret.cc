#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int **copy_arr(int arr[][3], int row, int col)
{
    int **newarr = new int *[row];
    for (int i = 0; i < row; i++) {
        newarr[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            newarr[i][j] = arr[i][j];
        }
    }
    return newarr;
}

int main() {

    int arr[][3] = {{ 1, 2, 3},
        {4, 5, 6}};

    int **newarr;
    newarr = copy_arr(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0])/sizeof(arr[0][0]));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << newarr[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
