#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Graph {
    private:
        int V;
        list <int> *adj;
    public:
        Graph(int UV) { 
            V = UV;
            adj = new list <int> [V]; 
        }

        void add_adj(int u, int v) {
            adj[u].push_back(v);
        }

        bool detect_cycle();
        bool detect_cycle_wrapper(bool visited[], int index, int parents[]);
};

bool
Graph::detect_cycle_wrapper(bool visited[], int index, int parents[])
{
    if (visited[index]) {
        return false;
    }
    
    for (int i = 0 ; i < V; i++) {
        if (parents[i] == index) {
            cout << "Ops there is a loop " << index <<  " "<< parents[i] << endl ;
            return true;
        }
    }

    parents[i] = ;
    visited[index] = true;
  
    cout << index << " ";
    for (auto adj_itr : adj[index]) {
        //cout << "adj_itr " << adj_itr << " " << endl;
        if (visited[adj_itr] == 0) {
            bool ret = detect_cycle_wrapper(visited, adj_itr, parents);
            if (ret == true) {
                return ret;
            }
        }
    }

    parents[index] = false;
    return false;
}

bool
Graph::detect_cycle()
{
 
    bool ret = false;
    bool visited[V];
    int parents[V];

    memset(visited, 0, sizeof(visited));
   
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            memset(parents, -1, sizeof(parents));
            ret = detect_cycle_wrapper(visited, i, parents);
            if (ret) {
                return ret;
            }
        }
    }
    return ret;
}


int main() {

    Graph G(4);
    G.add_adj(0, 1);
    G.add_adj(1, 2);
    G.add_adj(1, 3);
    cout << G.detect_cycle();
    return 0;
}
