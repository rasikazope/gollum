#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;



using namespace std;

/*
 *  * Complete the function below.
 *   */
int findMinimum(vector < int > arr) {

    int j;
    for (int i = 1, j = 0; i < arr.size(); i++, j++) {
        if (arr[j] > arr[i]) {
            return arr[i];
        }
    }
    return arr[0];
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
3
2
3
1
o/p
1
#endif
