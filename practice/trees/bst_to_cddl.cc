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
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    stack<Node *> stack1;     
    stack<Node *> stack2;
    stack1.push(root);
    Node *tmp;
    while (!stack1.empty()) {
        tmp = stack1.top();
        stack1.pop();
        stack2.push(tmp);
        cout << " tmp " << tmp->val << endl;
              if (tmp->right) {
           cout << " pushing tmp right " << tmp->right->val << endl;
           stack1.push(tmp->right);
       }
              if (tmp->left) {
            cout << " pushing tmp left " << tmp->left->val << endl;
            stack1.push(tmp->left);
        }

     
    }

    while (!stack2.empty()) {
        cout << stack2.top()->val << " ";
        stack2.pop();
    }
}

void bst_to_cdll(Node *root, Node **head)
{
    if (root == NULL) {
        return;
    }
    
    bst_to_cdll(root->left, head);
   
    static Node *prev = NULL;
    if (prev) {
        root->left = prev;
        prev->right = root;
    } else {
        *head = root;
    }
    prev = root;

    Node *root_right = root->right;
    if (*head) {
        (*head)->left = root;
        root->right = *head;
    }

    bst_to_cdll(root_right, head);
}


int main() {

    int _str_size = 0;
    cin >> _str_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _str;
    string _str_item;
    getline(cin, _str_item);

    Node* root = createTree(_str_item);
    Node *head;
    bst_to_cdll(root, &head);

    while (head) {
        cout << head->val << " ";
        head = head->right;
    }

    return 0;
}
