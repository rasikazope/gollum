#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;



bool
regular_exp_helper(string input, string exp, int i_index, int exp_index)
{
    if (i_index == input.length() && exp_index == exp.length()) {
        return true;
    }
    if (exp[exp_index] == input[i_index] || exp[exp_index] == '.') {
        return regular_exp_helper(input, exp, i_index+1, exp_index+1);
    }
    if (exp[exp_index] == '*') {
        // Don't consume
        bool ret1 = regular_exp_helper(input, exp, i_index, exp_index+1);
        // Consume 
        bool ret2 = regular_exp_helper(input, exp, i_index+1, exp_index+1);
        // Consume and wait to consume more 
        bool ret3 = regular_exp_helper(input, exp, i_index+1, exp_index);
        return (ret1 || ret2 || ret3);
    }
    return false;
}


bool
regular_exp(string input, string exp) 
{
    return regular_exp_helper(input, exp, 0, 0);

}


int main() {

    cout << regular_exp("chat", ".*at") << endl;
    cout << regular_exp("cat", "c.t") << endl;
    cout << regular_exp("ab", "a*b") << endl;
    cout << regular_exp("aab", "a*b") << endl;
    cout << regular_exp("aaab", "a*b") << endl;
    return 0;
}
