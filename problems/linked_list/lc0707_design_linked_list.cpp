#include "list_node.h"
#include <cstddef>

/**
707. 设计链表
*/

class MyLinkedList {
private:
  ListNode *_dummy;
  int _size;

public:
  MyLinkedList() {
    ListNode *node = new ListNode();
    this->_dummy = node;
    _size = 0;
  }

  int get(int index) {
    if (index < 0 || index >= _size) {
      return -1;
    }
    int pos = 0;
    ListNode *curr = _dummy;
    for (int i = 0; i <= index; i++) {
      curr = curr->next;
    }
    return curr->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(_size, val); }

  void addAtIndex(int index, int val) {
    if (index > _size) {
      return;
    }

    index = max(0, index);

    ListNode *pre = _dummy;

    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }
    ListNode *temp = new ListNode(val, pre->next);
    pre->next = temp;
    _size++;
    return;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= _size) {
      return;
    }

    ListNode *pre = _dummy;
    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }
    ListNode *curr = pre->next;
    pre->next = curr->next;
    curr->next = nullptr;
    _size--;

    return;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */