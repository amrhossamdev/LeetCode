class Solution {
public:

    bool willGetRotten(int i, int j, vector <vector<int>> &grid, int &n, int &m) {
        bool ch = 0;
        if (i - 1 >= 0) {
            ch |= grid[i - 1][j] == 2;
        }
        if (j - 1 >= 0) {
            ch |= grid[i][j - 1] == 2;
        }
        if (i + 1 < n) {
            ch |= grid[i + 1][j] == 2;
        }
        if (j + 1 < m) {
            ch |= grid[i][j + 1] == 2;
        }
        return ch;
    }

    int orangesRotting(vector <vector<int>> &grid) {
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                fresh += grid[i][j] == 1;
            }
        }

        for (int min = 1; min <= 100 && fresh > 0; min++) {
            bool ch = 0;
            vector <pair<int, int>> updates;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 1) {
                        if (willGetRotten(i, j, grid, n, m)) {
                            fresh--;
                            updates.push_back({i, j});
                        }

                    }
                }
            }
            for (int i = 0; i < updates.size(); ++i) {
                grid[updates[i].first][updates[i].second] = 2;
            }
            if (!fresh) return min;
        }
        return (fresh > 0 ? -1 : 0);
    }
};