#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int 
func(vector<int> arr)
{
    int *cache  = new int[arr.size() + 1];

    memset(cache, sizeof(cache), 0);
    if (arr.size() == 0) {
        return 0;
    }
    cache[0] = 0;
    cache[1] = arr[0];

    for (int index = 1; index < arr.size(); index++) {
        // Important index +1
        cache[index+1] = max(cache[index], cache[index-1] + arr[index]);
    }

    return cache[arr.size()];
}



int main() {
    vector <int> myarr =  {2, 4, 6, 8, 55};
    cout << func(myarr) << endl;
    return 0;
}
