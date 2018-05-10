#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


int
edit_distance(string str1, string str2) 
{
    int len1 = str1.length();
    int len2 = str2.length();

    vector < vector <int>  > cache(len1+1, vector <int> (len2+1, 0));

    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (i == 0) {
                cache[i][j] = j;
                continue;
            }
            if (j == 0) {
                cache[i][j] = i;
                continue;
            }
            // IMP: Please note when you are accessing from input it should be -1 
            if (str1[i-1] == str2[j-1]) {
                cache[i][j] = cache[i-1][j-1];
            } else {
                cache[i][j] = 1 + min(min(cache[i-1][j], cache[i][j-1]), cache[i-1][j-1]);
            }
        }
    }
#if 0
    for (auto &inner: cache) {
        for (auto &item: inner) {
            cout << item <<  " ";
        }
        cout << endl;
    }
#endif
    return cache[len1][len2];
}

int main() {

    cout << edit_distance("kitten", "sitting") << endl;
    cout << edit_distance("", "sitting")<< endl;
    cout << edit_distance("sitting", "sitting")<< endl; 
    cout << edit_distance("qit", "sitting")<< endl; 
    cout << edit_distance("qit", "sit")<< endl;
    return 0;
}
