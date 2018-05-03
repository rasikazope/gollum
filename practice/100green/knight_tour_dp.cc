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
#if 0
int * 
get_neighbors(int startdigit, int &size)
{
    
}
#endif


/*
 *  * Complete the function below.
 *   */
int numPhoneNumbers(int startdigit, int phonenumberlength) {

    int[][] cache1 = new int[phonenumberlength][10];
    int **cache = new int*[phonenumberlength];

    for (int i = 0; i <= phonenumberlength; i++) {
        cache[i] = new int[10];
    }

    for (int i = 0; i < 10; i++) {
        cache[1][i] = 1;
    }
   
    for (int i = 2; i <= phonenumberlength; i++) {
        for (int j = 0; j < 10; j++) {
            int size = 0;
            //int *arr = get_neighbors(i, j, size);
            for (int k = 0; k < size; k++) 
            {
                cache[i][j] = cache[i-1][k];
            }        
        }
    }
    return cache[phonenumberlength][startdigit]; 

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _startdigit;
    cin >> _startdigit;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    int _phonenumberlength;
    cin >> _phonenumberlength;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = numPhoneNumbers(_startdigit, _phonenumberlength);
    cout << res << endl;

    fout.close();
    return 0;
}

// Sample input
#if 0
i/p:
1
5
o/p
26
i/p
6
10
o/p
2304
#endif
