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

bool ispalindrome(string str, int start, int end)
{
    if (start == end) {
        return true;
    }
    while (start < end) {
        if (str[start] == str[end]) {
            start++;
            end--;
        } else {
            return false;
        }
    }

    return true;
}



void
palindromicDecompositionUtil(string strInput, vector<string> & result, string &curr_str, int start, int n)
{

    if (start == n) {
        string tmp_str(curr_str);
        tmp_str.pop_back();
        result.push_back(tmp_str);
        return;
    }

    for (int i = start ; i < n ; i++) {
        if (ispalindrome(strInput, start, i)) {
            string sub_str = strInput.substr(start, i - start + 1);
            curr_str += sub_str; 
            curr_str += "|";
            palindromicDecompositionUtil(strInput, result, curr_str, i+1, strInput.length());
            // -1 for "|"
            curr_str.erase (curr_str.end() - sub_str.length() - 1, curr_str.end());  
        }
    }

}



/*
 *  * Complete the function below.
 *   */
vector <string> palindromicDecomposition(string strInput) {
    vector <string> result;
    string curr_str;

    palindromicDecompositionUtil(strInput, result, curr_str, 0, strInput.length());

    return result;

}




int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector<string> res;
    string _strInput;
    getline(cin, _strInput);

    res = palindromicDecomposition(_strInput);
    for (auto itr : res) {
        cout << itr << endl;
    }
    fout.close();
    return 0;
}
