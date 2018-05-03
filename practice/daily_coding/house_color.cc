#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int
min_cost(vector <vector <int> > input) {
    
    int total_cost = 0;
    int prev_k = INT_MAX;
    int k = INT_MAX;

    for (int i = 0 ; i < input.size(); i++) {
       
        int min_so_far = INT_MAX;
        for (int j = 0; j < input[0].size(); j++) {
                if (prev_k == j) {
                    continue;
                }
                if (input[i][j] < min_so_far) {
                    min_so_far = input[i][j];
                    k = j;
                }
        }
        prev_k = k;
        total_cost += min_so_far;
    }
    return total_cost;

}


int main() {

    vector < vector <int> > input = { {2, 3, 4},
        {5, 6, 3},
        {2, 3, 1}
    };
    cout << min_cost(input) << endl;
    return 0;
}
