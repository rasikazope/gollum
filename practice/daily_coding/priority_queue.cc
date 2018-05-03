#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {

    priority_queue <int> max_pq;
    priority_queue < int, vector<int>, greater<int> > min_pq;
    max_pq.push(20);
    max_pq.push(50);
    max_pq.push(30);

    min_pq.push(20);
    min_pq.push(50);
    min_pq.push(30);
    while (!max_pq.empty()) {
        cout << max_pq.top() <<  endl;
        max_pq.pop();
    }
    while (!min_pq.empty()) {
        cout << min_pq.top() <<  endl;
        min_pq.pop();
    }
    return 0;
}
