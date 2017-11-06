#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int i = 0;
        int j = n-1;
        cout << " " << m << " " << n << endl; 
        while (i < m && j >= 0) 
        {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j = j-1;
            } else {
                i = i+1;
            }
            
        }
        return false;
}



int main() {
    vector < vector<int> > matrix = { {1, 2, 3},
                                       {4, 5, 6},
                                        {7, 8, 9}};

    cout << endl << searchMatrix(matrix, 7) << endl;
    return 0;
}
