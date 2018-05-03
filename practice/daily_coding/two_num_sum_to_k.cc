#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;

int
sum_to_k(vector <int> arr, int k) {

    int count = 0, sum_so_far = 0;
    set<int> myset;
    for (auto itr: arr) {
        sum_so_far += itr;

        // Please note it is sum_so_far - k here
        if (myset.find(sum_so_far -k) != myset.end() || (k - sum_so_far) == 0) {
            count++;
        } 
        myset.insert(sum_so_far);
    }

    return count;

}


int main() {

    vector <int> arr = {3, 7, 18};
    cout << sum_to_k(arr, 25) << endl;
    return 0;
}
