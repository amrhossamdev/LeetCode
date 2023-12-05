class Solution {
public:
    int dp[1005];
    int go(int idx,int &n,vector<int> &v){
        if(idx>=n)return 0;
        int &ret = dp[idx];
        if(~ret) return ret;
        ret = v[idx]+go(idx+1,n,v);
        ret = min(ret,v[idx]+ go(idx+2,n,v));
        
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n  = cost.size();
        int ans = min(go(0,n,cost),go(1,n,cost));
        return ans;
    }
};