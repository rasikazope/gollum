#include <stdio.h>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

struct interval {
    int start;
    int end;
};


bool
inter_comp(interval i1, interval i2)
{
    if (i1.start < i2.start) {
        return true;
    }
    return false;
}


void merge_intervals(struct interval intervals[], int size)
{
    // Very interesting the pointer addition here
    sort(intervals, intervals + size, inter_comp);
    stack<struct interval> mystack;
    
    for (int i = 0; i < size; i++) {
        if (mystack.empty()) {
            mystack.push(intervals[i]);
        } else {
            struct interval top = mystack.top();
            if (top.end >= intervals[i].start) {
                mystack.pop();
                top.end = intervals[i].end;
                mystack.push(top);
            } else {
                mystack.push(intervals[i]);
            }
        }
    }
    while (!mystack.empty()) {
       interval top = mystack.top();
       cout << top.start << " " << top.end << endl;
       mystack.pop();
    }

}


int main() {
    //struct interval intervals[] =  {{1,3}, {2,4}, {5,7}, {6,8}};
    struct interval intervals[] =  {{2,4}, {1,2}};
    int size = sizeof(intervals)/sizeof(intervals[0]);
    merge_intervals(intervals, size);
    return 0;
}
