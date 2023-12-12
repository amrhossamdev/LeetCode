class Solution {
public:

    int minFallingPathSum(vector <vector<int>> &matrix) {
        int n = matrix.size();
        vector <vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j] +
                           min({
                                       dp[i + 1][max(0, j - 1)],
                                       dp[i + 1][j],
                                       dp[i + 1][min(n - 1, j + 1)]
                               });
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};