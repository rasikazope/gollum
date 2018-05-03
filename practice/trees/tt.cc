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



struct Tree {
    int val;
    Tree *left;
    Tree *right;
    Tree(int val_u) {
        val = val_u;
        left = NULL;
        right = NULL;
    }
};




Tree *insert_in_bst(Tree *root, int val_u)
{
    if (root == NULL) {
        Tree *nn = new Tree(val_u);
        return nn;
    } else {
        //cout << " Rasika " << root->val << " " <<  val_u << endl ;
    }
     if (root->val < val_u) {
         root->left = insert_in_bst(root->left, val_u);
     } else {
         root->right = insert_in_bst(root->right, val_u);
     }
     return root;
}


void createBalancedBST_helper(vector < int > iArray, int start, int end, Tree **root_pp) {

    Tree *root = *root_pp;
    if (start >= end) {
        return;
    }
    
    cout << "start " << start << " end " << end << endl;
    int midpoint = start + end / 2;
    cout << "midpoint " << midpoint << endl;
    root = insert_in_bst(root, iArray[midpoint]);

    createBalancedBST_helper(iArray, 0 , midpoint - 1, &root);
    createBalancedBST_helper(iArray, midpoint + 1, iArray.size() - 1, &root);

}

/*
 *  * Complete the function below.
 *   */
void createBalancedBST(vector < int > iArray) { 
    Tree *root = NULL;
    createBalancedBST_helper(iArray, 0, iArray.size() - 1, &root);
}




int main() {

    int _iArray_size = 0;
    cin >> _iArray_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _iArray;
    int _iArray_item;
    for(int _iArray_i=0; _iArray_i<_iArray_size; _iArray_i++) {
        cin >> _iArray_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _iArray.push_back(_iArray_item);
    }

    createBalancedBST(_iArray);

    return 0;
}


