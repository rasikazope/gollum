#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void
add_neighbor(queue <pair <int, int> > &myq,  queue<int> &path_q, vector <vector <int> > matrix, 
        vector < vector <int> > visited, int x, int y, int path_size)
{
    if ((x>=0 && x < matrix.size()) && (y >=0 && y < matrix[0].size())) {
        if (visited[x][y] == 0 && matrix[x][y] == 1) {
            myq.push(make_pair(x, y)); 
            path_q.push(path_size + 1);
        }
    }
}

int
min_steps(vector <vector <int> > matrix, int sx, int sy, int ex, int ey)
{
    vector < vector <int> > visited(matrix.size(), vector <int> (matrix[0].size(), 0));

    queue <pair <int, int> > myq;
    queue <int > path_size;
    
    myq.push(make_pair(sx, sy));
    path_size.push(0);
    while (!myq.empty()) {
        auto myp = myq.front();
        auto p_size = path_size.front();
        myq.pop();
        path_size.pop();

        visited[myp.first][myp.second] = 1;
        if ( myp.first == ex && myp.second == ey) {
            return p_size;
        }
        add_neighbor(myq, path_size, matrix, visited, myp.first-1, myp.second, p_size);
        add_neighbor(myq, path_size, matrix, visited, myp.first, myp.second-1, p_size);
        add_neighbor(myq, path_size, matrix, visited, myp.first+1, myp.second, p_size);
        add_neighbor(myq, path_size, matrix, visited, myp.first, myp.second+1, p_size);
    }

    
    return 0;
}

int main() {

    vector <vector <int> > matrix =  
               {{1, 1, 0},
                {0, 1, 0},
                {1, 1, 1 }};
    cout << min_steps(matrix, 0, 0, 2, 0) << endl;
    return 0;
}
