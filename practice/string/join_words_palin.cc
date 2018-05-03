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
is_palindrome(string str) 
{
    for (int i = 0, j = str.length() - 1 ; i < str.length(); i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

 
void 
join_palindrome(vector <string> &strvec)
{
    unordered_map<string, int> map;
    for (int i = 0; i < strvec.size(); i++) {
        map[strvec[i]] = i;
    }

    for (int i = 0; i < strvec.size(); i++) {
        string word = strvec[i];
        for (int len = 0; len < word.size(); len++) {
            string str1 = word.substr(0, len);
            string str2 = word.substr(len);
            // Ideally we should do the opposite first lookup and then palindrom check
            if (is_palindrome(str1)) {
                string tmp(str2.rbegin(), str2.rend());
                auto map_itr = map.find(tmp);
                if (map_itr != map.end()) {
                    if (map_itr->second != i) {
                         cout << word << " " << str2 << endl;
                    }
                }

            }
            if (is_palindrome(str2)) {
                string tmp(str1.rbegin(), str1.rend());
                auto map_itr = map.find(tmp);
                if (map_itr != map.end()) {
                    if (map_itr->second != i) {
                        cout << word << " " << str1 << endl;
                    }
                }

            }

        }
    }

}


int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
#if 0
    vector <string> strvec = {"cat", 
            "bat", "tabini", "rab"};    
#endif
#if 1 
    vector <string> strvec = {"cat", 
            "bat", "tab", "rab"};    
#endif

    join_palindrome(strvec);
    
    return 0;
}


//TODO
//
// O (n k2) : k2 because k to find the palindrome
// Create trie for reverse of the words
//Try this using trie
