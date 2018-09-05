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




/*
 *  * Complete the function below.
 *   */
void makeChange(int C, vector < int > intDenominations) {
   
    vector <unsigned int> cache(C+1);
    vector <unsigned int> coins_used(C+1);
    cache[0] = 0;
    for (int i = 1; i < cache.size(); i++) {
        cache[i] = INT_MAX;
    }

    for (int i = 0; i < intDenominations.size(); i++) {

        for (int j = 1; j < cache.size(); j++) {
            if (j - intDenominations[i] >= 0) {
                if (1 + cache[ j - intDenominations[i] ] < cache[j]) {
                    coins_used[j] = i;
                }
                cache[j] = min(cache[j], 1 + cache[ j - intDenominations[i] ]);
                //cout << endl << j << " " << cache[j];
            } 
        }
    }

    cout << endl << "Minimum coins needed for change "<< cache[C] << endl;
    int coin_index = 0;
    while (C > 0) {
        if (coin_index) 
            cout << ",";
        coin_index = coins_used[C];
        cout << intDenominations[coin_index];
        C = C - intDenominations[coin_index];
    }
#if 0
    cout << endl;
    for (int i: coins_used)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    for (int i: cache)
    {
        cout << i << " ";
    }
    cout << endl;
#endif
}


int main() {
    int _C;
    cin >> _C;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _intDenominations_size;
    cin >> _intDenominations_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intDenominations;
    int _intDenominations_item;
    for(int _intDenominations_i=0; _intDenominations_i<_intDenominations_size; _intDenominations_i++) {
        cin >> _intDenominations_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intDenominations.push_back(_intDenominations_item);
    }

    makeChange(_C, _intDenominations);

    return 0;
}

#if 0

// Please note: this works for repeated coins too
i/p
4
3
1
2
3
o/p
1,3
2,2
#endif

