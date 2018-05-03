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
partion(int intArr[], int low, int high, int pivot)
{

    int left = low;
    int right = high;
    
    while (true) {
        while (intArr[left] < pivot) {
            left++;
        }

        while (intArr[right] > pivot) {
            right--;
        }

        if (left >= right) {
            break;
        }
    
        swap(intArr[left], intArr[right]);
#if 0
        for (int i = 0; i < high ; i++) {
            cout << intArr[i] << " ";
        }
        cout << endl;
#endif
    }
    return left;
    
}




void 
nutsandbolts(int nuts[], int bolts[], int start, int end)
{
    if (start <= end) {

        int pivot_index = partion(nuts, start, end, bolts[end]);        
        partion(bolts, start, end, nuts[pivot_index]);        

        nutsandbolts(nuts, bolts, start, pivot_index - 1);
        nutsandbolts(nuts, bolts, pivot_index + 1, end);
    }
}

int  main() 
{
#if 1
    int nuts[] = { 2, 4, 3, 1};  
    int bolts[] = { 3, 2, 4, 1};
#endif
#if 0
    int nuts[] = { 4, 2, 3, 1};  
    int bolts[] = { 2, 3, 4, 1};
#endif
    int n = sizeof(nuts)/sizeof(nuts[0]); 
    nutsandbolts(nuts, bolts, 0, n-1);
    
    cout << endl << "Nuts : ";
    for (int i = 0; i < n; i++ ) {
        cout << nuts[i] << " ";
    }
    cout << endl <<"Bolts : ";
    for (int i = 0; i < n; i++ ) {
        cout << bolts[i] << " ";
    }
    cout << endl; 
    
    return 0;
}


#if 0

Notes:
When passing start and end of an array always pass from 0..n-1

#endif
