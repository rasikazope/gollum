#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct meeting {
    int start;
    int end;
};


bool
m_sort(meeting m1, meeting m2) {
    return m1.start < m2.start;
}


int 
min_meeting_rooms(vector <meeting> meetings)
{
    if (meetings.empty()) { return 0; }
    int no_of_rooms = 0;
    sort(meetings.begin(), meetings.end(), m_sort);
    priority_queue <int> min_pq;

    for (auto itr : meetings) {
      if (min_pq.empty()) {
          min_pq.push(itr.start);
      } else {
          if (itr.start > min_pq.top()) {
            min_pq.pop();
          }
          min_pq.push(itr.end);
      }

    }
    return min_pq.size();
}


int main() {


    //vector <meeting> meetings = { {30,100}, {20,75}, {0, 150}, {0, 200} }; // Answer 4
    vector <meeting> meetings = { {0,10}, {20,75}, {80, 150}, {200, 400} }; // Answer 4
    cout << min_meeting_rooms(meetings) << endl;
    return 0;
}
