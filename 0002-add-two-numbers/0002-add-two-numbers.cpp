// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify edge cases
//         ListNode* curr = dummyHead;
//         int carry = 0;

//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int x = 0, y = 0;

//             // Get the value from l1 if it is not null
//             if (l1 != nullptr) {
//                 x = l1->val;
//                 l1 = l1->next;
//             }

//             // Get the value from l2 if it is not null
//             if (l2 != nullptr) {
//                 y = l2->val;
//                 l2 = l2->next;
//             }

//             int sum = carry + x + y;
//             carry = sum / 10;

//             curr->next = new ListNode(sum % 10);
//             curr = curr->next;
//         }

//         return dummyHead->next;  // Return the next node after dummy
//     }
// };
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
class Solution
{
public:
//iterative--------------------------------------------------------------------
    ListNode *iterative(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(-1);
        ListNode *it = ans;

        int carry = 0;
        while (l1 || l2 || carry)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;
            it->next = new ListNode(digit);
            it = it->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode *finalAns = ans->next;
        delete ans;
        return finalAns;
    }
//recurrsion----------------------------------------------------------
    ListNode *recursive(ListNode *l1, ListNode *l2, int carry = 0)
    {
        if (!l1 && !l2 && !carry)
            return 0;

        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;

        // build the ans LL
        ListNode *ans = new ListNode(digit);
        ans->next = recursive(l1 ? l1->next : l1, l2 ? l2->next : l2, carry);
        return ans;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // return iterative(l1, l2);
        return recursive(l1, l2);
    }
};