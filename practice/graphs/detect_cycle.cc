#include <iostream>
#include <list>
#include <stack>

using namespace std;



class Graph {
    
private:
    int V;
    list<int> *adjlist;
public:
    Graph(int u_V) {
        V = u_V;
        adjlist = new list<int> [V];
    }
    void addedge(int u, int v) {
        adjlist[u].push_back(v); 
    }

    void print() {
        for (int i = 0; i < V; i++) {
            for( auto itr : adjlist[i]) {
                cout << i << " " << itr << " ";
                cout << endl;
            }
        }
    }

    bool has_cycle_util(int val, bool visited[], bool rec_stack[]) {
        
        //cout << val << " ";
        visited[val] = true;
        rec_stack[val] = true;

        for (auto itr: adjlist[val]) {

            if (rec_stack[itr] == true) {
                return true;
            }
            if (visited[itr] == false) {
                return has_cycle_util(itr, visited, rec_stack);
            }
        }

        rec_stack[val] = false;
        return false;

    }

    bool has_cycle() {
        bool *visited = new bool[V];
        bool *rec_stack = new bool[V];
        
        for (int i = 0; i < V ; i++) {
            visited[i] = false;
            rec_stack[i] = false;
        }

        cout << endl;
        for (int i = 0; i < V ; i++) {
            if (visited[i] == false) {
                if (has_cycle_util(i, visited, rec_stack))
                    return true;
            }
        }
        return false;
    }
};






int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Graph G(5);
    G.addedge(0, 1);
    G.addedge(1, 3);
    G.addedge(2, 0);
    G.addedge(3, 2);
    G.addedge(0, 4);
    G.print();

    cout << endl << "Result " << G.has_cycle() << endl;
    
    return 0;
}
