#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void
print_subset(vector<int> &arr, vector<int> &mask)
{
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] == 1) {
            cout << " " << arr[i] << " ";
        }
    }
    cout << endl;
}

void
all_poss_subset_helper(vector <int> &arr, vector <int> &mask, int index)
{
    if (index == arr.size()) {
        print_subset(arr, mask);
        return;
    }

    mask[index] = 0;
    all_poss_subset_helper(arr, mask, index + 1);
    mask[index] = 1;
    all_poss_subset_helper(arr, mask, index + 1);

}

void 
all_poss_subset(vector <int> & arr)
{
    vector <int> mask(arr.size(), 0);
    all_poss_subset_helper(arr, mask, 0);
}


int main() {

    vector<int> arr = {2, 3, 4, 5};
    all_poss_subset(arr);
    return 0;
}
