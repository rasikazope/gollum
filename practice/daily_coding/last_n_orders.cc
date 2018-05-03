#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

/*
 * You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:
 *
 * record(order_id): adds the order_id to the log
 * get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
 */

int N = 5;
int endp = 0;
int bucket[5];

using namespace std;


int 
record(int record_id) {
    bucket[endp] = record_id;
    endp++;
    endp = endp % N;
}

int 
get_last(int index)
{
    int i_index = endp;
    while (index) {
        if (i_index == 0) {
            i_index = N;
        }
        i_index--;
        index--;    
    }
    return bucket[i_index];
}

int main() {
    record(11);
    record(12);
    record(13);
    record(14);
    record(15);
    record(16);
    record(17);
    cout << get_last(4) << endl;
    cout << get_last(1) << endl;
    return 0;
}
