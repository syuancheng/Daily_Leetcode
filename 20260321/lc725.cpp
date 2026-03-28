#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
  int val;

  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int n) : val(n), next(nullptr) {}
};

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return {head};
    }

    int n = 0;
    ListNode *curr = head;
    while (curr) {
      n++;
      curr = curr->next;
    }

    int size = n / k, restSize = n % k;

    vector<ListNode *> ans =
        {}; // ans.size = k, [0, restSize-1]: size+1, [restSize, k-1]: size

    ListNode *h = new ListNode(0);

    

    return {};
  }
};