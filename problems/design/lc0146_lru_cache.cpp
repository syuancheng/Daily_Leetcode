#include <unordered_map>

struct DLinkedNode {
  int key, value;
  DLinkedNode *next;
  DLinkedNode *prev;

  DLinkedNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
  DLinkedNode(int k, int n) : key(k), value(n), next(nullptr), prev(nullptr) {}
};

class LRUCache {

  int capacity;
  int size;
  DLinkedNode *head;
  DLinkedNode *tail;
  std::unordered_map<int, DLinkedNode *> cache;

public:
  LRUCache(int c) : capacity(c), size(0) {
    head = new DLinkedNode();
    tail = new DLinkedNode();

    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (cache.count(key) == 0) {
      return -1;
    }
    DLinkedNode *node = cache[key];
    moveToHead(node);

    return node->value;
  }

  void put(int key, int value) {
    if (cache.count(key) == 0) {
      DLinkedNode *node = new DLinkedNode(key, value);
      cache[key] = node;
      addToHead(node);
      ++size;
      if (size > capacity) {
        DLinkedNode *removed = removeTail();
        cache.erase(removed->key);
        delete removed;
        --size;
      }
    } else {
      DLinkedNode *node = cache[key];
      node->value = value;
      moveToHead(node);
    }
  }

  void moveToHead(DLinkedNode *node) {
    removeNode(node);
    addToHead(node);
  }

  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addToHead(DLinkedNode *node) {
    node->prev = head;
    node->next = head->next;

    head->next->prev = node;
    head->next = node;
  }

  DLinkedNode *removeTail() {
    DLinkedNode *node = tail->prev;
    removeNode(node);
    return node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
