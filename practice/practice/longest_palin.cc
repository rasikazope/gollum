#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void
max_palin(string input, int left, int right, int &max_start, int &max_end) 
{

    max_start = 0;
    max_end = 0;
    while (left >= 0 && right < input.size()) {
        if (input[left] == input[right]) {
            left--;
            right++;
         } else {
             break;
         }
    }
    left++;
    right--;
    max_start = left;
    max_end = right;

}


string 
longest_palin(string input)
{
    int max_start = 0, max_end = 0, start = 0, end = 0;
    for (int i = 0; i < input.size(); i++) {
        //Odd

        max_palin(input, i-1, i+1, start, end);
        
        if (end - start + 1 > max_end - max_start + 1) {
            max_end = end;
            max_start = start;
        }
        //Even
        max_palin(input, i, i+1, start, end);

        if (end - start + 1 > max_end - max_start + 1) {
            max_end = end;
            max_start = start;
        }
    }
    return input.substr(max_start, max_end - max_start + 1);
}


int main() {

    cout << longest_palin("nitie") << endl;
    return 0;
}
