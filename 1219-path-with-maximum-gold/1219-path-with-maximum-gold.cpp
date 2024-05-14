class Solution {
 public:
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, 1, -1, 0};

  bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 0);
  }

  int solve(int i, int j, int n, int m, vector<vector<int>> &grid,
            vector<vector<bool>> &vis) {
    if (!isValid(i, j, n, m, grid) || vis[i][j]) return 0;
    vis[i][j] = true;
    int ret = 0;
    for (int k = 0; k < 4; ++k) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      ret = max(ret, grid[i][j] + solve(nx, ny, n, m, grid, vis));
    }
    vis[i][j] = 0;
    return ret;
  }
  int getMaximumGold(vector<vector<int>> &grid) {
    int ans = 0;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 0) ans = max(ans, solve(i, j, n, m, grid, vis));
      }
    }
    return ans;
  }
};