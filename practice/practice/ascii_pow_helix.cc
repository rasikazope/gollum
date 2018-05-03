#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {

    int testcases;
    cin >> testcases;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    string mystr;
    
    getline(cin, mystr);
    int M, K;
    stringstream sstr(mystr);
    sstr >> M >> K;
    cout << "M " << M << "K " << K;
    
    return 0;
}
