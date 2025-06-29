class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
          if (!head || !head->next) {
            return head;
        }
        ListNode* curr=head;
        int length=0;
        while (curr){
            ++length;
            curr=curr->next;
        }
        k %= length;
        if (k==0) {
            return head;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while (k--) {
            fast=fast->next;
        }
        while (fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* new_head=slow->next; 
        slow->next=nullptr;
        fast->next=head; 
        return new_head;
        
    }
};
