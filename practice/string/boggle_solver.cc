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

    transform(str.begin(), str.end(), str.begin(),::tolower);
    
    for (int i = 0; i < str.length(); i++) {
        if (!root->edge[str[i] - 'a']) {
            Trie *new_node = new Trie(); 
            root->edge[str[i] - 'a'] = new_node;
        } 
        root = root->edge[str[i] - 'a'];
    }

    root->isleaf = true;

}



// return type 2 means it is a prefix
int 
search(string str, Trie *root)
{
    transform(str.begin(), str.end(), str.begin(),::tolower);
    
    for (int i = 0; i < str.length(); i++) {
        
        if (!root->edge[str[i] - 'a']) {
            return 0;
        } else {
            root = root->edge[str[i] - 'a'];
        }
    }
    if (root->isleaf)
    {
        return 1;
    } else {
        return 2;
    }
}



struct cell {
    int x;
    int y;
    string p;
    cell(int _x, int _y, string _p) { x = _x; y = _y; p = _p;} 
};


/*
 *  * Complete the function below.
 *   */
vector < string > findWords(vector < string > dictionaryList, vector < vector < string > > board) {

    vector <string> res;
    Trie *trie_root = new Trie();
    for ( auto itr : dictionaryList) {
        insert(itr, trie_root);
    }


    list<struct cell *> queue;

    for(int _board_i=0; _board_i < 3; _board_i++) {
        for(int _board_j=0; _board_j < 3; _board_j++) {
            //cout << " " << board[_board_i][_board_j];
            struct cell *newcell = new cell(_board_i, _board_j, board[_board_i][_board_j]);  
            queue.push_front(newcell);
        }
    }


    vector <int> op = { 1, 0, -1};
    while (!queue.empty()) {
        struct cell *p_cell = queue.front();
        queue.pop_front();
      
        for (auto i: op) {
            for (auto j : op) {
                int _board_i;
                int _board_j;
                _board_i = p_cell->x + i;
                _board_j = p_cell->y + j;
                if (_board_i < 0 || _board_i >= 3 || _board_j < 0 || _board_j >= 3 || (i == 0 && j == 0)) {
                    continue;
                }
                string neigh_v = board[_board_i][_board_j];
                string new_prefix = p_cell->p + neigh_v; 
                int search_ret = search(new_prefix, trie_root);
                if (search_ret == 2) {
                    // Prefix
                    struct cell *newcell = new cell(_board_i, _board_j, new_prefix);  
                    queue.push_front(newcell);
                } else if (search_ret == 1) {
                    res.push_back(new_prefix); 
                }
            }
        }
    }

    return res;

}



int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;

    int _dictionaryList_size = 0;
    cin >> _dictionaryList_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _dictionaryList;
    string _dictionaryList_item;
    for(int _dictionaryList_i=0; _dictionaryList_i<_dictionaryList_size; _dictionaryList_i++) {
        getline(cin, _dictionaryList_item);
        _dictionaryList.push_back(_dictionaryList_item);
    }


    int _board_rows = 0;
    int _board_cols = 0;
    cin >> _board_rows >> _board_cols;
    vector< vector < string > > _board(_board_rows);
    for(int _board_i=0; _board_i<_board_rows; _board_i++) {
        for(int _board_j=0; _board_j<_board_cols; _board_j++) {
            string _board_tmp;
            cin >> _board_tmp;
            _board[_board_i].push_back(_board_tmp);
        }
    }

    res = findWords(_dictionaryList, _board);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;
    }

    fout.close();
    return 0;
}



#if 0
i/p
4
GEEKS
QUIZ
ANIMAL
FROG
3
3
G
Z
S
I
E
K
U
Q
E
o/p
2
GEEKS
QUIZ


#endif
