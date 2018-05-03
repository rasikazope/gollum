#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public:
        Graph(int V_) {
            V = V_;
            adj = new list<int> [V];
        }

        void add_edge(int a, int b) 
        {
            adj[a].push_back(b);
        }

        void ts();
        void ts_util(int i, vector <bool> &visited, stack <int> &st); 
    private:
        int V;
        list <int> *adj;

};


void Graph::
ts_util(int i, vector <bool> &visited, stack <int> &st) 
{
    if (visited[i]) {
        return;
    }
    visited[i] = 1;

    for (auto itr: adj[i]) {
        ts_util(itr, visited, st);
    }

    st.push(i);
}


void
Graph::ts()
{
    vector <bool> visited(V, 0);
    stack<int> st;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            ts_util(i, visited, st);
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

}

int main() {
    Graph G(4);
    G.add_edge(0, 1);
    G.add_edge(0, 3);
    G.add_edge(0, 2);
    G.add_edge(1, 2);
    G.ts();
    return 0;
}
