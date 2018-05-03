#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LinkedListNode{
    public:
        int val;
        LinkedListNode *next;

        LinkedListNode(int node_value) {
            val = node_value;
            next = NULL;
        }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

void
swap_next_pointer(LinkedListNode ** head, LinkedListNode *prev1, LinkedListNode *node1, LinkedListNode *prev2, LinkedListNode *node2)
{
    if (!prev1) {
        *head = node2;
    } else {
        prev1->next = node2;
    }
    
    if (!prev2) {
        *head = node1;
    } else {
        prev2->next = node1;
    }

    LinkedListNode *tmp;
    tmp = node1->next;
    node1->next = node2->next;
    node2->next = tmp;


}


void    
swapknode(LinkedListNode **_pList, int k)
{

    LinkedListNode *tmp = *_pList, *prev1 = NULL, *node1 = *_pList, *prev2 = NULL, *node2 = *_pList;
    if (!tmp || !tmp->next || k <=0 ) {
        // No need to swap
        return;
    }

    while(--k && tmp) {
       prev1 = tmp;
       tmp = tmp->next;
    }
    node1 = tmp;
    
    while (tmp && tmp->next) 
    {
        prev2 = node2;
        tmp = tmp->next;
        node2 = node2->next;
    }
    
    swap_next_pointer(_pList, prev1, node1, prev2, node2);

}


int main() {

    int _pList_size = 0;
    int _pList_item;
    LinkedListNode* _pList = NULL;
    LinkedListNode* _pList_tail = NULL;
    cin >> _pList_size;
    int _pList_i;
    for(_pList_i = 0; _pList_i < _pList_size; _pList_i++) { 
        cin >> _pList_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        if(_pList_i == 0) {
            _pList = _insert_node_into_singlylinkedlist(_pList, _pList_tail, _pList_item);
            _pList_tail = _pList;
        }
        else {
            _pList_tail = _insert_node_into_singlylinkedlist(_pList, _pList_tail, _pList_item);
        }
    }

    swapknode(&_pList, 2);

    while (_pList) {
        cout << " " << _pList->val;
        _pList = _pList->next;
    }
    return 0;
}

