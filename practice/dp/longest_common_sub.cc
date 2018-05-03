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




/*
 *  * Complete the function below.
 *   */
string getLCS(string strX, string strY) {

    int Xlen = strX.length();
    int Ylen = strY.length();
    //int cache[Xlen+1][Ylen+1]; 
    vector < vector<int> > cache(Xlen+1, vector<int> (Ylen+1, 0) );


    for (int i = 0; i < Xlen+1; i++) {
        for (int j = 0; j < Ylen+1; j++) {
            if (i == 0 || j == 0) {
                cache[i][j] = 0;
                continue;
            }
            if (strX[i-1] == strY[j-1]) {
            //if (strX[i] == strY[j]) {
                cache[i][j] = cache[i-1][j-1] + 1;
            } else {
                cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
            }
        }
    }

    int len = cache[Xlen][Ylen];
    char lcs[len+1];
    lcs[len] = '\0';
    //cout << "length of max common sub " << cache[Xlen][Ylen];
  

    for (int i = 0; i <= Xlen; i++) {
        for (int j = 0; j <= Ylen; j++) {
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }

    int i = Xlen;
    int j = Ylen;
    int index = len;

    // Note we need to check if the value is same as top of left if not then only check if it comes it by 1 to the diagonal;
    while (i > 0 && j > 0) {
        if(strX[i-1] == strY[j-1]) {
            lcs[index-1] = strX[i-1];
            //cout << strX[i-1];
            index--;
            i--;
            j--;
        } else if (cache[i-1][j] > cache[i][j-1]) {
            i--; 
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strX;
    getline(cin, _strX);

    string _strY;
    getline(cin, _strY);

    res = getLCS(_strX, _strY);
    //cout << res << endl;

    fout.close();
    return 0;
}
