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



int
find_min(int ret1, int ret2, int ret3)
{
    return min(min(ret1, ret2), ret3);
}

int
edit_dist(string strWord1, string strWord2, int m, int n)
{

    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    if (strWord1[m - 1] == strWord2[n - 1]) {
        return edit_dist(strWord1, strWord2, m-1, n-1);
    }

    int ret1 = edit_dist(strWord1, strWord2, m-1, n-1); // Replace
    int ret2 = edit_dist(strWord1, strWord2, m, n-1); // Delete
    int ret3 = edit_dist(strWord1, strWord2, m-1, n); // Insert

    return 1 + find_min(ret1, ret2, ret3);
}

/*
 *  * Complete the function below.
 *   */
int levenshteinDistance(string strWord1, string strWord2) {
    return edit_dist(strWord1, strWord2, strWord1.length(), strWord2.length()); 
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _strWord1;
    getline(cin, _strWord1);

    string _strWord2;
    getline(cin, _strWord2);

    res = levenshteinDistance(_strWord1, _strWord2);
    cout << res << endl;

    fout.close();
    return 0;
}

#if 0
input:
kitten
sitting
output:
3
#endif
