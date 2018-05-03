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
vector < int > topK(vector < int > iStream, int iK) {

    priority_queue<int, vector<int>, greater<int>> min_pq;

    for (auto itr : iStream) {
        if (min_pq.empty() || min_pq.size() < iK) {
            min_pq.push(itr);
        } else {
            if (min_pq.top() < itr) {
                min_pq.pop();
                min_pq.push(itr);
            }
        }
    }

    vector <int> res;
    while (!min_pq.empty()) {
        res.push_back(min_pq.top());
        min_pq.pop();
    }
    return res;
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;

    int _iStream_size = 0;
    cin >> _iStream_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _iStream;
    int _iStream_item;
    for(int _iStream_i=0; _iStream_i<_iStream_size; _iStream_i++) {
        cin >> _iStream_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _iStream.push_back(_iStream_item);
    }

    int _iK;
    cin >> _iK;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = topK(_iStream, _iK);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}

#if 0 
i/p
7
1
23
12
9
30
2
50
2
o/p
50
30
#endif
