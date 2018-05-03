#include <iostream>

using namespace std;


struct LL {
    int val;
    struct LL *next;
    LL(int val_tmp) {
        val = val_tmp;
        next = NULL;
    }
};


int LL_length(LL *head) 
{
    int count = 0;
    while (head) {
        head = head->next;
        count++;
    }
    return count;
}

int 
intersect(LL *head1, LL *head2)
{
   int intersect_at = -1;
   int len1 = LL_length(head1); 
   int len2 = LL_length(head2);
   int diff = abs(len2-len1);

   if (len2 > len1) {
       while(diff) {
           head2 = head2->next;
           diff --;
       }
   } else {
       while(diff) {
           head1 = head1->next;
           diff --;
       }
   
   }
   while (head1) {
        if (head1 == head2) {
            intersect_at = head1->val;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
   }
    return intersect_at;

}


int main() {

     // LL1 : 1,2,3,4,5 LL2: 6,3,4,5
     LL *head1 = new LL(1);
     LL *node2 = new LL(2);
     LL *node3 = new LL(3);
     LL *node4 = new LL(4);
     LL *node5 = new LL(5);
     LL *node6 = new LL(6);
    
     head1->next = node2;
     node2->next = node3;
     node3->next = node4;
     node4->next = node5;

     node6->next = node5;

     cout << intersect(head1, node6);

     return 0;
}
