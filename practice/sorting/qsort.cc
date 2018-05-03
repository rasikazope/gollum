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

        
void swap(int &even, int &odd)
{
    int tmp = even;
    even = odd;
    odd = tmp;
}

int 
partion(vector <int> &intArr, int low, int high)
{

    int left = low + 1;
    int right = high;
    int pivot = intArr[low];
    int pivot_index = low;
    
    while (left <= right) {
        if (intArr[left] < pivot) {
            swap(intArr[left], intArr[pivot_index]);
            left++;
            pivot_index++;
        } else {
            swap(intArr[left], intArr[right]);
            right--;
        }

    }
    return pivot_index;
}

/*
 *  * Complete the function below.
 *   */
void quicksort(vector < int > &intArr, int low, int high) {

    if (low < high) {
        int pivot_index = partion(intArr, low, high);
        quicksort(intArr, low, pivot_index - 1);
        quicksort(intArr, pivot_index + 1, high);
    }
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;

    int _intArr_size = 0;
    cin >> _intArr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intArr;
    int _intArr_item;
        for(int _intArr_i=0; _intArr_i<_intArr_size; _intArr_i++) {
        cin >> _intArr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intArr.push_back(_intArr_item);
    }

    quicksort(_intArr, 0, _intArr_size - 1);
    for (auto i : _intArr) {
        cout << i << " " << endl;
    }
    fout.close();
    return 0;
}


