class Solution {
public:
    int dp[2550][2550];
    int go(int idx,int prev,int &n,vector<int>&v){
        if(idx >=n){
            if(idx == n)return 0;
            return -2e4;
        }
        int &ret =dp[idx][prev + 1];
        if(~ret) return ret;
        if(prev == -1 || v[prev] < v[idx]){
          ret = 1 + go(idx + 1,idx,n,v);
        }
        ret = max(ret,go(idx + 1,prev,n,v));
        return ret;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<=n;++i){
            for(int j = 0;j<=n;++j){
                dp[i][j] = -1;
            }
        }
        int ans = go(0,-1,n,nums);
        return ans;
    }
};