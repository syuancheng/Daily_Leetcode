#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class WeightedDigraph {
public:
  struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) {
      this->to = to;
      this->weight = weight;
    }
  };

private:
  std::vector<std::vector<Edge>> graph;

public:
  WeightedDigraph(int n) { graph = std::vector<std::vector<Edge>>(n); }

  void addEdge(int from, int to, int weight) {
    graph[from].emplace_back(to, weight);
  }

  void removeEdge(int from, int to) {
    for (auto it = graph[from].begin(); it != graph[from].end(); ++it) {
      if (it->to == to) {
        graph[from].erase(it);
        break;
      }
    }
  }

  bool hasEdge(int from, int to) {
    for (const auto &t : graph[from]) {
      if (t.to == to) {
        return true;
      }
    }
    return false;
  }

  int weight(int from, int to) {
    for (const auto &t : graph[from]) {
      if (t.to == to) {
        return t.weight;
      }
    }
    throw std::invalid_argument("No such edge");
  }

  const std::vector<Edge> &neighbors(int v) { return graph[v]; }
};

int main() {
  WeightedDigraph graph(3);
  graph.addEdge(0, 1, 1);
  graph.addEdge(1, 2, 2);
  graph.addEdge(2, 0, 3);
  graph.addEdge(2, 1, 4);

  cout << boolalpha << graph.hasEdge(0, 1) << endl; // true
  cout << boolalpha << graph.hasEdge(1, 0) << endl; // false

  for (const auto &edge : graph.neighbors(2)) {
    cout << "2 -> " << edge.to << ", wight: " << edge.weight << endl;
  }
  // 2 -> 0, wight: 3
  // 2 -> 1, wight: 4

  graph.removeEdge(0, 1);
  cout << boolalpha << graph.hasEdge(0, 1) << endl; // false

  return 0;
}