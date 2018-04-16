#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int
min_jump(vector <int> jump, int start_index)
{
	if (start_index == jump.size() - 1) {
		return 0;
	} else if (start_index >= jump.size()) {
		return INT_MAX;	
	}

	int min_steps = INT_MAX;
	for (int i = 0; i < jump[start_index] ; i++) {
		int tmp_min_steps = min_jump(jump, start_index + i + 1);  
		if (tmp_min_steps < min_steps) {
			min_steps = tmp_min_steps;
		}
	}

	return min_steps + 1;
		
}



int main() {
	vector <int> jump =  {2,1,1,1,4};
	//vector <int> jump =  {2,3,1,1,4};
	cout << min_jump(jump, 0) << endl;	
    return 0;
}
