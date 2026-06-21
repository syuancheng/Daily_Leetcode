#include "list_node.h"

#include <cstddef>
#include <vector>

/**
 * Interview. 单链表初始化与基本操作
 *
 * 题目描述：
 * 使用已有的 ListNode 结构，实现一个管理单链表的 SinglyLinkedList 类。
 * 不允许使用 std::list 或 std::forward_list 保存节点。
 *
 * 需要实现：
 * 1. 创建空链表，以及根据 vector 中的元素顺序初始化链表。
 * 2. 判断链表是否为空，并返回当前节点数量。
 * 3. 在链表头部、尾部插入节点。
 * 4. 在指定下标插入节点：合法范围为 [0, size]。
 * 5. 删除指定下标的节点：合法范围为 [0, size - 1]。
 * 6. 查找第一个值等于 target 的节点；找不到时返回 nullptr。
 * 7. 按链表顺序将所有节点值转换成 vector。
 * 8. 清空链表，并在对象销毁时释放所有动态分配的节点。
 *
 * 下标规则：
 * - 下标从 0 开始。
 * - insert 的下标无效时返回 false，否则插入并返回 true。
 * - erase 的下标无效时返回 false，否则删除并返回 true。
 *
 * 示例：
 *
 * SinglyLinkedList list({1, 2, 3});
 * list.pushFront(0);       // 0 -> 1 -> 2 -> 3
 * list.pushBack(4);        // 0 -> 1 -> 2 -> 3 -> 4
 * list.insert(2, 9);       // 0 -> 1 -> 9 -> 2 -> 3 -> 4
 * list.erase(3);           // 0 -> 1 -> 9 -> 3 -> 4
 * list.find(9);            // 返回值为 9 的节点
 * list.toVector();         // {0, 1, 9, 3, 4}
 *
 * 要求：
 * - size 和 empty 的时间复杂度为 O(1)。
 * - pushFront 的时间复杂度为 O(1)。
 * - 其他需要遍历链表的操作允许为 O(n)。
 * - clear 和析构后不能发生内存泄漏。
 */

class SinglyLinkedList {
private:
  ListNode *head_;
  std::size_t size_;

public:
  SinglyLinkedList() : head_(new ListNode()), size_(0) {}
  explicit SinglyLinkedList(const std::vector<int> &values)
      : SinglyLinkedList() {
    for (int value : values) {
      pushBack(value);
    }
  }
  ~SinglyLinkedList() {
    clear();
    delete head_;
    head_ = nullptr;
  }

  SinglyLinkedList(const SinglyLinkedList &) = delete;
  SinglyLinkedList &operator=(const SinglyLinkedList &) = delete;

  bool empty() const { return this->size_ == 0; }
  std::size_t size() const { return this->size_; }

  void pushFront(int value) { insert(0, value); }
  void pushBack(int value) { insert(this->size_, value); }

  bool insert(std::size_t index, int value) {
    if (index > this->size_) {
      return false;
    }

    ListNode *node = new ListNode(value);
    ListNode *prev = this->head_;
    for (std::size_t pos = 0; pos < index; ++pos) {
      prev = prev->next;
    }

    node->next = prev->next;
    prev->next = node;
    this->size_++;
    return true;
  }

  bool erase(std::size_t index) {
    if (index >= this->size_) {
      return false;
    }

    ListNode *prev = this->head_;
    for (std::size_t pos = 0; pos < index; ++pos) {
      prev = prev->next;
    }

    ListNode *target = prev->next;
    prev->next = target->next;
    delete target;
    this->size_--;
    return true;
  }

  ListNode *find(int target) {
    ListNode *cur = this->head_->next;
    while (cur != nullptr) {
      if (cur->val == target) {
        return cur;
      }
      cur = cur->next;
    }
    return nullptr;
  }

  std::vector<int> toVector() const {
    std::vector<int> values;
    values.reserve(this->size_);

    ListNode *cur = this->head_->next;
    while (cur != nullptr) {
      values.push_back(cur->val);
      cur = cur->next;
    }
    return values;
  }

  void clear() {
    ListNode *cur = this->head_->next;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      delete cur;
      cur = next;
    }
    this->head_->next = nullptr;
    this->size_ = 0;
  }
};
