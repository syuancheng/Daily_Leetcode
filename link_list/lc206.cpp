#include "list_node.h"

/**
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

*/

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *dummy = new ListNode();

    while (head) {
      ListNode *tmp = head->next;
      head->next = dummy->next;
      dummy->next = head;

      head = tmp;
    }
    return dummy->next;
  }
};