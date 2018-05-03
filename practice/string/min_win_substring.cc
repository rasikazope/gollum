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

bool controls(string strText, string strCharacters) 
{
    unordered_map<int, int> mymap;
    for (auto itr : strCharacters) {
        auto itr_map = mymap.find(itr - 'a');
        if (itr_map != mymap.end()) {
            mymap[itr -'a']++;
        } else {
            mymap[itr -'a'] = 1;
        }
    } 
    for (auto itr : strText) {
        auto itr_map = mymap.find(itr - 'a');
        if (itr_map != mymap.end()) {
            if (mymap[itr -'a'] == 1) {
                mymap.erase(itr_map);
            } else {
                mymap[itr -'a']--;
            }
        }
    }
    if (mymap.size()) {
        return false;
    } 
    return true;
}
    
string MinWindow(string strText, string strCharacters) {

    int len = INT_MAX;
    int start = 0;

    int i = 0;
    int j = 0;

    while (j < strText.length() && (i <= j)) {
        int tmp_len = j - i + 1;
        if (controls(strText.substr(i, j - i + 1), strCharacters)) {
            if (tmp_len < len) {
                start = i;
                len = tmp_len;
            }
            i++;

        } else {
            j++;
        }
    }

    if (i) {
        return strText.substr(start, len);
    } else {
        return "";
    }

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strText;
    getline(cin, _strText);

    string _strCharacters;
    getline(cin, _strCharacters);

    res = MinWindow(_strText, _strCharacters);
    cout << res << endl;

    fout.close();
    return 0;
}

