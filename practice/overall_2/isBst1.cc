
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

    
    
    bool
isBST_helper(Node *root, int &prev)
{
    if (root == NULL) {
        return true;
    }

    if (!isBST_helper(root->left, prev))
        return false;

    if (root->val < prev) {
        return false;
    }

    prev = root->val;

    if (isBST_helper(root->right, prev));
    return false;

}


bool isBST(Node *root) {

        int min = -1;
            return isBST_helper(root, min);

}




int main() {
        
        int _str_size = 0;
            cin >> _str_size;
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
                    vector<string> _str;
                        string _str_item;
                            getline(cin, _str_item);
                                
                                Node* root = createTree(_str_item);
                                    cout << isBST(root) << endl;
                                        
                                        return 0;
    }
