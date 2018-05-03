#include <iostream>
#include <string.h>
using namespace std;


void
longest_palindromic_string_util(string orig_string, int start, int end, int &max_start, int &max_end)
{ 
    while(start >= 0 && end < orig_string.length() && orig_string[start] == orig_string[end]) {
        start--;
        end++;
    }
    start++;
    end--;
    if (end - start + 1 > max_end - max_start + 1) {
        max_start = start;
        max_end = end;
    }
}



string
longest_palindromic_string(string orig_string)
{

    int start = 0;
    int end = 0;

    int max_start = 0;
    int max_end = 0;
    
    for (int i = 0; i < orig_string.length(); i++) {
        // Odd
        start = i - 1;
        end = i + 1;

        longest_palindromic_string_util(orig_string, start, end, max_start, max_end);
       
        // Even
        start = i;
        end = i + 1;
        longest_palindromic_string_util(orig_string, start, end, max_start, max_end);
    }
    return orig_string.substr(max_start, max_end - max_start + 1);
}


int main() 
{
    //string mystring_even("qstnittinkk");
    string mystring_even("abcdefg");
    cout << longest_palindromic_string(mystring_even) << endl;
    string mystring_odd("qstnitinkk");
    cout << longest_palindromic_string(mystring_odd) << endl;
    return 1;
}
