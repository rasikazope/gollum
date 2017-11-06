#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int reverse(int num)
{
    long rev_num = 0;
    while (num) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
        
    }
    return (rev_num > INT_MAX || rev_num < INT_MIN) ? 0 : rev_num;

}

int main() {

    cout << reverse(1234567891) << endl;
    cout << "Int "<< sizeof(int) << endl;
    cout << "Long " <<sizeof(long) << endl;
    // Note below returns zero since signed int is around 2B
    cout << reverse(1234567893) << endl;
    return 0;
}
