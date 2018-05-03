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

        
void swap(int &even, int &odd)
{
    cout << "even: " << even << " odd: " << odd << endl; 
    int tmp = even;
    even = odd;
    odd = tmp;
}

/*
 *  * Complete the function below.
 *   */
vector < int > groupNumbers(vector < int > intArr) {
    int even = 0;
    int odd = intArr.size() - 1;

    while (even < odd) {
        if (intArr[even] % 2 == 0 || intArr[odd] % 2 == 1) {
            if (intArr[even] % 2 == 0) {
                even++;
            }
            if (intArr[odd] % 2 == 1) {
                odd--;
            }
        } else {
            swap(intArr[even], intArr[odd]);
        }
    }

    return intArr;
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;

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

    res = groupNumbers(_intArr);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}


#if 0
i/p
4
1
2
3
4
o/p
4
2
3
1
#endif
