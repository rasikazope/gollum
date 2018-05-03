#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


class Node {
    public:
    int val;
    list <Node *> adj;
    Node(int val_t) {
        val = val_t;
    }

    void add_neigh(Node *neigh) {
        adj.push_back(neigh);
    }
};

Node *
graph_clone(Node *root)
{
    list <Node *> queue;
    unordered_map<Node *, Node *> map;  
    queue.push_back(root);
    

    Node *c_temp = NULL; 
    while (!queue.empty()) {
        Node *temp = queue.front();
        queue.pop_front();
        for (auto itr : temp->adj) {
            if (!map[itr]) {
                c_temp = new Node(itr->val);
                map[itr] = c_temp;
                queue.push_back(itr);
            } else {
                c_temp = map[itr]
            }
            c_temp->add_neigh(map[itr]);
        }
    }

    return map[root];
    
}


int main() {
    // 0->2->3->0
    // |
    // 1
    Node *root = new Node(0);
    Node *root_1 = new Node(1);
    Node *root_2 = new Node(2);
    Node *root_3 = new Node(3);
    root->add_neigh(root_2);
    root->add_neigh(root_1);
    root_2->add_neigh(root_3);
    root_3->add_neigh(root);
    Node *cloned_node = graph_clone(root);
    return 0;
}
