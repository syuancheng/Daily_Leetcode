
struct ListNode {
  int val;

  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int n) : val(n), next(nullptr) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    if (!node->next) {
      return;
    }
    node->val = node->next->val;
    node->next = node->next->next;
  }
};