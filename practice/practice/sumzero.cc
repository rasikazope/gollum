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
vector < string > sumZero(vector < int > intArr) {

    unordered_map<int, int> map;
    vector <string> res;
    int sum = 0;
    int start = 0;

    for (int i = 0; i < intArr.size(); i++) {
        sum += intArr[i];

        if (map.find(sum) != map.end() || sum == 0) {
            stringstream ss;
            if (sum == 0) {
                start = 0;
                map[sum] = i;
            } else {
                start = map[sum] + 1;
            }
            for (int j = start ; j <= i; j++ ) {
                ss << intArr[j];
                if (j + 1 <= i) {
                    ss << ',';
                }
            }
            
            res.push_back(ss.str());
        } else {
            map[sum] = i;
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

    res = sumZero(_intArr);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}

