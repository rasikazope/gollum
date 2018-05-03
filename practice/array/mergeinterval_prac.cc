#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct interval {
    int start;
    int end;
};

void
merge_interval(interval myint[], int size)
{
    stack<interval> st;
    st.push(myint[0]);
    for (int i = 1; i < size; i++) {
        if (myint[i].start <= st.top().end) {
            interval tmp = st.top();
            tmp.end = myint[i].end;
            st.pop();
            st.push(tmp);
        } else {
            st.push(myint[i]);
        }
    }
    while(!st.empty()) {
        cout << st.top().start << " " << st.top().end << endl;
        st.pop();
    }
}


int main() {
    interval myint[3] =  {{2, 7}, {6, 8}, {7, 9}};
    merge_interval(myint, sizeof(myint)/sizeof(myint[0]));
    return 0;
}
