class Solution {
 public:
  vector<int> adj[100001];

  int dfs(int node, int par, vector<bool>& hasApple) {
    int ans = 0;
    for (auto to : adj[node]) {
      if (to != par) {
        ans += dfs(to, node, hasApple);
      }
    }
    if (hasApple[node] || ans) ans += 2;
    return ans;
  }
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    return max(0, dfs(0, -1, hasApple) - 2);
  }
};