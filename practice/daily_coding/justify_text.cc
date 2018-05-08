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
justify_text(string mystr, vector <string> &result, int k)
{
    stringstream sstr(mystr);
    int no_of_words;

    string tmp;
    vector <string> input;
    while (sstr >> tmp) {
        no_of_words++;
        input.push_back(tmp);
    }

    cout << no_of_words << endl;

    vector < vector <int> > cache(k, vector <int> (k, 0) );

    for (int i = 0; i < no_of_words; i++) {
        for (int j = i; j < no_of_words; j++) {
            int len = 0;
            for (int q = i; q <= j; q++) {
                len += input[q].length();
            }
            int spaces = k - (j - i + len);
            if (j - i + len <= k) {
                cache[i][j] = spaces * spaces;
            } else {
                cache[i][j] = INT_MAX;
            }
        }
    }


    for (int i = 0; i < no_of_words; i++) {
        for (int j = 0; j < no_of_words; j++) {
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }

    vector <int> cache_cost(no_of_words);
    vector <int> cache_index(no_of_words);

    // Cache index contains starting from that index to the value 
    // at cache_index[index] but not including cache[index]

    for (int i = no_of_words - 1; i >=0; i--) {
        if (cache[i][no_of_words - 1] != INT_MAX) {
            cache_cost[i] = cache[i][no_of_words - 1];
            cache_index[i] = no_of_words;
        } else {
            // We need to break the string but where ?
            int min_break = INT_MAX; 
            int min_break_index = 0;
           for (int j = i; j < no_of_words; j++) {
               if (cache[i][j] != INT_MAX) {
                   if (cache[i][j] + cache_cost[j+1] < min_break) {
                        min_break = cache[i][j] + cache_cost[j+1];
                        min_break_index = j; 
                   }
               }
           }
           cache_cost[i] = min_break;
           cache_index[i] = min_break_index + 1;
        }
    }
    for (int i = 0; i < no_of_words; i++) {
        cout << cache_cost[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < no_of_words; i++) {
        cout << cache_index[i] << " ";
    }

    cout << endl;


    int val_at_index = cache_index[0];
    int index = 0;
    string str;
    do  {
        str = "";
        for (int i = index; i < val_at_index; i++) {
            str += input[i] + " ";
        }
        result.push_back(str);
        index = val_at_index;
        val_at_index = cache_index[index];

    } while (index < cache_index.size());
    return cache_cost[0];
}

int main() {
    string mystr = "Rasika Zop likes to code";
    vector <string> result;
    cout << justify_text(mystr, result, 10) << endl;
    
    for (auto itr: result) {
        cout << itr << endl;
    }
    return 0;
}
