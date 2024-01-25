class Solution {
public:
    int go(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        int n = s1.size();
        int m = s2.size();
        if(i>=n || j >=m)return 0;
        int &ret= dp[i][j];
        if(~ret) return ret;
        if(s1[i] == s2[j]){
            ret = max(ret,1 + go(i + 1,j + 1,s1,s2,dp));
            ret = max(ret,go(i + 1,j,s1,s2,dp));
        }else{
            ret = max(ret,go(i+1,j+1,s1,s2,dp));
            ret = max(ret,go(i,j + 1,s1,s2,dp));
            ret = max(ret,go(i+1,j,s1,s2,dp));
        }
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = go(0,0,text1,text2,dp);
        return ans;
        
    }
};