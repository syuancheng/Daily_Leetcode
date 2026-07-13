#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class WeightedDigraph {
public:
  struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
  };

private:
  std::vector<std::vector<Edge>> graph;

public:
  explicit WeightedDigraph(int n) : graph(static_cast<size_t>(n)) {}

  void addEdge(int from, int to, int weight) {
    graph[static_cast<size_t>(from)].emplace_back(to, weight);
  }

  void removeEdge(int from, int to) {
    auto &edges = graph[static_cast<size_t>(from)];
    for (auto it = edges.begin(); it != edges.end(); ++it) {
      if (it->to == to) {
        edges.erase(it);
        break;
      }
    }
  }

  bool hasEdge(int from, int to) const {
    for (const auto &edge : graph[static_cast<size_t>(from)]) {
      if (edge.to == to) {
        return true;
      }
    }
    return false;
  }

  int weight(int from, int to) const {
    for (const auto &edge : graph[static_cast<size_t>(from)]) {
      if (edge.to == to) {
        return edge.weight;
      }
    }
    throw std::invalid_argument("No such edge");
  }

  const std::vector<Edge> &neighbors(int v) const {
    return graph[static_cast<size_t>(v)];
  }
};

int main() {
  WeightedDigraph graph(3);
  graph.addEdge(0, 1, 1);
  graph.addEdge(1, 2, 2);
  graph.addEdge(2, 0, 3);
  graph.addEdge(2, 1, 4);

  std::cout << std::boolalpha << graph.hasEdge(0, 1) << '\n';
  std::cout << std::boolalpha << graph.hasEdge(1, 0) << '\n';

  for (const auto &edge : graph.neighbors(2)) {
    std::cout << "2 -> " << edge.to << ", weight: " << edge.weight << '\n';
  }

  graph.removeEdge(0, 1);
  std::cout << std::boolalpha << graph.hasEdge(0, 1) << '\n';

  return 0;
}
