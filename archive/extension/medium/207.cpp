class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &pre) {
    unordered_map<int, vector<int>> adj;
    for (auto &p : pre) {
      adj[p[1]].push_back(p[0]);
    }

    vector<int> vis(numCourses, 0);
    for (int edge = 0; edge < numCourses; ++edge) {
      if (!vis[edge]) {
        if (cycle(edge, vis, adj)) {
          return false;
        }
      }
    }

    return true;
  }

  bool cycle(int edge, vector<int> &vis, unordered_map<int, vector<int>> &adj) {
    vis[edge] = 1;
    for (int nei : adj[edge]) {
      if (!vis[nei]) {
        if (cycle(nei, vis, adj)) {
          return true;
        }
      } else if (vis[nei] == 1) {
        return true;
      }
    }

    vis[edge] = 2;
    return false;
  }
};
