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


        
int 
validate(string strText, int start, int len) {
    vector <int> alpha(26, 0);
    int char_count = 0;

    for (int i = start; i < len; i++) {
        int index = strText[i] - 'a';
        if (alpha[index] == 0) {
            if (char_count == 2) {
                return 0;
            }
            alpha[index]++;
            char_count++;
        } else {
            alpha[index]++;
        }
        
    }
    return char_count;
}

string longestSub(string strText) {
    
    int len = strText.length();
    int start = 0;
    int maxlen_so_far = 2;
    if (len == 1) {
        return strText;
    }
    int i = 0;
    int j = 1;
    while (j < len && i < len) {
        if (validate(strText, i, j-i+1)) {
            if (maxlen_so_far < j-i+1) {
                maxlen_so_far = j-i+1;
                start = i;
            }
            j++;
        } else {
            i++;
        }
    }

   if (2 == validate(strText, start, maxlen_so_far)) {
        return strText.substr(start, maxlen_so_far);
    } else {
        return ""; 
    }
}




int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strText;
    getline(cin, _strText);

    res = longestSub(_strText);
    cout << res << endl;

    fout.close();
    return 0;
}
// tricky input is
//1.  "ttttt" 2. "tttttllllll"
