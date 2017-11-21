#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


void
zigzag(vector<int>& v1, vector<int>& v2)
{
   vector<int>::iterator s[2];
   vector<int>::iterator e[2];
   s[0] = v1.begin();
   s[1] = v2.begin();

   e[0] = v1.end();
   e[1] = v2.end();

   int p = 0;

   while (1) {
        if (s[0] == e[0] && s[1] == e[1]) {
            break;
        }
        if (s[p] != e[p]) {
            cout << *s[p] << " ";
            *s[p]++;
        } 
        p = (p + 1) % 2;
   }
}


int main() {

    vector <int> v1 = { 1, 3, 5, 7 , 11 };
    vector <int> v2 = { 2, 4, 6, 8, 9, 10};
    zigzag(v1, v2);
    return 0;
}
