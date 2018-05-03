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
 * Complete the function below.
 */
string RLE(string strinput) {

        stringstream output;
        
        int i = 0;

        for (int j = 1; j <= strinput.size();) {
            if (strinput[i] == strinput[j]) {
                j++;
            } else {
                if (i != (j - 1) && strinput[j-1] == strinput[i]) {
                    output << j-i << strinput[i];
                    i = j;   
                } else {
                    output << strinput[i];
                    i++;
                    j++;
                }
            }
        }
        return output.str();

}




int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strinput;
    getline(cin, _strinput);
    
    res = RLE(_strinput);
    cout << res << endl;
    
    fout.close();
    return 0;
}

