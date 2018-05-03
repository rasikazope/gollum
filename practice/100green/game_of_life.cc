#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
// TODO
// remove 3



void
gameoflife(vector < vector<int> > &input) 
{

    int m = input.size();
    int n = input[0].size();

    int neigh[] = { -1, 0, 1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           
            int count = 0;
            for (auto i_itr: neigh) {
                for (auto j_itr: neigh) {
                    if (i_itr == 0 && j_itr == 0) {
                        continue;
                    }
                    // Make it round
                    int i_n = (i + i_itr) % m;
                    if (i_n < 0) {
                        i_n = m - 1;
                    }
                    
                    int j_n = (j + j_itr) % n;
                    if (j_n < 0) {
                        i_n = n - 1;
                    }

                    if (input[i_n][j_n] & 1) {
                        count++;
                    }
                }
                if (count == 3) {
                    input[i][j] = input[i][j] | 2;
                } 
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            input[i][j] = input[i][j] >> 1;
        }
    }

}


int main() {

    vector < vector <int> > input = {{ 0, 0, 0, 0, 1},
                                     { 0, 0, 1, 0, 0},
                                     { 0, 0, 0, 1, 0},
                                     { 0, 0, 1, 0, 1},
                                     { 0, 0, 0, 1, 0}};

    gameoflife(input);

    for (auto o_itr : input) {
        for (auto i_itr : o_itr) {
            cout << i_itr << " ";
        }
        cout << endl;
    }


    return 0;
}
