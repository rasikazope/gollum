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

struct Trie {
    struct Trie *edge[26];
    bool isleaf;    
    Trie() {
        isleaf = false;
        for (int i = 0; i < 26; i++) {
            edge[i] = NULL;
        }
    }
};



void 
insert(string str, Trie *root) 
{
    for (int i = 0; i < str.length(); i++) {
        if (!root->edge[str[i] - 'a']) {
            Trie *new_node = new Trie(); 
            root->edge[str[i] - 'a'] = new_node;
        } 
        root = root->edge[str[i] - 'a'];
    }

    root->isleaf = true;

}

bool 
search(string str, Trie *root)
{
    for (int i = 0; i < str.length(); i++) {
        
        if (!root->edge[str[i] - 'a']) {
            return false;
        } else {
            root = root->edge[str[i] - 'a'];
        }
    }
    if (root->isleaf)
    {
        return true;
    } else {
        cout << endl << "It is a prefix " << endl;
        return false;
    }
}


int main()
{
    vector <string> strlist = { "cat", "catnap", "hat" };
    Trie *trie_root = new Trie();
    for ( auto itr  :  strlist) {
        insert(itr, trie_root);
    }
   
    cout << search("catnap", trie_root) << endl;
    return 0;
}
