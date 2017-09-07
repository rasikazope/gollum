#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct LinkedList {
    int val;
    LinkedList *next;
    LinkedList(int _val) { val = _val; next = NULL;}
};




class compare {
    public:
    bool operator() (LinkedList *n1, LinkedList *n2) {
        if (n1->val > n2->val) {
            return true;
        }
    }
};

LinkedList *
merge(LinkedList *myvec[]) 
{
    LinkedList *newhead = NULL;

    priority_queue <LinkedList *, vector<LinkedList *>, compare> pq;    
    for (int i = 0; i < 2; i++) {
        pq.push(myvec[i]);
    }

    LinkedList *last = NULL;

    while (!pq.empty()) {
        // cout << pq.top()->val << endl;
        LinkedList *top = pq.top();
        if (pq.top()->next) {
            pq.push(pq.top()->next);
        }
        pq.pop();

        if (!newhead) {
            newhead = top;
            last = top;
        } else {
            last->next = top;
            last = top;
        }
    }

    return newhead;

}



int main() {
    //vector <LinkedList *> myvec(2);
    LinkedList * myvec[2];

    LinkedList *head1 = new LinkedList(1);
    LinkedList *h1_next1 = new LinkedList(3);
    LinkedList *h1_next2 = new LinkedList(5);

    head1->next = h1_next1;
    h1_next1->next = h1_next2;

    LinkedList *head2 = new LinkedList(2);
    LinkedList *h2_next1 = new LinkedList(6);
    LinkedList *h2_next2 = new LinkedList(8);

    head2->next = h2_next1;
    h2_next1->next = h2_next2;

    myvec[0] = head1;
    myvec[1] = head2;

    LinkedList *newhead = merge(myvec);
    
    while (newhead) {
        cout << newhead->val << endl;
        newhead = newhead->next;
    }



    return 0;
}
