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
bool hasMatchingParantheses(string strExpression) {
    stack<char> mystack;

    for (int i = 0; i < strExpression.length(); i++) {
        if (strExpression[i] == '(' || strExpression[i] == '[' || strExpression[i] == '{') {
            mystack.push(strExpression[i]);
        } else if (strExpression[i] == ')' || strExpression[i] == ']' || strExpression[i] == '}') {
           if (mystack.empty()) {
               return false;
           }
           char top_char = mystack.top();
           if ((strExpression[i] == ')' && top_char != '(') || (strExpression[i] == ']' && top_char != '[') ||
                   (strExpression[i] == '}' && top_char != '{'))  {
               return false;
           } 
           mystack.pop();
        }
    }

    if (mystack.empty()) {
        return true;
    } else {
        return false;
    }
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    bool res;
    string _strExpression;
    getline(cin, _strExpression);

    res = hasMatchingParantheses(_strExpression);
    cout << res << endl;

    fout.close();
    return 0;
}

