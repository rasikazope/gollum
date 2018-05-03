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




bool isMatch(string strText, string strPattern, int t, int p) {

    if (strPattern.length() == p && strText.length() == t) {
        return true;
    }
    if (strPattern.length() == p 
            || strText.length() == t) {
        return false;    
    }

    // Three cases:
    //  Either we do not consume t
    //  We consume t and wait to wait more
    //  We consume t and do  not wait to consume more 
    if (strPattern[p + 1] == '*') {
        return isMatch(strText, strPattern, t, p + 2) ||  (strText[t] == strPattern[p]  ? isMatch(strText, strPattern, t + 1, p + 2) : 0) ||
             (strText[t] == strPattern[p]  ? isMatch(strText, strPattern, t + 1, p) : 0);
    }
    if (strPattern[p] == strText[t] || strPattern[p] == '.') {
        return isMatch(strText, strPattern, t + 1, p + 1);
    }


    return false;

}


/*
 *  * Complete the function below.
 *   */
bool isMatch(string strText, string strPattern) {
    return isMatch(strText, strPattern, 0, 0);
}




int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    bool res;
    string _strText;
    getline(cin, _strText);

    string _strPattern;
    getline(cin, _strPattern);

    res = isMatch(_strText, _strPattern);
    cout << res << endl;

    fout.close();
    return 0;
}



#if 0
i/p
aab
c*a*b
o/p
1

#endif
