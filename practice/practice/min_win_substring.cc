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





bool
control(string strText, string strCharacters) 
{

    unordered_map<char, int> mymap;
    for (int i = 0; i < strCharacters.length(); i++) {
        auto itr = mymap.find(strCharacters[i]);
        if (itr != mymap.end()) {
            itr->second++;
        } else {
            mymap[strCharacters[i]] = 1;
        }
    }

    for (int i = 0; i < strText.length(); i++) {
        auto itr = mymap.find(strText[i]);
        if (itr != mymap.end()) {
            if (itr->second == 1) {
                mymap.erase(strText[i]);
            } else {
                itr->second--;
            }
        } 
    }
    if (mymap.empty()) {
        return true;
    } else {
        return false;
    }
}



string 
MinWindow(string strText, string strCharacters)
{
    int i = 0; int j = 0;
    int start = 0;
    int len = INT_MAX;

    while (j < strText.length() && i <= j) {
        if (!control(strText.substr(i, j - i + 1), strCharacters)) {
            j++;
        } else {
            if (j - i + 1 < len) {
                start = i;
                len = j - i + 1; 
            }
            i++;
        }
    }

    if (len != INT_MAX) { 
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

