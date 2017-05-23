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


using namespace std;

int findMinimum(vector < int > arr, int low, int high) {
    if (high < low) {
        return arr[0];
    }
    if  (high == low) {
        return arr[low];
    }

    int mid = low + (high -low) / 2;
    
    if (mid != 0) {
        if (arr[mid] < arr [mid - 1]) {
            return arr[mid];
        }
    }

    if (arr[mid] < arr[high]) {
        return findMinimum(arr, low, mid - 1);
    } else {
        return findMinimum(arr, mid + 1, high);
    }

}



/*
 *  * Complete the function below.
 *   */
int findMinimum(vector < int > arr) {
    
    return findMinimum(arr, 0, arr.size() - 1); 

}



int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _arr;
    int _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        cin >> _arr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arr.push_back(_arr_item);
    }

    res = findMinimum(_arr);
    cout << res << endl;

    fout.close();
    return 0;
}

#if 0
10
11
12
13
14
15
16
17
18
1
2
#endif
