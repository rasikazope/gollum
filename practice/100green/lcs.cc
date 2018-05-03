#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int
lcs(string str1, string str2) 
{
    vector <vector <int> > cache(str1.length() + 1, vector <int> (str2.length() + 1, 0));
    
    int m = str1.length();
    for (int i = 0; i <= m; i++) {
        cache[i][0] = 0;
    }

    int n = str2.length();
    for (int i = 0; i <= n; i++) {
        cache[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i] == str2[j]) {
                cache[i][j] = 1 + cache[i-1][j-1]; 
            } else {
                cache[i][j] = max(cache[i-1][j], cache[i][j-1]); 
            }
        }
    }

    return cache[str1.length()][str2.length()];
}


int main() {

    cout << lcs("ABCEF", "AGBHCDEF") << endl;
    return 0;
}
