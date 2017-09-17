#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


vector<int> getMode(vector<int> &A, vector<vector<int> > &B) {

    vector <int> res;

    for (int m = 0 ; m < B.size() ; m++) {

        int i = B[m][0];
        int j = B[m][1];

        A[i-1] = B[m][1];

        unordered_map <int, int> mymap;
        for (auto itr: A) {
            mymap[itr]++;
        }

        int max = 0;
        int max_val = 0;
        for ( auto itr = mymap.begin(); itr != mymap.end(); ++itr ) {
            if (mymap[itr->first] == max) {
                if (mymap[itr->first] < max_val) {
                    max_val = itr->first; 
                }
            } else if (mymap[itr->first] > max) {
                max = mymap[itr->first];
                max_val = itr->first; 
            }
        }
        res.push_back(max_val);
    }
    
    return res;


}

int main() {

    vector <int> A = {2, 2, 2, 3, 3};
    vector < vector <int> > B =  { {1, 3},
                        {5, 4}, 
                        {2, 4} };

    vector <int> res = getMode(A, B);
    for (auto itr: res) {
        cout << endl << itr << " ";
    }
    cout << endl;
}


/* Answer should be 3 2 3*/
