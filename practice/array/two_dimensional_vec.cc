#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void    
create_duplicate_and_print(vector < vector<int> > myarr, int m, int n)
{
    vector < vector<int> > newarr(m , vector <int> (n, 0));

    newarr = myarr;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << newarr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector < vector <int> > myarr = { 
        {1, 2, 3, 4, 17},
        {5, 6, 7, 8, 18},
        {9, 10, 11, 12, 19},
        {13, 14, 15, 16, 20}
    };
    create_duplicate_and_print(myarr, 4, 5);

}
