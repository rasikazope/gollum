#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

bool
word_present(vector <string> dict, string sub_str) {
    if (find(dict.begin(), dict.end(), sub_str) != dict.end()) {
        return true;
    }
    return false;
}

void
word_break_helper(vector<string> dict, string input, vector<string> &result, int index, string str_so_far)
{

    if (index == input.size()) {
        result.push_back(str_so_far);
        str_so_far.clear();
        return;
    }

    for (int i = index; i < input.length(); i++) {
        string sub_str =  input.substr(index, i - index + 1);
        if (word_present(dict, sub_str)) {
            str_so_far += " "; 
            str_so_far += sub_str; 
            word_break_helper(dict, input, result, i + 1, str_so_far);
            str_so_far.erase(str_so_far.end() - (i - index + 2), str_so_far.end());
        }
    }
}

void
word_break(vector<string> dict, string input, vector <string> &result)
{
    word_break_helper(dict, input, result, 0, "");
}






int main() {

    vector <string> dict = {"bed", "bath", "bedbath", "beyond", "and"};
    vector <string> result;
    word_break(dict, "bedbathandbeyond", result);

    for (auto itr : result) {
        cout << itr << endl;
    }

    return 0;
}
