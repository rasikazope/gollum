#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 *  * Complete the function below.
 *   */

void
ci_util(vector <vector <int> > imatrix, vector < vector <int> > &visited, int i, int j)
{
    if (i < 0 || i >= imatrix.size() || j < 0 || j >= imatrix[0].size()) {
        return;
    }

    if (visited[i][j] == 1) {
        return;
    }
    
    visited[i][j] = 1;
    
    if (imatrix[i][j] == 0) {
        return;
    }


    ci_util(imatrix, visited, i-1, j);
    ci_util(imatrix, visited, i, j-1);
    ci_util(imatrix, visited, i+1, j);
    ci_util(imatrix, visited, i, j+1);
}



int countIslands_main(vector < vector < int > > imatrix) {
    vector < vector <int> > visited(imatrix.size(), vector<int> (imatrix[0].size() , 0));

    int count = 0;
    
    for (int i = 0; i < imatrix.size(); i++) {
        for (int j = 0; j < imatrix[0].size(); j++) {
            if (imatrix[i][j] == 1 && visited[i][j] == 0) {
                ci_util(imatrix, visited, i, j);
                count++;
            }
        } 
    }
    return count;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _imatrix_rows = 0;
    int _imatrix_cols = 0;
    cin >> _imatrix_rows >> _imatrix_cols;
    vector< vector < int > > _imatrix(_imatrix_rows);
    for(int _imatrix_i = 0; _imatrix_i<_imatrix_rows; _imatrix_i++) {
        for(int _imatrix_j=0; _imatrix_j<_imatrix_cols; _imatrix_j++) {
            int _imatrix_tmp;
            cin >> _imatrix_tmp;
            _imatrix[_imatrix_i].push_back(_imatrix_tmp);
        }
    }

    res = countIslands_main(_imatrix);
    cout << res << endl;

    fout.close();
    return 0;
}

/*
 * input
 4
 4
 0
 1
 0
 0
 1
 1
 0
 0
 0
 0
 1
 1
 0
 0
 1
 0
 outout is 2
 */


