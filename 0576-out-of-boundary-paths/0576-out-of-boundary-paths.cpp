class Solution {
 public:
  int h, w;
  long long dp[51][51][51];
  bool isValid(int i, int j) { return (i >= 0 && i < h && j >= 0 && j < w); }
  int mod = 1e9 + 7;
  int maxMoves;
  long long go(int i, int j, int moves) {
    if (!isValid(i, j)) {
      return 1;
    }
    if (moves > maxMoves) return 0;
    long long &ret = dp[i][j][moves];
    if (~ret) return ret;
    ret = 0;
    ret = (ret + go(i + 1, j, moves + 1)) % mod;
    ret = (ret + go(i, j + 1, moves + 1)) % mod;
    ret = (ret + go(i - 1, j, moves + 1)) % mod;
    ret = (ret + go(i, j - 1, moves + 1)) % mod;
    return ret;
  }
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(dp, -1, sizeof(dp));
    h = m, w = n;
    maxMoves = maxMove;
    long long ans = go(startRow, startColumn, 1);
    return ans;
  }
};