#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int
subarray(vector <short int> myarr, long target)
{
    unordered_map <int, int> mymap;
    int counter = 0;

    int sum = 0;

    for (int i = 0; i < myarr.size(); i++) {
        sum = sum + myarr[i];
        mymap[sum] = i;

        int diff = sum - target;
       
        if (sum == target) {
            cout << "Found subarray start "<< 0 << " end " << i << endl;

        }
        if (mymap.find(diff) != mymap.end()) {
            cout << "Found subarray start "<< mymap[diff] + 1  << " end " << i << endl;
        }
        
    }
    
    for (auto itr: mymap) {
        cout << endl << itr.first << " " << itr.second;
    }

    return counter;
}


int main() {

    vector <short int> myarr = {1, 2, 3, 4};
    subarray(myarr, 6) ;
    subarray(myarr, 7) ;
    return 0;
}
