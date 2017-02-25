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
int numWaysToClimb(vector < int > numSteps, int numStairs) {
    
    vector <int> cache(numStairs, 0);

    for (int i = 0; i < numStairs; i++) {
        for (auto itr : numSteps) {
                if (i+1 == itr) {
                    cache[i] += 1;
                }

                if (itr <= i) {
                    cache[i] += cache[i-itr];
                }
        }
    }

#if 0
    cout << "cache " << endl;
    for (auto itr : cache) {
        cout << itr << endl;

    }
    cout << "cache  done " << endl;
#endif
    return cache[numStairs - 1];

}





int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _numSteps_size = 0;
    cin >> _numSteps_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _numSteps;
    int _numSteps_item;
    for(int _numSteps_i=0; _numSteps_i<_numSteps_size; _numSteps_i++) {
        cin >> _numSteps_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _numSteps.push_back(_numSteps_item);
    }

    int _numStairs;
    cin >> _numStairs;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = numWaysToClimb(_numSteps, _numStairs);
    cout << res << endl;

    fout.close();
    return 0;
}

#if 0
input:
2
2
3
9
output:
5
#endif
