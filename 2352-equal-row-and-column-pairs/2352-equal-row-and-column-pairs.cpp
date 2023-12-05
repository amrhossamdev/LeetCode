class Solution {
public:
    int equalPairs(vector <vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> row, col;
            for (int j = 0; j < m; ++j) {
                row.push_back(grid[i][j]);
            }
            for (int c = 0; c < m; ++c) {
                col.clear();
                for (int r = 0; r < n; ++r) {
                    col.push_back(grid[r][c]);
                }
                ans += row == col;
            }
        }
        return ans;
    }
};