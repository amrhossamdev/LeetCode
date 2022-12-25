class Solution {
 public:
  vector<int> dp;
  int solve(int index,int n, vector<int> v) {
    if (index >= n) {
      return 0;
    }
    if (~dp[index]) return dp[index];
    int take = 0, leave = 0;
    take = v[index] + solve(index + 2,n, v);
    leave = solve(index + 1, n,v);
    return dp[index] = max(take, leave);
  }
  int rob(vector<int>& v) {
    dp.assign(1000, -1);
    return solve(0,(int)v.size(), v);
  }
};