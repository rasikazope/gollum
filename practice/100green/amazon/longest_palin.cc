#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


bool
is_palin(string str, int &start, int &end) {
    
    int i = start;
    int j = end;
    while (i < str.length() && j >= 0) {
        if (str[i] == str[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

string 
longest_palin(string input)
{

    int max_start = 0;
    int max_end = 0;

    for (int i = 0; i < input.length(); i++) {
        // Odd
        if (ispalin());

        // Even
    }



}



int main() {

    cout << longest_palin("genitinlll");
    return 0;
}
