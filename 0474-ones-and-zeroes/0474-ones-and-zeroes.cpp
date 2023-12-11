class Solution {
public:
    int dp[601][101][101];
    int calc(string &s,bool isZero){
        int ans = 0;
        int n = s.size();
        for(int i = 0;i<n;++i){
            if(isZero){
                ans+=s[i] == '0';
            }else{
                ans+=s[i] == '1';
            }
        }
        return ans;
    }
    int solve(int idx,int zeros,int ones,vector<string>&strs,int &n,int &m){
        if(idx>=strs.size()){
            return 0;
        }
        int &ret = dp[idx][zeros][ones];
        if(~ret)return ret;
        ret = 0;
        int o = calc(strs[idx],0);
        int z = calc(strs[idx],1);
        if(o + ones<=n && z+zeros<=m){
           ret = 1+solve(idx+1,zeros+calc(strs[idx],1),ones+calc(strs[idx],0),strs,n,m);
        }
        ret = max(ret,solve(idx+1,zeros,ones,strs,n,m));
        return ret;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        memset(dp,-1,sizeof(dp));
        int o = calc(strs[0],0);
        int z = calc(strs[0],1);
        int ans  = solve(0,0,0,strs,n,m);
     
        return ans;
        
    }
};