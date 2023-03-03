class Solution {
public:
    long long dp[205][205];
    long long go(int i,int j,int &n,int &m,vector<vector<int>>& grid){
        if(i >= n  || j >=m)return 5e3;
        if(i == n -1 && j == m - 1){return grid[i][j];}
        long long &ret = dp[i][j];
        if(~ret)return ret;
        ret = 0;
        long long down = INT_MAX, right = INT_MAX;
        if(i + 1 < n){
            down = grid[i][j] + go(i + 1,j,n,m,grid);
        }
        if(j+ 1 < m){
            right = grid[i][j] + go(i,j + 1,n,m,grid);
        }
        ret += min(down,right);
        return ret;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        for(int i =0;i<=n;++i){
            for(int j=0;j<=m;++j){
                dp[i][j] = -1;
            }
        }
        return go(0,0,n,m,grid);
      
    
    }
};