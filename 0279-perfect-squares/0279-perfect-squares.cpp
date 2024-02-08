class Solution {
 public:
  vector<int> v;

  
  int go(int sum,vector<int> &dp) {
    if(sum==0)return 0;
    int &ret = dp[sum];
    if (~ret) return ret;
    ret = 1e9;
    for(int i =1;i*i<=sum;++i){
    	ret = min(ret,1+ go(sum-(i*i),dp));
    }
    return ret;
  }
  int numSquares(int n) {
    for (int i = 1; i <= n; ++i) {
      v.push_back(i * i);
    }
    vector<int>dp(n + 1,-1);
    int ans = go(n,dp);
    return ans;
  }
};