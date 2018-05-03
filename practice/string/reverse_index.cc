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
    vector <int> trie_index;
    Trie() {
        isleaf = false;
        for (int i = 0; i < 26; i++) {
            edge[i] = NULL;
        }
    }
};


void
insert(string str, Trie *root, int index) 
{
    transform(str.begin(), str.end(), str.begin(),::tolower);
    for (int i = 0; i < str.length(); i++) {
        if (!root->edge[str[i] - 'a']) {
            Trie *new_node = new Trie(); 
            root->edge[str[i] - 'a'] = new_node;
        } 
        root = root->edge[str[i] - 'a'];
    }

    root->trie_index.push_back(index);
    root->isleaf = true;

}

bool 
search(string str, Trie *root)
{
    transform(str.begin(), str.end(), str.begin(),::tolower);
    for (int i = 0; i < str.length(); i++) {
        
        if (!root->edge[str[i] - 'a']) {
            return false;
        } else {
            root = root->edge[str[i] - 'a'];
        }
    }
    if (root->isleaf)
    {
        cout << endl << "Found indices are: " << endl;
        cout << endl;
        for (auto itr : root->trie_index) {
            cout << itr << " ";
        }
        cout << endl;
        return true;
    } else {
        cout << endl << "It is a prefix " << endl;
        return false;
    }
}


int main()
{

    
    Trie *trie_root = new Trie();
    ifstream readfile;
    ofstream writefile;
    string filename = "myfile.txt";
    readfile.open( filename.c_str() );
    
    if( readfile )
    {
        string word;
        int index = 1;
        while (readfile >> word) {
            cout << word << " " ;
            insert(word, trie_root, index);
            index++;
        }
        //I can read something from the file
        readfile.close();
    }
    cout << endl;
    search("anymore", trie_root);
    return 0;
}
