#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


int 
num_of_ways_steps(int num_steps)
{
    vector <int> cache(num_steps+1, 0);

    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= num_steps; i++) {
        cache[i] = cache[i-1] + cache[i-2];
    }

    return cache[num_steps];

}

int main() {

    cout << num_of_ways_steps(7) << endl;
    return 0;
}
