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
simplify_path(string path)
{
	stringstream ss(path);
	string str;
	stack <string> stk;
	while (getline(ss, str, '/')) {
	        if (str == ".." && !stk.empty()) {
	            stk.pop();
	        } else if (str == ".") {
	            continue;
	        } else {
	            stk.push(str);
	        }
	        cout << str << endl;
	}
	stringstream sbul;
	while (!stk.empty()) {
	    sbul << "/";
	    sbul << stk.top();
	    stk.pop();
	}
	return sbul.str();
	
}

int main() {
	
	cout << simplify_path("/a/./b/../../c/") << endl;
    return 0;
}
