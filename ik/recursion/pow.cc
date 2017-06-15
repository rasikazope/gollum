
#include <stdio.h>
#include <iostream>

using namespace std;
float pow(float base, int power) 
{
    float result = 1;
    bool process_result = false;

    if (power < -1) {
        process_result = true;
    }
    
    power = abs(power);

    while (power) {
        if (power & 1) {
            result = result * base;
        }
        power = power >> 1;
        base *= base;
    }
    if (process_result) {
        result = 1 / result;
    }
    return result;
}


int main() {

    cout << pow(4.5, 0) << endl;
    return 0;
}
