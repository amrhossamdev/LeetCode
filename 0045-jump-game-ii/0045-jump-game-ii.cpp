class Solution {
public:
    long long dp[10005];

    long long go(int index, vector<int> &v, int &n) {
        if (index == n) { return 0;}
        if(index > n || v[index] == 0)return INT_MAX;
        long long &ret = dp[index];
        if (~ret) return dp[index];
        ret = INT_MAX;
        for(int i = 1;i<=v[index];++i){
            ret = min(ret,1 + go(index + i,v,n));  
        }
        return ret;
    }

    int jump(vector<int> &v) {
        int n = v.size();
        memset(dp, -1, sizeof(dp));
        n--;
        return go(0, v, n);
    }
};