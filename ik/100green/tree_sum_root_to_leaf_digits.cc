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

int
sum_to_root(Node *root, int cur_sum)
{
    static int sum;
    if (!root) {
        return sum;
    }
    cur_sum = root->val + 10 * cur_sum;

    if (!root->left && !root->right) {
        sum = sum + cur_sum;
        return sum;
    }

    if (root->left) {
        sum_to_root(root->left, cur_sum);
    }

    if (root->right) {
        sum_to_root(root->right, cur_sum);
    }

    return sum;


}


int 
sum_to_root(Node *root) 
{
    return sum_to_root(root, 0);

}



int main() {

    int _str_size = 0;
    cin >> _str_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _str;
    string _str_item;
    getline(cin, _str_item);

    Node *root = createTree(_str_item);
    cout << sum_to_root(root) << endl;
    return 0;
}

#if 0 
i/p
9
1 2 4 # # # 3 # #
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



