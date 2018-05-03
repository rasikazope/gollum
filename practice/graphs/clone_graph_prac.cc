#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;


class Node {
public:
    int val;
    vector <Node *> adj;
    Node(int _val) { val = _val; visited = false;}
    bool visited;
};


Node *
clone(Node *root)
{
    list <Node *> queue;
    queue.push_back(root);
    unordered_map <Node *, Node *> map;

    Node *new_root = new Node(root->val);
    map[root] = new_root;

    while (!queue.empty()) {
        Node *tmp = queue.front();
        queue.pop_front();
        cout << tmp->val << " ";

        for (auto neigh: tmp->adj) {
            if (!map[neigh]) {
                queue.push_back(neigh);
                Node *new_node_tmp = new Node(neigh->val);
                map[neigh] = new_node_tmp;
            } 
            map[tmp]->adj.push_back(map[neigh]);
        }
    }

    return map[root];
}


void BFS(Node *root)
{

    list<Node *> queue;
    queue.push_back(root);
    root->visited = true;

    while (!queue.empty()) {
         Node *tmp = queue.front();
         queue.pop_front();
         cout << tmp->val << " : " << tmp << " "; 
         for (auto neigh : tmp->adj) {
             if (!neigh->visited) {
                 neigh->visited = true;
                 queue.push_back(neigh);
             }
         }
    }


}


int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n1->adj.push_back(n2);
    n1->adj.push_back(n3);
    n1->adj.push_back(n4);
    n2->adj.push_back(n4);
   
    Node *root = clone(n1);
    cout << endl;
    BFS(n1);
    cout << endl;
    BFS(root);

}
