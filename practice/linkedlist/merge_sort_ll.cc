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
LinkedListNode* mergeSortList(LinkedListNode* pList) {


}




int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    LinkedListNode* res;

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

    res = mergeSortList(_pList);
    while (res != NULL) {
        fout << res->val << endl;

        res = res->next;
    }

    fout.close();
    return 0;
}

