#include <stdio.h>
#include <iostream>

using namespace std;


void pp_util(int n, int oc, int cc, int index) 
{
    static char str[50];
    if (cc == n) {
        cout << str << endl;
        return;
    }

    if (oc < n) {
        str[index] = '(';
        pp_util(n, oc + 1, cc, index + 1);
    }

    if (cc < oc) {
        str[index] = ')';
        pp_util(n, oc, cc + 1, index + 1);

    }
}

void pp(int n) 
{
    pp_util(n, 0, 0, 0);
}


int main() {
    pp(3);
    return 0;
}
