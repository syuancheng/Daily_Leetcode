

#include <cstdio>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

struct Node {
  std::string name;
  std::vector<std::string> input_nodes;
  int count = 0;

  Node(std::string &node_name, std::vector<std::string> &nodes)
      : name(node_name), input_nodes(nodes), count(nodes.size()) {}
};

int main() {

  std::vector<std::string> input_nodes = {"node1", "node2"};

  std::shared_ptr<Node> node1 = std::make_shared<Node>("node1");
  std::shared_ptr<Node> node2 = std::make_shared<Node>("node2");
  std::shared_ptr<Node> node3 = std::make_shared<Node>("node3", input_nodes);

  std::vector<std::shared_ptr<Node>> nodes = {node1, node2, node3};

  //执行所有入读为0的node， 所有入度不为0的node 入读减一
  for (auto& node : nodes) {
    if (node->count != 0) {
        node->count--;
        continue;
    }
    std::cout << "run " << node->name << std::endl;
  }
  
}
