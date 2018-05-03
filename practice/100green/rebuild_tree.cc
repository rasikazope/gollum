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

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* sibling;
    Node(int v):val(v),left(nullptr), right(nullptr),sibling(nullptr) {}
};



void printInorder(Node* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printLevelorder(Node* root) {
    if(!root) return;
    list <Node *> queue;
    list <int> queue_val;
    cout << endl;
    queue.push_back(root);
    Node *sentinel = new Node(-1);
    Node *prev = NULL;
    queue.push_back(sentinel);
    while (!queue.empty()) {
        root = queue.front();
        queue.pop_front();
        
        if (root->val == -1) {
            if (!queue.empty()) {
                queue.push_back(sentinel);
            
            }
            cout << endl;
        } else {
            if (prev) {
                prev->sibling = root;
            }
            cout << root->val << " ";
            if (root->left)
                queue.push_back(root->left);
            if (root->right)
                queue.push_back(root->right);
        }
        prev = root;
    }
}



/*
 * Complete the function below.
 */
void constrctTree(vector < int > iInOrderArray, vector < int > iPreOrderArray) {
    
    Node *root = constrctTree(iInOrderArray, iPreOrderArray, 0, iPreOrderArray.size() - 1,  0, iInOrderArray.size() -1); 
    printLevelorder(root);

}



int main() {
    
    int _iInOrderArray_size = 0;
    cin >> _iInOrderArray_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _iInOrderArray;
    int _iInOrderArray_item;
    for(int _iInOrderArray_i=0; _iInOrderArray_i<_iInOrderArray_size; _iInOrderArray_i++) {
        cin >> _iInOrderArray_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _iInOrderArray.push_back(_iInOrderArray_item);
    }
    
    
    int _iPreOrderArray_size = 0;
    cin >> _iPreOrderArray_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _iPreOrderArray;
    int _iPreOrderArray_item;
    for(int _iPreOrderArray_i=0; _iPreOrderArray_i<_iPreOrderArray_size; _iPreOrderArray_i++) {
        cin >> _iPreOrderArray_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _iPreOrderArray.push_back(_iPreOrderArray_item);
    }
    
    constrctTree(_iInOrderArray, _iPreOrderArray);
    
    return 0;
}


#if 0
First inorder and then pre order
i/p
7
10
30
40
50
60
70
90
7
50
30
10
40
70
60
90
o/p
50
30 70
10 40 60 90


#endif
