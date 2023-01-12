class Solution {
 public:
  vector<int> adj[100005];
  int freq[100005][26];
  void dfs(int node, int par, string& label) {
    freq[node][label[node]-'a']++;
    for (auto to : adj[node]) {
      if (to != par) {
        dfs(to,node,label);
        for (int i = 0; i < 26; i++) {
          freq[node][i] += freq[to][i];
        }
      }
    }
  }
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    for (int i = 0; i < edges.size(); ++i) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(0, -1, labels);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      ans[i] = freq[i][labels[i] - 'a'];
    }
    return ans;
  }
};