#include <stdio.h>
#include <iostream>
using namespace std;



int 
distance(string word, char first, char second)
{

    int i = 0, j = 0;
    int dist = 0;
    int min_dist = INT_MAX;

    for (i = 0; i < word.length(); i++) {
       if (word[i] == first || word[i] == second) {
         break; 
       }
    }

    if (i == word.length()) {
        return -1;
    }

    j = i;
    for (j = 0; j < word.length(); j++) {
        if (word[i] == word[j]) {
            i = j;
        } else if (word[j] == second || word[j] == first) {
            dist = j-i;
            if (dist < min_dist) {
                min_dist = dist;
            }
            i = j;
        }
    }

    if (min_dist == INT_MAX) {
        return -1;
    }
    return min_dist;
}


int main() {

    string word ="rasiiiiika";
    cout << distance(word, 'a', 'k') << endl;

}
