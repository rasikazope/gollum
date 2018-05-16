#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;

void
powerset(vector <int> arr, vector<int> subset, int index)
{
    if (index == arr.size()) {
        // Print it
        for (int i = 0; i < subset.size(); i++) {
            if (subset[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        return;
    }
    subset[index] = 0;
    powerset(arr, subset, index + 1);
    subset[index] = 1;
    powerset(arr, subset, index + 1);
}


int main() {

    vector <int> arr = {1, 2, 3};
    vector <int> subset(arr.size(), 0);

    powerset(arr, subset, 0);
    return 0;
}
