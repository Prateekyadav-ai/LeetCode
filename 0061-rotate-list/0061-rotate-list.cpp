class Solution {
public:
    int getlength(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // edge cases

        int len = getlength(head);
        k = k % len;  // handle large k
        if (k == 0) return head; // no rotation needed

        int rotate = len - k; // number of steps to new head

        ListNode* temp1 = head;
        for (int count = 1; count < rotate; count++) {
            temp1 = temp1->next;
        }

        ListNode* temp2 = temp1->next; // new head
        temp1->next = nullptr; // break the list

        ListNode* temp3 = temp2;
        while (temp3->next != nullptr) {
            temp3 = temp3->next;
        }
        temp3->next = head; // connect old tail to old head

        return temp2;
    }
};
