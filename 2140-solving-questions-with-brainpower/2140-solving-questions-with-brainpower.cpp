class Solution {
 public:
  long long const N = 1e5 + 5;
  vector<long long> dp;
  long long solve(vector<vector<int>>& questions, int index) {
    if (index >= questions.size()) {
      return 0;
    }
    if (~dp[index]) return dp[index];
    long long leave = 0,take = 0;
    
    take = questions[index][0] + solve(questions, index +questions[index][1] + 1);
    leave = solve(questions,index + 1);
    return dp[index] = max(leave, take);
  }
  long long mostPoints(vector<vector<int>>& questions) {
    dp.assign(N,-1);
    return solve(questions, 0);
  }
};