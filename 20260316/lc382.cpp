#include <cstddef>
#include <cstdlib>
#include <random>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  std::vector<int> values;

public:
  Solution(ListNode *head) {
    while (head) {
      values.push_back(head->val);
      head = head->next;
    }
  }

  int getRandom() { return values[rand() % values.size()]; }
};


class Solution2 {
private:
  ListNode* head;

public:
  Solution2(ListNode *head) {
    this->head = head;
  }

  int getRandom() {

    int ans = 0, count = 1;

    auto node = head;
    while (node) {
        if (rand() % count == 0) {
            ans = node->val;
        }
        count++;
        node = node->next;
    }

    return ans;
};
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */