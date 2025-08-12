/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* it = new ListNode();
        ListNode* ans = it;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                it->next = list1;
                list1 = list1->next;  // move list1
                it = it->next;        // move iterator
            }
            else if (list1->val > list2->val) {
                it->next = list2;
                list2 = list2->next;  // move list2
                it = it->next;
            }
            else { // list1->val == list2->val
                it->next = list1;
                list1 = list1->next;
                it = it->next;

                it->next = list2;
                list2 = list2->next;
                it = it->next;
            }
        }

        if (list1 != nullptr) {
            it->next = list1;
        }
        if (list2 != nullptr) {
            it->next = list2;
        }

        return ans->next;
    }
};
