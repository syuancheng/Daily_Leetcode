# 146. LRU Cache

## Labels

- Hash Table
- Linked List
- Design

## Mastery

- Attempts: OHHOH
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/lru-cache/

## Problem Description

Design an LRU cache supporting get and put in O(1) time.

## My Solution

```cpp
class Node {
public:
  int key, value;
  Node *prev, *next;
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DoubleList {
private:
  Node *head;
  Node *tail;

  int size;

public:
  DoubleList() {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  int getSize() { return size; }

  void addLast(Node *x) {
    x->prev = tail->prev;
    x->next = tail;
    tail->prev->next = x;
    tail->prev = x;
    size++;
  }

  void remove(Node *x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    size--;
  }

  Node *removeFirst() {
    if (head->next == tail) {
      return nullptr;
    }

    Node *first = head->next;
    remove(first);
    return first;
  }
};

class LRUCache {
private:
  std::unordered_map<int, Node *> map;

  DoubleList cache;

  int cap;

public:
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    if (!map.count(key)) {
      return -1;
    }

    Node *n = map[key];

    cache.remove(n);
    cache.addLast(n);

    return n->value;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      Node *old = map[key];
      cache.remove(old);
      map.erase(key);
      delete old;
    }

    if (cache.getSize() == cap) {
      Node *tmp = cache.removeFirst();
      map.erase(tmp->key);
      delete tmp;
    }

    Node *node = new Node(key, value);
    cache.addLast(node);
    map[key] = node;
  }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

## Complexity

- Time: O(1) per operation.
- Space: O(capacity).
