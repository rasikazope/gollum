#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


int 
exp_eval(string exp)
{
	stack<char> op;
	stack<int> num;
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '+' || exp[i] == '*') {
			op.push(exp[i]);		
		} else {

			stringstream sstr;
			while (exp[i] > '0' && exp[i] < '9' && i < exp.length()) {
				sstr << exp[i];
				i++;	
			}
			int val;
			sstr >> val;
			num.push(val);	
		}
		
	}

	while (!op.empty()) {
		cout << op.top();
		op.pop();
		cout << " ";
	}
	cout << endl;
	while (!num.empty()) {
		cout << num.top();
		num.pop();
		cout << " ";
	}
	cout << endl;


}

int main() {

	cout << exp_eval("5+4*33");
    return 0;
}
