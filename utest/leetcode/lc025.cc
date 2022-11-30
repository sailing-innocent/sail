/**
 * LeetCode 025: Reverse Nodes in k-Group
 * The most difficult part is that: this is a single direction linklist
 * -------------------------------------------------------
 *  ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        if (k <= 1) {
            return head;
        }
        ListNode* p = head;
        int len = 0;
        ListNode* rp = head;
        while (p != nullptr) {
            len = len + 1;
            if ( k == len) {
                rp = reverseKGroup(p->next, k);
                break;
            }            
            p = p->next;
        }            
        if (rp == head) {
            return rp;
        }
        ListNode* tail = p;
        ListNode* pPrev = head;
        ListNode* pNext = nullptr;
        p = pPrev->next;
        while ( p != tail) {
            pNext = p->next;
            p->next = pPrev;
            pPrev = p;
            p = pNext;
        }
        tail->next = pPrev;
        head->next = rp;
        return tail;
    }
*/