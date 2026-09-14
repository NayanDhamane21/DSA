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
        if(head==nullptr) return 0;
        if(!head->next) return 0;
        ListNode* slow=head;
        ListNode* fast=head->next;


        while(fast->next && fast->next->next){
            if(slow==fast) return 1;
            slow=slow->next;
            fast=fast->next->next;
        }
        return 0;

    }
};