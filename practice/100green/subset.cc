#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector< vector<int> > subsetsWithDup_util(vector<int> &A, int index) {

    static vector < vector<int> > res;
    static vector <int> B(A.size());
    
    if (index == A.size()) {
        
        // Push to this result vector;
        vector <int> subset(0);
        for (int i = 0; i < A.size(); i++) {
            
            if (B[i] == 1) {
                subset.push_back(A[i]);
            
            }
        
        }
        res.push_back(subset);
        return res;
    }
    
    B[index] = 0;
    subsetsWithDup_util(A, index + 1);
    
    B[index] = 1;
    subsetsWithDup_util(A, index + 1);
    
    B[index] = 0;
    return res;
}
    


int main() {

    vector <int> A = {2, 3};
    vector  < vector <int> > res = subsetsWithDup_util(A, 0);
    for (auto itr : res ) {
        for (auto itr_i : itr ) {
                cout << itr_i << " ";
        }
        cout << endl;
    }
        return 0;
}
