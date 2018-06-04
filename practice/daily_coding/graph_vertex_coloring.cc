#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;


class Graph {

public:
    int V;
    list <int> *adj;


    Graph(int U_V) {
        V = U_V;
        adj = new list <int> [V];
    }
    void add_adj(int u, int v) {
        adj[u].push_back(v);
    }

};


bool
color_valid(Graph G, int color, int vertex_index, vector <int> vertex_color) 
{
    for (auto neigh: G.adj[vertex_index]) {
        if (vertex_color[neigh] == color) {
            return false;
        }
    }
    return true;
}

bool
color_graph_vertices_helper(Graph G, int k, int vertex_index, vector <int> vertex_color) 
{
 
    if (vertex_index == G.V) {
        return true;
    }

    for (int i = 0; i < k; i++)  {
        if (color_valid(G, i, vertex_index, vertex_color)) {
            vertex_color[vertex_index] = i;
            if (color_graph_vertices_helper(G, k, vertex_index + 1, vertex_color)) {
                return true;
            }
        }
    }
    return false;
}


bool
color_graph_vertices(Graph G, int k)
{

    vector<int> vertex_color(G.V, INT_MAX); 
    return color_graph_vertices_helper(G, k, 0, vertex_color);


}

int main() {

    Graph  G(4);
    G.add_adj(0, 1);
    G.add_adj(1, 0);
    G.add_adj(0, 2);
    G.add_adj(2, 0);
    G.add_adj(1, 3);
    G.add_adj(3, 1);
    G.add_adj(2, 3);
    G.add_adj(3, 2);
    G.add_adj(1, 2);
    G.add_adj(2, 1);
    cout << color_graph_vertices(G, 2) << endl;

    return 0;

}
