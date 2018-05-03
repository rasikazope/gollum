#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


bool
iso_str(string a, string b)
{
    unordered_map <char, char> mymap;

    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if (mymap.find(a[i]) == mymap.end()) {
            mymap[a[i]] = b[i];
        } else {
            if (mymap[a[i]] != b[i]) {
                return false;
            }
        }

    }
    return true;

}


int main() {

    cout << iso_str("add", "egg") << endl;
    return 0;
}
