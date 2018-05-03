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

class pair_comp {
    public:
    bool operator() (pair <int, int> mypair1, pair <int, int> mypair2)
        {
            return mypair1.first > mypair2.first;
        }
};


/*
 *  * Complete the function below.
 *   */
vector < int > mergearrays(vector < vector < int > > iarray) {
    priority_queue <pair<int, int>, vector <pair<int, int> >, pair_comp > pq;
    int k = iarray.size();

    for (int a_num = 0; a_num < iarray.size(); a_num++) {
        pq.push(make_pair(iarray[a_num][0], a_num));
    }

    int j[k];
    for (int i = 0; i < k; i++) {
        j[i] = 1;
    }

    vector <int> res;
    while (!pq.empty()) {
        auto itr_pair = pq.top();
        res.push_back(itr_pair.first);
        pq.pop();
        
        int i_index = itr_pair.second;
        int j_index = j[itr_pair.second];
        if (j_index < iarray[i_index].size()) {
            pq.push(make_pair(iarray[i_index][j_index], i_index));
            j[itr_pair.second]++;
        }

    }
    return res;
}



int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;

    int _iarray_rows = 0;
    int _iarray_cols = 0;
    cin >> _iarray_rows >> _iarray_cols;
    vector< vector < int > > _iarray(_iarray_rows);
    for(int _iarray_i=0; _iarray_i<_iarray_rows; _iarray_i++) {
        for(int _iarray_j=0; _iarray_j<_iarray_cols; _iarray_j++) {
            int _iarray_tmp;
            cin >> _iarray_tmp;
            _iarray[_iarray_i].push_back(_iarray_tmp);
        }
    }

    cout << endl << endl;
    res = mergearrays(_iarray);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}



#if 0
i/p:
3
3
1
4
6
2
5
7
3
8
9
o/p
1
2
3
4
5
6
7
8
9

#endif
