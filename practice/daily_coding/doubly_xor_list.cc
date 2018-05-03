#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct dll 
{
    int data;
    dll *pn;

    dll(int _data) {
        data = _data;
        pn = NULL;
    }
    

};

void
add(dll *root, int data)
{

    dll *prev = NULL;
    dll *next = NULL; 
    dll *new_node = new dll(data);
    while (root) {
        dll *next = (dll *)((unsigned long) prev ^ ((unsigned long)root->pn));
        prev = root;
        root = next;  
    }
    // Note: don't forget to cast the pointers to unsigned long
    prev->pn = (dll *)((unsigned long)prev->pn ^ (unsigned long)new_node);
    new_node->pn = prev;

}

int
get_index(dll *root, int index)
{
    dll *prev = NULL;
    dll *next = NULL; 
    int count = 1;
    while (root && count <= index) {
        if (count == index) {
            return root->data;
        }
        count++;
        dll *next = (dll *)((unsigned long) prev ^ ((unsigned long)root->pn));
        prev = root;
        root = next;  
    }
 
    return -1;

}



int main() {

    dll *dll_root = new struct dll(1);
    add(dll_root, 2);
    add(dll_root, 3);
    add(dll_root, 4);
    cout << get_index(dll_root, 2) << endl;
    return 0;
}
