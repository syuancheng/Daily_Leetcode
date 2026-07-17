# Data Structures

Reusable data structure implementations and basic operation templates live here.

Use this directory for code organized around a concrete structure, such as linked
lists, trees, graphs, arrays, or probabilistic structures. Keep general language
notes and problem-solving tips in `cpp_notes/`.

## Graph

- [BFS traversal templates](graph/bfs_traversal.cpp): plain queue BFS,
  layer-by-layer BFS, and state-carrying BFS.
- [Graph traversal templates](graph/graph_traversal.cpp): vertex traversal with
  `visited`, edge traversal with `edgeVisited`, and simple path enumeration with
  `onPath`.

## Backtracking

- [Backtracking search shapes](backtracking/backtracking_search_shapes.cpp):
  compare choose/permutation templates across distinct values, duplicate values,
  and reusable values.
- [Permutations with repetition](backtracking/permutations_with_repetition.cpp):
  generate length-`k` sequences where each position can reuse any input value.
