#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


string
url_shortening(long int num)
{
    // base 62 encoding
    string url;
    char mymap[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    while (num) {
        url.push_back(mymap[num % 62]);
        num = num / 62;
    }

    reverse(url.begin(), url.end());
    return url;
}


long int 
restore(string short_url) 
{
   long int num = 0; 
   for (int i = 0; i < short_url.length(); i++) {
        if (short_url[i] >= 'a' && short_url[i] <= 'z') {
            num = num * 62 + short_url[i] - 'a';
        } else  if (short_url[i] >= 'A' && short_url[i] <= 'Z') {
            num = num * 62 + short_url[i] - 'A' + 26;
        } else  if (short_url[i] >= '0' && short_url[i] <= '9') {
            num = num * 62 + short_url[i] - '0' + 52;
        }
   }
   
   return num;
}


int main() {

    string short_url = url_shortening(456789822);
    cout << endl << short_url << endl;
    cout << restore(short_url) << endl;
    return 0;
}
