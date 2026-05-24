#include <atomic>
#include <butil/atomicops.h>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

class Node {

  std::vector<Node *> input_nodes;
  std::vector<Node *> ouput_nodes;

  butil::atomic<int32_t> inDegree{0};

  size_t getIndegree() const { return input_nodes.size(); }
  size_t getOutdegree() const { return ouput_nodes.size(); };
};

class Graph {
  std::unordered_map<Node *, std::vector<Node *>>
      graph; // key: node, value: nodes rely on this node
  std::unordered_map<Node *, int> inDegrees;
};
