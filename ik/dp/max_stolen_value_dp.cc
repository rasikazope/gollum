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
int maxStolenValue(vector < int > arrHouseValues, int end) {

    int ret1 = INT_MIN;
    int ret2 = INT_MIN;
    vector <int> cache(arrHouseValues.size(), 0);

    for (int end = 0; end < arrHouseValues.size(); end++) {
        ret1 = INT_MIN;
        ret2 = INT_MIN;
        ret1 = arrHouseValues[end];
        if (end-2 >= 0) {
            ret1 += cache[end-2];
        }
        if (end-1 >= 0) {
            ret2 = cache[end-1];
        }
        cache[end] = max(ret1, ret2);
    }
    cout << endl;
    for (int end = 0; end < cache.size(); end++) {
        cout << cache[end] << " ";
    }
    cout << endl;
    return cache[arrHouseValues.size() - 1];
}

int maxStolenValue(vector < int > arrHouseValues) {
    return maxStolenValue(arrHouseValues, arrHouseValues.size() - 1);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _arrHouseValues_size = 0;
    cin >> _arrHouseValues_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _arrHouseValues;
    int _arrHouseValues_item;
    for(int _arrHouseValues_i=0; _arrHouseValues_i<_arrHouseValues_size; _arrHouseValues_i++) {
        cin >> _arrHouseValues_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arrHouseValues.push_back(_arrHouseValues_item);
    }

    res = maxStolenValue(_arrHouseValues);
    cout << res << endl;

    fout.close();
    return 0;
}


