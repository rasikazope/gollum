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
swap(vector <char> &arr, int i, int j)
{

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void
sort_rgb(vector <char> &arr )
{
    int r_itr = 0;
    int b_itr = arr.size() - 1;

    int i = 0;
    while (i <= b_itr) {
        if (arr[i] == 'R') {
            swap(arr, r_itr, i);
            r_itr++;
            // Very interesting
            // Only in this case we need to increment i too
            i++;
        } else if (arr[i] == 'B') {
            swap(arr, b_itr, i);
            b_itr--;
        } else {
            i++;
        }
    }

}


int main() {

    vector <char> arr = {'R', 'G', 'B', 'R', 'G', 'B'};
    sort_rgb(arr);
    for (auto itr: arr) {
        cout << itr << " ";
    }
    return 0;
}
