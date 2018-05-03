#include <stdio.h>
#include <iostream>

using namespace std;

void    
create_duplicate_and_print(int myarr[][5], int m, int n)
{
    int **newarr = new int *[m];
    for (int i = 0; i < m; i++) {
        newarr[i] = new int [n]; 
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            newarr[i][j] = myarr[i][j];  
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << newarr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int myarr[4][5] = { 
        {1, 2, 3, 4, 17},
        {5, 6, 7, 8, 18},
        {9, 10, 11, 12, 19},
        {13, 14, 15, 16, 20}
    };
    create_duplicate_and_print(myarr, 4, 5);

}
