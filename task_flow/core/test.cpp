#include "graph.hpp"
#include <bthread/bthread.h>

int main() {
  Graph graph;

  auto nodes = graph.get_nodes();

  for (auto &node : nodes) {
    if (node->inDegree() == 0) {
      //bthread run node
    }
  }
}