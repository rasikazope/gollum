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

void printInorder(Node* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}


/*
 *  * Complete the function below.
 *   */
Node* cloneTree(Node* node) {

    Node *newnode = NULL;
    if (node) {
        newnode = new Node(node->val);
        newnode->left = cloneTree(node->left);
        newnode->right = cloneTree(node->right);
    }

    return newnode;

}





int main() {
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    string _str;
    getline(cin, _str);
    Node* root = createTree(_str);
    Node* clone = cloneTree(root);
    printInorder(clone);
    return 0;
}

#if 0
13
10 5 3 # # 7 # # 30 20 # # 50
o/p
3 5 7 10 20 30 50


#endif

