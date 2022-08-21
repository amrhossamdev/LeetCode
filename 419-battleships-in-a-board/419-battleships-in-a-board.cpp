class Solution {
 public:
  bool isValid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
  }
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, 1, -1, 0};
  void dfs(int i, int j, vector<vector<char>>& g, int n, int m) {
    if (!isValid(i, j, n, m) || g[i][j] == '.') return;
    g[i][j] = 'v';  // visited
    for (int k = 0; k < 4; ++k) {
      int r = i + dx[k];
      int c = j + dy[k];
      if (isValid(r, c, n, m) && g[r][c] != 'v') {
        dfs(r, c, g, n, m);
      }
    }
  }
  int countBattleships(vector<vector<char>>& g) {
    int n = g.size();
    int m = g[0].size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == 'X') {
          ++ans;
          dfs(i, j, g, n, m);
        }
      }
    }
    return ans;
  }
};