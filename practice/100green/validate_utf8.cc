#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;



#if 0
   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
  --------------------+---------------------------------------------
  0000 0000-0000 007F | 0xxxxxxx
  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

#endif


bool
validate_utf(const vector<int> & utf)
{
    int count = 1;

    for (int i = 0; i < utf.size();) {
        // Starts with zero
        if ((utf[i] & 128) == 0) {
            count = 1;
        } else if ((utf[i] & 224) == 192) { // 110X
            count = 2;
        } else if ((utf[i] & 240) == 224) { // 1110X
            count = 3;
        } else if ((utf[i] & 248) == 240) { // 1110X
            count = 3;
        } else {
            return false;
        }


        for (int j = 1; j < count; j++) {
            if ((utf[i+j] & 192) != 128) {
                return false;
            }
        }

        i = i + count; 
    }
    return true;
}



int main() {

    vector <int> utf = {197, 130, 1};
    cout << validate_utf(utf) << endl;
    
    utf = { 128 };
    cout << validate_utf(utf) << endl;

    utf = { 235, 140, 4 };
    cout << validate_utf(utf) << endl;
    return 0;
}
