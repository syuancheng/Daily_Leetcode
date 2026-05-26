#include "list_node.h"

/**
143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
*/

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