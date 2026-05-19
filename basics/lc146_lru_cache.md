# 146. LRU Cache

## Labels

- Hash Table
- Linked List
- Design

## Mastery

- Attempts: H
- Status: Beginner

## Link

https://leetcode.com/problems/lru-cache/

## Problem Description

Design an LRU cache with a fixed positive capacity. The cache supports `get(key)`, which returns the value for an existing key or `-1` otherwise, and `put(key, value)`, which inserts or updates a key-value pair. Whenever a key is accessed or updated, it becomes the most recently used item. If insertion exceeds the capacity, remove the least recently used item. Both operations must run in average `O(1)` time.

## My Solution

```cpp
#include <unordered_map>
struct DLinkedNode {
  int key, value;
  DLinkedNode *prev;
  DLinkedNode *next;

  DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkedNode(int k, int n) : key(k), value(n), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
  int capacity;
  int size;
  DLinkedNode *head;
  DLinkedNode *tail;
  std::unordered_map<int, DLinkedNode *> cache;

public:
  LRUCache(int _capacity) : capacity(_capacity), size(0) {
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

  void addToHead(DLinkedNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedNode *node) {
    removeNode(node);
    addToHead(node);
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
```

## Complexity

- Time: O(1) average time for both `get` and `put`.
- Space: O(capacity), for the hash table and linked-list nodes.
