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

int mymin(int val1, int val2, int val3)
{
        val1 = std::min(val1, val2);
            return std::min(val1, val3);
}



int levenshteinDistance_helper(string strWord1, string strWord2, int i, int j) {


    if (i == strWord1.length() && j == strWord2.length()) {
        return 0;
    }

    if (i == strWord1.length()) {
        return j;
    }

    if (j == strWord2.length()) {
        return i;
    }

    int val2 = 0;
    int val3 = 0;
    int val1 = 0;


    if (strWord1[i] == strWord2[j]) {
        return levenshteinDistance_helper(strWord1, strWord2, i+1, j+1);
    } else {
        val1 = levenshteinDistance_helper(strWord1, strWord2, i+1, j); //delete
        val2 = levenshteinDistance_helper(strWord1, strWord2, i, j+1); //insert
        val3 = levenshteinDistance_helper(strWord1, strWord2, i+1, j+1); //replace
        return 1 + mymin(val1, val2, val3);
    }   

}

int levenshteinDistance(string strWord1, string strWord2) {
        return levenshteinDistance_helper(strWord1, strWord2, 0, 0);
}
int main() {
        ofstream fout(getenv("OUTPUT_PATH"));
            int res;
                string _strWord1;
                    getline(cin, _strWord1);
                        
                        string _strWord2;
                            getline(cin, _strWord2);
                                
                                res = levenshteinDistance(_strWord1, _strWord2);
                                    fout << res << endl;
                                        
                                        fout.close();
                                            return 0;
}

