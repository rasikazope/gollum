#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector <string>
fizzbuzz(int n) 
{
    vector<string> res;

    for (int i = 1; i <= n; i++) {
        string ans;
        if (i % 3 == 0) {
            ans = "fizz";
        } 
        if (i % 5 == 0) {
            ans += "buzz";
        } 
        if (ans.empty()) {
            ans = to_string(i);
        }
        res.push_back(ans);
    }

    return res;
}


int main() {

    vector <string> res = fizzbuzz(15);
    for (auto itr : res) {
        cout << itr << endl;
    }
    return 0;
}
