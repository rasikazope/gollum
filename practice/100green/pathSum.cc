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

/*
 *  * Complete the function below.
 *   */
bool pathSum(Node *root, int sum, int index) {
    static int path[10];
    if (!root) {
        return false;
    }
    path[index] = root->val;
    index++;

    if (root->left == NULL && root->right == NULL) {
        int agg = accumulate(path, path + index, 0);
        if (agg == sum) {
            return true;
        } else {
            return false;
        }
    }
    
    int ret1 = pathSum(root->left, sum, index);
    int ret2 = pathSum(root->right, sum, index);
    return ret1 || ret2;
}

bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}



int main() {

    int _str_size = 0;
    cin >> _str_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _str;
    string _str_item;
    getline(cin, _str_item);

    Node* root = createTree(_str_item);
    if (root) {
        cout << pathSum(root, 12, 0) << endl;
    }
    return 0;
}

#if 0 
i/p
13
10 5 3 # # 7 # # 5 7 # # 3
o/p 
1

i/p
13
1 2 4 # # 5 # # 3 6 # # 8
o/p
0


#endif


