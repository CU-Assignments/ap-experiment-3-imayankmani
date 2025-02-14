class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // Edge case: No rotation needed
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        tail->next = head;

        k = k % length; // Optimize k (handle large values)
        int stepsToNewHead = length - k;
        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
