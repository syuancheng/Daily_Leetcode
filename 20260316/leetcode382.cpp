//review 707

class MyLinkedList {
private:
  struct Node {
    Node *next;
    int val;

    Node(int n): val(n), next(nullptr) {}
  };

  Node *head;
  int size = 0;

public:
  MyLinkedList(): head(new Node(0)), size(0) {}
  
  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }

    int start = 0;
    Node *cur = head->next;
    while (start < index) {
      cur = cur->next;
      start++;
    }
    return cur->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size, val); }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
      return;
    }

    int start = 0;
    Node *prev = head;
    while (start < index) {
      prev = prev->next;
      start++;
    }
    Node *tmp = new Node(val);

    tmp->next = prev->next;
    prev->next = tmp;
    size++;
  }

  void deleteAtIndex(int index) {
    int start = 0;
    Node *prev = head;
    while (start < index) {
      prev = prev->next;
      start++;
    }
    Node *del = prev->next;
    prev->next = del->next;
    del->next = nullptr;
  }
};
