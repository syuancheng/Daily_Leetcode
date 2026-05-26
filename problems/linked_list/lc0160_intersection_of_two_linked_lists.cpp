#include <cstddef>
#include "list_node.h"
#include <unordered_set>

using namespace std;

/**
160. 相交链表

*/


class Solution {
public:
  // get size
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tmpA = headA;
    int sizeA = 0, sizeB = 0;
    while (tmpA) {
      sizeA++;
      tmpA = tmpA->next;
    }

    ListNode *tmpB = headB;
    while (tmpB) {
      sizeB++;
      tmpB = tmpB->next;
    }

    tmpA = headA, tmpB = headB;
    int step = 0;
    if (sizeA > sizeB) {
      while (step < (sizeA - sizeB) && tmpA != nullptr) {
        tmpA = tmpA->next;
        step++;
      }
    } else {
      while (step < (sizeB - sizeA) && tmpB != nullptr) {
        tmpB = tmpB->next;
        step++;
      }
    }

    while (tmpA != nullptr && tmpB != nullptr && tmpA != tmpB) {
      tmpA = tmpA->next;
      tmpB = tmpB->next;
    }
    return tmpA;
  }

  ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    unordered_set<ListNode *> nodes;
    while (headA) {
      nodes.insert(headA);
      headA = headA->next;
    }

    while (headB) {
      if (nodes.count(headB) == 1) {
        return headB;
      }
      headB = headB->next;
    }
    return nullptr;
  }

  ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    ListNode *pa = headA;
    ListNode *pb = headB;

    while (pa != pb) {//如果没有交点，最终都会为nullptr
      pa = pa == nullptr ? headB : pa->next;
      pb = pb == nullptr ? headA : pb->next;
    }
    return pa;
  }
};