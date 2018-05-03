#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

vector<vector<string>> 
groupAnagrams(vector<string>& strs) {
    unordered_map <string, multiset<string> > mymap; 
    
    for (auto itr: strs) {
        string t = itr;
        sort(t.begin(), t.end());
        mymap[t].insert(itr);
    }

    vector < vector<string> > res;
    for (auto itr: mymap) {
        vector <string> v_s(itr.second.begin(), itr.second.end());
        res.push_back(v_s);
    }
    return res;
}

int main() {
    vector <string> mylist = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector <vector <string> > res = groupAnagrams(mylist);
    for (auto itr1: res) {
        for (auto itr: itr1) {
            cout << itr << " ";
        }
        cout << endl;
    }

    return 0;
}
