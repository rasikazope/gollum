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

vector <string > wordBreak(string strWord, vector < string > strDict) {

    map<int, vector<string> > cache;
    int start;
    string cur_str;

    vector <string> res;
    
    cache[strWord.length()] = res; 

    for (int start = strWord.length() - 1; start >=0; start--) {
        for (int i = start; i < strWord.length(); i++) {
            string my_substr = strWord.substr(start, i-start+1);

            if (find_in_str_dict(my_substr, strDict)) {
                vector <string> v_string;
                cur_str += my_substr;
                cur_str += " ";
                auto itr_cache_i_plus_one = cache.find(i+1);
                if (itr_cache_i_plus_one != cache.end()) {
                    auto itr_cache_start = cache.find(start);
                    if (itr_cache_start != cache.end()) {
                        v_string = itr_cache_start->second;
                    }
                    if (itr_cache_i_plus_one->second.empty()) {

                        string s_tmp = my_substr;
                        v_string.push_back(s_tmp);
                    }
                    for (auto i_v_s = itr_cache_i_plus_one->second.begin();
                            i_v_s != itr_cache_i_plus_one->second.end();
                            ++i_v_s) {
                        string s_tmp = my_substr + " " + *i_v_s;
                        v_string.push_back(s_tmp);
                    }
                    cache[start] = v_string;
                } else {
                    cur_str.erase (cur_str.end() - my_substr.length() - 1, cur_str.end());  
                }
            }
        }
    }

    return cache[0];

}
#if 0
/*
 *  * Complete the function below.
 *   */
vector < string > wordBreak(string strWord, vector < string > strDict) {

    string cur_res;
    return wordBreak_help(strWord, 0, cur_res, strDict);

}

#endif
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

    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}

#if 0 
i/p
interviewkickstart
12
a
e
i
int
inter
interview
kick
kicker
kickstart
star
start
view

o/p
inter view kick start
interview kickstart
inter view kickstart
interview kick start


#endif
