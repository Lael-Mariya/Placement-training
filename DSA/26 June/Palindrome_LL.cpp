class Solution {
public:
    bool isPalindrome(ListNode* head) {
         ListNode* slow=head;
        ListNode* fast=head->next;
        while (fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev =nullptr;
        ListNode* curr=slow->next;
        while (curr) {
            ListNode* nextTemp =curr->next;
            curr->next = prev;
            prev= curr;
            curr= nextTemp;
        }
        while (prev) {
            if (prev->val!=head->val) {
                return false;
            }
            prev=prev->next;
            head=head->next;
        }
        return true;
        
    }
};
