    
#include <stdio.h>
#include <iostream>

using namespace std;

void wildcard(string &input, int offset) 
{
    if (offset == input.length()) {
        cout << input << endl;
    }
    if (input[offset] == '?') {
        input[offset] = '0';
        wildcard(input, offset + 1);
        input[offset] = '1';
        wildcard(input, offset + 1);
    } else {
        wildcard(input, offset + 1);
    }

}




int main() {

    wildcard("1?1", 0) << endl;
    return 0;
}
