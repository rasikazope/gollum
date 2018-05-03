#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int maxProductFromCutPieces(int ropelength) {
    static int max_so_far = 1;
   
    if (ropelength == 0) {
        return 1;
    }
    for (int i = 0; i < ropelength; i++) {
        int product = (i + 1) * maxProductFromCutPieces(ropelength - (i + 1) );

        cout << i << ": roplength : " << ropelength << ": "<< max_so_far  << " " << endl;
        if (product > max_so_far) {
            max_so_far = product;
        }
    }

    return max_so_far;


}





int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _ropelength;
    cin >> _ropelength;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = maxProductFromCutPieces(_ropelength);
    cout << res << endl;

    fout.close();
    return 0;
}

