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

void
printlevel(Node *node, int k)
{
    if (!node) {
        return;
    }

    if (k == 1) {
        cout << node->val << " ";
        return;
    }

    k--;  
    printlevel(node->left, k);
    printlevel(node->right, k);

}

/*
 *  * Complete the function below.
 *   */
void
printlevel(Node* node) {

    if (!node) {
        return;
    }

    //Print upto 3 levels.
    int height = 3;
    
    for (int i = 1; i <= height; i++) {
        printlevel(node, i);
        cout << endl;
    }

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    string _str;
    getline(cin, _str);

    Node* root = createTree(_str);
    printlevel(root);

    fout.close();
    return 0;
}


#if 0
i/p
13
10 5 3 # # 7 # # 30 20 # # 50
o/p
10
5 30
3 7 20 50
#endif
