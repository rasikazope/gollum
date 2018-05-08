#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


string 
encode(string input) {
    if (input.empty()) {
        return "";
    }
    int anchor = 0;
    int trav = 1;
   
    stringstream output;
    while (trav < input.length()) {
        int ctr = 1;
        while (input[anchor] == input[trav]) {
            ctr++;
            trav++;
        }
        output << ctr << input[anchor];
        anchor = trav;
        trav = anchor+1;
    }
    return output.str();
}


string
decode(string input) {

    stringstream output;
    for (int i = 0; i < input.length();) {
        stringstream len;
        while(isdigit(input[i])) {
             len << input[i];
             i++;
        }
        for (int j = 0; j < stoi(len.str()); j++) {
            output << input[i];
        }
        i = i + 1;
    }

    return output.str();
}

int main() {

    cout << encode("AAAABBBCCDAA")<< endl;
    cout << decode("4A3B2C1D2A")<< endl;
    cout << decode("12A3B")<< endl;
    return 0;
}
