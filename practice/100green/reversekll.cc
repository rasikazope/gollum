ListNode* Solution::reverseList(ListNode* A, int B) {

    ListNode *cur = A;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    int count = 0;

    while (cur != NULL && count < B) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }

    if (next) {
        A->next = reverseList(next, B);
    }

    return prev;

}

