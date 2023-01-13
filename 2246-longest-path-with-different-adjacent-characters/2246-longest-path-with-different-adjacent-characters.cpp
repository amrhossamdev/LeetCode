class Solution {
 public:
  vector<int> adj[100005];
  int ans = 0;
  int dfs(int node, int &globalMax, string &s) {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    pq.push(0);

    for (auto &child : adj[node]) {
      int maxFromChild = dfs(child, globalMax, s);

      if (s[child] != s[node]) {
        pq.push(maxFromChild);
        pq.pop();
      }
    }

    int secondMax = pq.top();
    pq.pop();
    int firstMax = pq.top();
    pq.pop();
    globalMax = max(globalMax, 1 + firstMax + secondMax);

    return 1 + firstMax;
  }
  int longestPath(vector<int> &parent, string &s) {
    int n = parent.size();
    for (int i = 1; i < n; ++i) {
      adj[parent[i]].push_back(i);
    }
    int mx = 0;
    dfs(0, mx, s);
    return mx;
  }
};