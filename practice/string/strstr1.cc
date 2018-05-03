#include <stdio.h>
#include <iostream>

using namespace std;


int 
mystrstr(string haystack, string needle) 
{
    int m = haystack.length();
    int n = needle.length();

    for (int i = 0; i < m - n + 1; ) {
        int j = 0;
        if (haystack[i] != needle[j]) {
            i++;
            continue;
        } else {
            while (haystack[i + j] == needle[j] && i + j < haystack.length() 
                    && j < needle.length()) {
                j++;
            } 
            if (j == needle.length()) {
                return i;
            }
            i++;
        }
    }
    return -1;
}


int main() {

    cout << mystrstr("Rassasika", "ikaz") << endl;
    return 0;
}
