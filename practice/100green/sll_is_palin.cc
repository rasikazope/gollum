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


int 
get_size(LinkedListNode *head)
{
    int size = 0;
    while (head) {
        head = head->next;
        size++;
    }
    return size;
}


LinkedListNode *
reversell(LinkedListNode *head)
{
    if (!head || !head->next) {
        return head;
    }

    LinkedListNode *prev = NULL, *cur = head, *cur_next = NULL;
    while (cur) {
        cur_next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur_next;
    }

    return prev;
}


bool
isPalin(LinkedListNode *head)
{
    if (!head || !head->next) {
        return true;
    }

    int size = get_size(head);

    LinkedListNode *sec_half = head;
    LinkedListNode *ll_last = NULL;
        
    for (int i = 0; i < size/2; i++) {
        ll_last = sec_half;
        sec_half = sec_half->next;
    }
    
    ll_last->next = NULL;
   
    if (size % 2 != 0) {
        sec_half = sec_half->next; 
    }

    LinkedListNode *newhead = reversell(sec_half);

    while (newhead && head) {
        if (newhead->val != head->val) {
            return false;
        }
        newhead = newhead->next;
        head = head->next;
    }
    // contruct back
    LinkedListNode *newhead = reversell(newhead);
    if (size % 2 != 0) {
        ll_last->next newhead;
    }
    // If there was a mid node handle that
    return true;

}



/*
 *  * Complete the function below.
 *   */
/*
 * For your reference:
 * LinkedListNode {
 *     int val;
 *         LinkedListNode *next;
 *         };
 *         */

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

    cout << isPalin(_pList) << endl;

    return 0;
}

