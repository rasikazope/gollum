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
palindromicDecompositionUtil(string strInput, vector< vector<string> > & result, vector<string> & curr_str, int start, int n)
{

    if (start == n) {
        result.push_back(curr_str);
        return;
    }

    for (int i = start; i < n ; i++) {
        if (ispalindrome(strInput, start, i)) {

            curr_str.push_back(strInput.substr(start, i - start + 1));
           
            // Please not the second argument of the substring is the length of the string
            palindromicDecompositionUtil(strInput, result, curr_str, i+1, n);
            
            curr_str.pop_back();
        }
    }
}



/*
 *  * Complete the function below.
 *   */
vector <vector <string> > palindromicDecomposition(string strInput) {
    vector <vector<string> > result;

    vector <string> curr_str;

    palindromicDecompositionUtil(strInput, result, curr_str, 0, strInput.length());

    return result;

}




int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < vector<string> > res;
    string _strInput;
    getline(cin, _strInput);

    res = palindromicDecomposition(_strInput);
#if 0
    for(int res_i=0; res_i < res.size(); res_i++) {
        for(int res_j=0; res_j < res_i.size(); res_j++) {
            cout << res[res_i][] << endl;;
        }
    }
#endif

#if 1
    cout << "Size " << res.size() << endl;
    for (auto itr = res.begin(); itr != res.end(); ++itr) {

        vector <string> i_res = *itr;
        for (auto itr1 = i_res.begin(); itr1 != i_res.end(); ++itr1) {
            cout << *itr1 << " ";
        }
        cout << endl;
    }
#endif

# if 0
    if (ispalindrome("nitin", 1, 3) ) {
        cout << "Yaay: Palin" << endl;
    } else {
        cout << "Nopes: Palin" << endl;
    }
#endif
    fout.close();
    return 0;
}
