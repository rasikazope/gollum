#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int sum_of_digits_square(int num) 
{

	int sum = 0;
	int digit = 0;
	while (num) {
		int digit = num % 10;
		sum = sum + (digit * digit);
		num = num / 10;			
	}
	return sum;
}


bool
is_happy(int num)
{
	if (num == 1) {
		return true;
	}
	if (num/10 == 0) {
		// Only if one digit
		return false;
	} 
	num = sum_of_digits_square(num);
	cout << num << endl;
	return is_happy(num);
}

int main() {

	cout << is_happy(19) << endl;
    return 0;
}
