#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int 
count_level(const string &str)
{
    string tmp = str;
    tmp.erase(remove(tmp.begin(), tmp.end(), '\t'), tmp.end());
    return str.length() - tmp.length();

}


int 
longest_abs_file_name(const string &str)
{
        istringstream sstr(str);
        vector <string> tokens;
        int longest_len = INT_MIN;
        string token;
        while (getline(sstr, token, '\n')) {
            // cout << token <<  endl;
            tokens.push_back(token);
        }

        stack<int> mystack;

        int cur_len = 0;
        for (auto itr_tok : tokens) {
            int level = count_level(itr_tok);
            if (!mystack.empty() && level <= mystack.size()) {
                cur_len -= mystack.top();
                mystack.pop();
            }
            
            itr_tok.erase(remove(itr_tok.begin(), itr_tok.end(), '\t'), itr_tok.end());
            cout << itr_tok << " ";
            mystack.push(itr_tok.length() + 1);
            cur_len += itr_tok.length() + 1;
            if (string::npos != itr_tok.find('.')) {
                if (longest_len < cur_len) {
                    longest_len = cur_len;
                }
            }
        }

        return longest_len;
}

int main() {

    cout << longest_abs_file_name("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    return 0;
}
