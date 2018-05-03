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
vector < string > printTriplets(vector < int > intArr) {

    vector <string> res;
    sort(intArr.begin(), intArr.end());
    int l;
    int r;
    for (int i = 0; i < intArr.size() - 2; i++) {
        l = i + 1;
        r = intArr.size() - 1;
        while (l < r) {
            int sum = intArr[l] + intArr[r] + intArr[i];
            if (sum == 0) {
                stringstream sstr;
                sstr << intArr[i] << ',' << intArr[l] << ',' << intArr[r];
                res.push_back(sstr.str());
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            }
        }
    }
    return res;

}



int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;

    int _intArr_size = 0;
    cin >> _intArr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intArr;
    int _intArr_item;
    for(int _intArr_i=0; _intArr_i<_intArr_size; _intArr_i++) {
        cin >> _intArr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intArr.push_back(_intArr_item);
    }

    res = printTriplets(_intArr);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}


#if 0
i/p
6
10
3
-4
1
-6
9
o/p
10,-4,-6
3,-4,1

#endif
