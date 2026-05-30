
struct ListNode {
  int val;

  ListNode *next;

  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int n) : val(n), next(nullptr) {
  }
  ListNode(int n, ListNode *node) : val(n), next(node) {
  }
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
  }
};