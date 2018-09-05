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
#include <string>

using namespace std;

bool
find_in_str_dict(string my_substr, vector < string > strDict) {

    if (find(strDict.begin(), strDict.end(), my_substr) != strDict.end()) { 
        return true;
    } else {
        return false;
    }
}

vector <string > wordBreak_help(string strWord, int start, string cur_str, vector < string > strDict) {

    static vector <string> res;
    if (start == strWord.length()) {
       res.push_back(cur_str);
       cur_str.clear();
       return res;
    }

    for (int i = start; i < strWord.length(); i++) {
        string my_substr = strWord.substr(start, i-start+1);
        
        if (find_in_str_dict(my_substr, strDict)) {
            cur_str += my_substr;
            cur_str += " ";
            wordBreak_help(strWord, i+1, cur_str, strDict);
            cur_str.erase (cur_str.end() - my_substr.length() - 1, cur_str.end());  
        }
    }
    
    return res;

}

/*
 *  * Complete the function below.
 *   */
vector < string > wordBreak(string strWord, vector < string > strDict) {

    string cur_res;
    return wordBreak_help(strWord, 0, cur_res, strDict);

}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;
    string _strWord;
    getline(cin, _strWord);


    int _strDict_size = 0;
    cin >> _strDict_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _strDict;
    string _strDict_item;
    for(int _strDict_i=0; _strDict_i<_strDict_size; _strDict_i++) {
        getline(cin, _strDict_item);
        _strDict.push_back(_strDict_item);
    }

    res = wordBreak(_strWord, _strDict);

    cout << endl << endl;
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}

#if 0 
i/p
ilikeicecreammango
10
a
e
i
like
ice
cream
icecream
man
go
mango

o/p
i like ice cream man go
i like ice cream mango
i like icecream man go
i like icecream mango


#endif
