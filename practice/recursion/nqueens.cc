#include <iostream>
#include <vector>
using namespace std;


    
void swap(int arr[], int i, int start)
{
    int tmp = arr[i];
    arr[i] = arr[start];
    arr[start] = tmp;
}

bool diag_kill(int arr[],  int start) 
{
    int col1 = start;
    int row1 = arr[start];
    if (start == 0) {
        return false;
    }
    for (int i = 0; i < start; i++) {
        int row2= arr[i];
        int col2 = i;
        if (abs(col1-col2) == abs(row1-row2)) {
        //if (abs(col1-col2) == abs(row1-row2) == 1) {
         //   cout << "Return true" << endl;
            return true;
        }
    }
    // cout << "Return false" << endl;
    return false;

}

void n_queen(int arr[], int n, int start)
{



    if (start == n) {
        // print the board
        vector <vector <char> > chess(n, vector<char>(n, '0'));
        for (int i = 0; i < n; i++) {
            //cout << arr[i] << " ";
            int row = arr[i];
            chess[row][i] = 'X';
        }
            cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << chess[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return;
    }

    for (int i = start; i < n; i++)  {
            swap(arr, i, start);

            //    cout << "start "<< start << endl;
            if (false == diag_kill(arr, start)) {
          //      cout << "start "<< start << endl;
                n_queen(arr, n, start + 1);
            }
            swap(arr, i, start);
    }

}

    
void nqueen_main(int nq)
{
    int arr[nq];
    for (int n = 0; n < nq; n++) {
        arr[n] = n;
    }
    n_queen(arr, nq, 0);
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nq;
    cin >> nq;
    nqueen_main(nq);
    return 0;
}
