class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,int &n,int &m,string &s1,string &s2){
        if(i == n){
            return m - j; // add reminder from s2
        }
        if(j == m){
            return n - i; // delete the reminder
        }
        int &ret = dp[i][j];
        if(~ret)return ret;
        if(s1[i] == s2[j]){
            return ret = solve(i + 1,j + 1,n,m,s1,s2);
        }
        int ch1 = 1 + solve(i + 1,j + 1,n,m,s1,s2); // replace s1[i] == s[j]
        int ch2 = 1 + solve(i, j+ 1,n,m,s1,s2); // insert s2[j] , before s1[i];
        int ch3 = 1 + solve(i + 1,j,n,m,s1,s2); // remve s1[i];
        return ret = min({ch1,ch2,ch3});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        for(int i  =0;i<n;++i){
            for(int j = 0;j<m;++j){
                dp[i][j] = -1;
            }
        }
        return solve(0,0,n,m,word1,word2);
    }
};