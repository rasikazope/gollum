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



int countIslands(vector < vector < int > > imatrix, vector < vector < int > > &visit, int i, int j) {

    if (i < 0 || i >= visit.size() || j < 0 || j >= visit.size()) {
        return 0;
    }
    if (visit[i][j] == 1) {
        return 0;
    }

    visit[i][j] = 1;

    if (imatrix[i][j] == 0) {
        return 0;
    }

    // For all neighbors of i, j call countIslands
    countIslands(imatrix, visit, i-1, j);
    countIslands(imatrix, visit, i+1, j);
    countIslands(imatrix, visit, i, j-1);
    countIslands(imatrix, visit, i, j+1);

}



int countIslands_main(vector < vector < int > > imatrix) {
    vector < vector < int > > visit;
    visit = imatrix;
    for (int i = 0; i < imatrix.size(); i++) {
        for (int j = 0; j < imatrix.size(); j++) {
            visit[i][j] = 0;
        }
    }
    int count = 0;
    for (int i = 0; i < imatrix.size(); i++) {
        for (int j = 0; j < imatrix.size(); j++) {
            if (visit[i][j] == 0 && imatrix[i][j] == 1) {
                cout << "Rasika" << endl;
                
                countIslands(imatrix, visit, i, j);
               
                for (int k = 0; k < imatrix.size(); k++) {
                    for (int l = 0; l < imatrix.size(); l++) {
                        cout << visit[k][l] << " ";
                    }
                    cout << endl;
                }
                count ++;
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
