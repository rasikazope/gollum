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

int maxStolenValue(vector < int > arrHouseValues) {
    vector <int> cache(arrHouseValues.size(), 0);

    cache[0] = arrHouseValues[0];
    if (arrHouseValues.size() > 1) {
        cache[1] = max(arrHouseValues[0], arrHouseValues[1]);
        for (int i = 2; i < arrHouseValues.size(); i++) {
            cache[i] = max(arrHouseValues[i]+ cache[i-2], cache[i-1]);
        }
    }
    return cache[arrHouseValues.size() - 1];

    
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

//http://codercareer.blogspot.com/2013/02/no-44-maximal-stolen-values.html
#if 0
input:
5
1
2
3
4
5
output:
9
#endif
