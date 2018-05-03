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



bool fsv_helper(Node *node, int &count)
{
    if (node == NULL) {
        return true;
    }
   
    bool left_ret = fsv_helper(node->left, count);
    bool right_ret = fsv_helper(node->right, count);
    if (!left_ret || !right_ret) {
        return false;
    }
    if (node->left && node->left->val != node->val) {
        return false;
    }
    if (node->right && node->right->val != node->val) {
        return false;
    }
    count++;
    cout << "hello " << node->val << endl;
    return true;
}


/*
 *  * Complete the function below.
 *   */
int findSingleValueTrees(Node* node) {

    int count = 0;
    fsv_helper(node, count);

    return count;
}




int main() {

    int _str_size = 0;
    cin >> _str_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _str;
    string _str_item;
    getline(cin, _str_item);

    Node* root = createTree(_str_item);
    cout << findSingleValueTrees(root) << endl;

    return 0;
}
