class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        while (--k) {
            fast=fast->next;
        }
        ListNode* slow=head;
        ListNode* firstNode=fast;
        while (fast->next) {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* secondNode=slow;
        std::swap(firstNode->val, secondNode->val);
        return head;
    }
};
