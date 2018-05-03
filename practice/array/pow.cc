#include <stdio.h>
#include <iostream>

using namespace std;

int 
pow(int base, int exp) 
{
    int result = 1;
    while (exp) {
        if (exp & 1) {
            result = result * base;
        }
        exp = exp >> 1;
        base = base * base;
    }
    
    return result;

}


int main()
{

    cout << pow(2, 5) << endl;
    return 0;
}
