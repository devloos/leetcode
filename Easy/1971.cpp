class Solution {
 public:
  bool dfs(
      int source, int destination, unordered_map<int, vector<int>> &map,
      vector<int> &visited) {
    if (source == destination) {
      return true;
    }

    if (visited[source]) {
      return false;
    }

    visited[source] = true;

    for (auto &edge : map[source]) {
      if (dfs(edge, destination, map, visited)) {
        return true;
      }
    }

    return false;
  }

  bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    unordered_map<int, vector<int>> map;
    vector<int> visited(n, false);

    for (auto &edge : edges) {
      map[edge[0]].push_back(edge[1]);
      map[edge[1]].push_back(edge[0]);
    }

    return dfs(source, destination, map, visited);
  }
};