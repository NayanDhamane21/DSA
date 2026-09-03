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
    ListNode* recursion(ListNode* temp){
        
        if(temp == nullptr || temp->next == nullptr)
        return temp;
        ListNode* sam=temp->next;
        temp->next=temp->next->next;
        sam->next=temp;
        temp->next = recursion(temp->next);
        return sam;
    }
    ListNode* swapPairs(ListNode* head) {
        return recursion(head);
        
    }
};