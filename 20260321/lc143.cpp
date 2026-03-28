struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    if (head == nullptr) {
      return;
    }
    ListNode *midNode = middleNode(head);
    ListNode *l1 = head;
    ListNode *l2 = midNode->next;
    midNode->next = nullptr;
    l2 = reverseList(l2);
    mergeList(l1, l2);
  }

  void mergeList(ListNode *l1, ListNode *l2) {
    ListNode *l1_tmp;
    ListNode *l2_tmp;

    while (l1 != nullptr && l2 != nullptr) {
      l1_tmp = l1->next;
      l2_tmp = l2->next;

      l1->next = l2;
      l1 = l1_tmp;

      l2->next = l1;
      l2 = l2_tmp;
    }
  }

  ListNode *middleNode(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      ListNode *tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }

    return prev;
  }
};