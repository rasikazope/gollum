#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


void
get_left_right(vector <int> ele, int &left, int &right, int index)
{

    left = 0;
    right = 0;
    int left_index = index - 1;
    
    while(left_index >=0) {
        if (ele[left_index] > left) {
            left = ele[left_index];
        }
        left_index--;
    }
    int right_index = index + 1;
    while(right_index < ele.size()) {
        if (ele[right_index] > right) {
            right = ele[right_index];
        }
        right_index++;
    }

}


int
water_trap(vector<int> ele)
{
    int water_trap = 0;
    int left = 0;
    int right = 0;

    for (int i = 1; i < ele.size() - 1; i++) {
        get_left_right(ele, left, right, i);
        if (left != 0 && right !=0) {
            water_trap += min(left, right) - ele[i]; 
        }
    }

    return water_trap;

}



int main() {

    vector <int> ele = {3, 0, 1, 3, 0, 5};
    cout << water_trap(ele) << endl;
    return 0;
}
