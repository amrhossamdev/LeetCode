class Solution {
public:
    bool vis[51][51];

    bool check(int i, int j, int n, int m, vector <vector<int>> &g) {
        return (i >= 0 && i < n && j < m && j >= 0 && g[i][j] == 1);
    }

    int dfs(int i, int j, int n, int m, vector <vector<int>> &g) {
        if (!check(i, j, n, m, g))return 0;
        g[i][j] = 0;
        return 1 + dfs(i + 1, j, n, m, g) +
               dfs(i - 1, j, n, m, g) +
               dfs(i, j + 1, n, m, g) +
               dfs(i, j - 1, n, m, g);

        return 0;
    }

    int maxAreaOfIsland(vector <vector<int>> &g) {
        int n = g.size();
        int m = g[0].size();
        int ans = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 1) {
                    int cnt = dfs(i, j, n, m, g);
                    mx = max(cnt, mx);

                }

            }
        }
        return mx;
    }

};