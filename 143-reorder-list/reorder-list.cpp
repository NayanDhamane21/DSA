class Solution {
public:
    ListNode* findmiddle(ListNode* temp){
        ListNode* slow = temp;
        ListNode* fast = temp; 
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* temp){
        ListNode* prev = nullptr;
        ListNode* curr = temp;
        while(curr){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find middle
        ListNode* middle = findmiddle(head);
        
        // 2. Split the list and reverse the second half
        ListNode* temp2 = reverse(middle->next);
        middle->next = nullptr; 
        
        // 3. Merge alternating nodes
        ListNode* temp1 = head;
        while (temp2) { 
            ListNode* dummy1 = temp1->next;
            ListNode* dummy2 = temp2->next;
            
            temp1->next = temp2;
            temp2->next = dummy1;
            
            temp1 = dummy1;
            temp2 = dummy2;
        }
    }
};
