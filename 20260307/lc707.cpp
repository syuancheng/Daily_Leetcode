

#include <algorithm>
class MyLinkedList {
private:
  struct Node {
    int val;
    Node *next;

    Node(int v) : val(v), next(nullptr) {}
  };
  Node *head;
  int size;

public:
  MyLinkedList() {
    head = new Node(0);
    size = 0;
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    Node *cur = head->next;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size, val); }
  //[0, size-1]
  void addAtIndex(int index, int val) {
    if (index > size) {
      return;
    }
    index = std::max(index, 0);

    Node *pre = head;

    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }

    Node *tmp = new Node(val);

    tmp->next = pre->next;//last node next is nullptr
    pre->next = tmp;
    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size)
      return;

    Node *pre = head;
    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }

    Node *del = pre->next;
    pre->next = del->next;
    // mid->next = nullptr;
    delete del;
    size--;
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