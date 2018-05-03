#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

struct interval {
    int start;
    int end;
};



bool
compare_sort(interval i1, interval i2)
{
        return i1.start > i2.start;
}


int
mm(vector<interval> meetings) {

    sort(meetings.begin(), meetings.end(), compare_sort);

    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    for (auto itr : meetings) {
        if (!min_pq.empty() && min_pq.top() <= itr.start) {
            min_pq.pop();
        }
        min_pq.push(itr.end);
    }


    return min_pq.size();

}


int main() {

    vector<interval> meetings =  { {3, 5}, {6, 7} };
    cout << mm (meetings) << endl;
    return 0;
}
