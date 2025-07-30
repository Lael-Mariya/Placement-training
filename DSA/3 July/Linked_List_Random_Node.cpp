class Solution {
 public:
  Solution(ListNode* head) : head(head) {}

  int getRandom() {
    int res = -1;
    int i = 1;

    for (ListNode* curr = head; curr; curr = curr->next, ++i)
      if (rand() % i == 0)
        res = curr->val;

    return res;
  }

 private:
  ListNode* head;
};
