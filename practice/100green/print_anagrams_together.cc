#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;



vector <string>
print_anagram(vector <string> input)
{

    vector <string> result;
    unordered_map<string, multiset<string> > mymap;
    for (auto itr: input) {
        string s = itr;
        sort(s.begin(), s.end()); 
        mymap[s].insert(itr); 
    }

    for (auto itr: mymap) {
        for (auto vec_itr: itr.second) {
            result.push_back(vec_itr);
        }
    }
    return result;
}



int main() {

    vector<string> input = {"cat", "atc", "rat", "tar"};
    vector<string> result = print_anagram(input);
    for (auto itr : result) {
        cout << itr << endl;
    }

    return 0;
}
