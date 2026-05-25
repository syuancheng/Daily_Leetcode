#include <atomic>
#include <cstddef>
#include <cstdint>
#include <vector>

class Node {
private:
  std::vector<Node *> _ouput_nodes;

  std::atomic<int32_t> _inDegree{0};

public:
  size_t getOutdegree() const { return _ouput_nodes.size(); };

  int inDegree() { return _inDegree; }

  void precede(Node *n) { // a.precede(b) a -> b
    this->_ouput_nodes.emplace_back(n);
    n->_inDegree.fetch_add(1); //
  }
};

class Graph {
private:
  std::vector<Node *> _nodes; // key: node, value: nodes rely on this node
public:
  std::vector<Node *> get_nodes() { return this->_nodes; }
};
