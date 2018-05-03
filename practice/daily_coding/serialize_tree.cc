#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


struct Tree {
    int data;
    Tree *left;
    Tree *right;
    Tree(int  tmp) {
       data = tmp; 
    }
};




Tree *
deserialize(stringstream &sstr) 
{

    string input;
    sstr >> input;
    // Note: I had missed the size == 0 check initially
    if (input == "#" || input.size() == 0) {
        return NULL;
    }

    Tree *node = new Tree(stoi(input));
    
    node->left = deserialize(sstr);
    node->right = deserialize(sstr);

    return node;
}


void
serialize(Tree *root) 
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    serialize(root->left);
    serialize(root->right);
}


int main() {

    string input = "1 2 3 # # 4 # # 5";
    stringstream sstr(input);
    Tree *root = deserialize(sstr); 
    serialize(root);
    return 0;
}
