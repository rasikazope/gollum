#include <iostream>
#include <list>
#include <stack>

using namespace std;


class Graph {
    int V;
    list<int> *adj;
    bool detect_cycle_util(int, bool vsisted[], bool rec_stack[]);
    
    public:
    Graph(int _V) {
        V = _V;
        adj = new list<int>[V];
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool detect_cycle();
};


bool Graph:: 
detect_cycle_util(int u, bool visited[], bool rec_stack[])
{
   visited[u] = true;
   rec_stack[u] = true;
   cout << u << " ";
   bool ret = false;

   for (auto neigh: adj[u]) {
       if (true == rec_stack[neigh]) {
           return true;
       }
       if (!visited[neigh]) {
           ret = detect_cycle_util(neigh, visited, rec_stack);
       }
    }
   rec_stack[u] = false;
   return ret;
}

    bool
Graph::detect_cycle()
{

    bool visited[V];
    bool rec_stack[V];
    memset(visited, 0, sizeof(visited));
    memset(rec_stack, 0, sizeof(rec_stack));

    for (int i = 0; i < V; i++) {

        if (!visited[i]) {
            if (detect_cycle_util(i, visited, rec_stack)) {
                return true;
            }
        }
    }

    return false;
}



int main()
{

    Graph G(4);
    G.add_edge(0, 1);
    G.add_edge(1, 2);
    //G.add_edge(3, 2);
    G.add_edge(2, 3);
    // G.add_edge(3, 0);
    cout << endl << endl<< G.detect_cycle();
    return 1;
}
