#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


void
count_island_helper(vector < vector <int> > map, vector < vector <int> > &visited, int i, int j) 
{
    if (!visited[i][j]) {
        return;
    }
    
    visited[i][j] = 1;
    
    

}


int 
count_island(vector < vector <int> >map)
{
    int count = 0;
    vector < vector <int> > visited(map.size(), vector <int> (map[0].size(), 0));
    
    for (int i = 0; i < map.size(); i ++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (!visited[i][j]) {
                count_island_helper(map, visited, i, j);
                count++;
            }
        }
    }

    return count;
}


int main() {

    vector < vector <int> > map = {{ 1, 1, 0}, 
                                   { 1, 0, 1},
                                   { 1, 0, 1}};
    cout << count_island(map);
    return 0;
}
