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
void printSnakeString() {

    string str = "googleworks";
    vector < vector <int> > arr(3, vector<int>(str.length(), 32)) ;

    for (int j = 0; j < str.length();) {
        for (int i = 2; i >= 0; i--) {
            arr[i][j] = str[j]; 
            j++;
        }
        arr[1][j] = str[j];
        j++;
    }

    for (int i = 0 ; i < 3; i ++) {
        for (int j = 0; j < str.length(); j++) {
            cout<< char(arr[i][j]) << " "; 
        }
        cout << endl;
    }
}




int main() {
    printSnakeString();

    return 0;
}

