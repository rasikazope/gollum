#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


bool
lss_subseq(vector <string> tags, vector <string> alltags, int start, int end)
{

    unordered_map <string, int> map;
    
    for (auto itr: tags) {
        map[itr] = 1; 
    }
    for (int i = start; i < end; i++) {
        if (map.find(alltags[i]) != map.end() ) {
            map.erase(alltags[i]);
        }
    }
#if 0
    for (auto itr : map) {
        cout << itr.first;
    }
#endif
    if (!map.empty()) {
        return false;
    }
    return true;
}


int main() {

    vector <string> tags = {
        {"cat"},
        {"rat"},
        {"bat"}
    };
    
    vector <string> all_tags = {
        {"cat"},
        {"sat"},
        {"rat"},
        {"bat"},
        {"mat"},
    };
    
    cout << lss_subseq(tags, all_tags, 0, all_tags.size())<< endl;
    return 0;
}
