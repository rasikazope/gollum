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
    Node(int v):val(v),left(nullptr), right(nullptr) {}
};


Node* deserialize(istringstream& in) {
    if(in.eof()) return nullptr;

    string val;
    in >> val;

    if(val.empty()) return nullptr;

    if (val == "#")
        return nullptr;

    Node* root = new Node(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

Node* createTree(string data) {
    if(data.empty()) return nullptr;
    istringstream in(data);
    return deserialize(in);
}

stack <Node *> mystack;
Node *root;
/*
 *  * Complete the function below.
 *   */
int next() {
    Node* min_val_node;
    int min_val = -1;

    if (mystack.empty()) {
        return  -1;
    }
    
    min_val_node = mystack.top();
    min_val = min_val_node->val;
    mystack.pop();

    if (min_val_node->right) {
        min_val_node = min_val_node->right;
        mystack.push(min_val_node);
        min_val_node = min_val_node->left;
        while (min_val_node) {
            mystack.push(min_val_node);
            min_val_node = min_val_node->left;
        } 
    }

    return min_val;

}


void init() {
    Node* min_val_node;
    min_val_node = root;
    if (min_val_node) {
        mystack.push(min_val_node);
        min_val_node = min_val_node->left;
        while (min_val_node) {
            mystack.push(min_val_node);
            min_val_node = min_val_node->left;
        } 

    }
}


int main() {

    int _str_size = 0;
    cin >> _str_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _str;
    string _str_item;
    getline(cin, _str_item);

    root = createTree(_str_item);
    init();
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;
    cout << next() << endl;

    return 0;
}

#if 0 
i/p
13
10 5 3 # # 7 # # 30 20 # # 50
o/p 
3
5
7
10
20
30
50
-1
-1

#endif



