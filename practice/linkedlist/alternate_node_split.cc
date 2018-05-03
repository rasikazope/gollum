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
void alternativeSplit(LinkedListNode* pList) {

    if (!pList) {
        return;
    }


    LinkedListNode *head1 = pList, *head2 = pList->next;
    if (!head2) {
        cout << head1->val;
        return;
    }
    LinkedListNode *head2_bk = head2;

    while(head1 && head1->next && head2 && head2->next) {
        head1->next = head2->next;
        head1 = head1->next;
        head2->next = head1->next;
        head2 = head2->next;
    }
    if (head1) {
        head1->next = NULL;
    }
    if (head2) {
        head2->next = NULL;
    }
    while (pList) {
        cout << pList->val;
        if (pList->next) {
            cout <<", ";
        }
        pList = pList->next;
    }
    cout << endl;
    
    while (head2_bk) {
        cout << head2_bk->val;
        if (head2_bk->next) {
            cout <<", ";
        }
        head2_bk = head2_bk->next;
    }
    cout << endl;


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

    alternativeSplit(_pList);

    return 0;
}

