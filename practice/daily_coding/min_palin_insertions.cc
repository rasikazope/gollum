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
min_palin_insertions(string input, int l, int r)
{
    if (l > r) {
        return INT_MAX;
    }
    if (l == r) {
        return 0;
    } 
    if (l == r-1) {
        return input[l] == input[r] ? 0: 1;
    }
    if (input[l] == input[r]) {
        return min_palin_insertions(input, l+1, r-1);
    }
    return 1 + min(min_palin_insertions(input, l+1, r), min_palin_insertions(input, l, r-1));
}



int main() {

    //string input = "raceecar"; 
    string input = "raar"; 
    cout << min_palin_insertions(input, 0, input.size()-1) << endl;    
    string input1 = "radar"; 
    cout << min_palin_insertions(input1, 0, input1.size()-1) << endl;    
    string input2 = "radexar"; 
    cout << min_palin_insertions(input2, 0, input2.size()-1) << endl;    
    string input3 = "abcde"; 
    cout << min_palin_insertions(input3, 0, input3.size()-1) << endl;    
    return 0;
}
