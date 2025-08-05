/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;
        ListNode *temp=head;
        if(temp==nullptr){
            return false;
        }
        if(temp->next==nullptr){
            return false;
        }
        while(temp!=nullptr){
            if(mp[temp]==true){
                return true;
            }
            else{
                mp[temp]=true;
            }
            temp=temp->next;
        }
        return false;
    }
};