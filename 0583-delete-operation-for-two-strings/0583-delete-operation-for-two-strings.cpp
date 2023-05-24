class Solution {
public:
    int dp[501][501];
    int solve(int i,int j ,string &s1,string &s2,int &n,int &m){
        if(i == n){
            return m - j;
        }
        if(j == m){
            return n - i;
        }
        int &ret = dp[i][j];
        if(~ret) return ret;
        if(s1[i] == s2[j]){
            return ret = solve(i + 1,j + 1,s1,s2,n,m);
        }
        int ch1 = 1 + solve(i + 1,j,s1,s2,n,m);
        int ch2 = 1 + solve(i,j+1,s1,s2,n,m);
        return ret= min(ch1,ch2);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        for(int i = 0;i<=n;++i){
            for(int j = 0;j<=m;++j){
                dp[i][j] = -1;
            }
        }
        return solve(0,0,word1,word2,n,m);
    }
};