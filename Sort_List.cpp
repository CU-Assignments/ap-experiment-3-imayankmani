class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; 
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        tail->next = left ? left : right; 
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; 
        
        ListNode* mid = getMid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(rightHead);
        
        return merge(leftSorted, rightSorted);
    }
};
