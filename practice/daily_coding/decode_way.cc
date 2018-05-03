#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int
decode_ways(string str, int index)
{

    // Important note: If you reach the end of the string then there is one way to decode.
    if (index == str.length()) {
       return 1; 
    }
    if (index > str.length()) {
        return 0;
    }

    int ways = 0;
    ways = decode_ways(str, index + 1);
    if (str[index] == '1' || (str[index] == '2' && str[index+1] < '7')) {
        ways += decode_ways(str, index + 2);
    }
    return ways;
}



int main() {
    cout << decode_ways("111", 0) << endl;
    return 0;
}
