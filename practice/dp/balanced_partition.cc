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


bool
bp(vector <int> arr, int n, int sum)
{
    if (sum == 0) {
        return true;
    } else if (n == 0) {
        return false;
    } else if (arr[n] > sum) {
        bp(arr, n-1, sum);
    } else {
        return (bp(arr, n-1, sum) || bp(arr, n-1, sum - arr[n]));
    }
}


/*
 *  * Complete the function below.
 *   */
vector < int > balancedPartition(vector < int > arr) {


    vector <int> res;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 == 1) {
        cout << "Partition not possible" << endl;
        return res;
    } else {
        cout << bp(arr, arr.size() - 1, sum/2);
    }
    return res;
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;

    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _arr;
    int _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        cin >> _arr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arr.push_back(_arr_item);
    }

    res = balancedPartition(_arr);
    for(int res_i=0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}

