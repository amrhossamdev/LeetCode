class Solution {
long long dp[105][105];
public:
    long long go(int i,int j,vector<vector<int>>& grid,int &n,int &m){
        if(grid[i][j] == 1)return -1e4;
        if(i == n- 1 && j == m -1)return 1;
        if(i>=n || j>=m) return -1e4;
        
        long long &ret = dp[i][j];
        if(~ret) return ret;
        int down  = 0, right = 0;
        if(i + 1 < n && grid[i + 1][j] != 1){
            down = go(i + 1,j,grid,n,m);
        }
        if(j + 1< m && grid[i][j + 1] != 1){
            right = go(i,j + 1,grid,n,m);
        }
        return ret = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        ans = max(ans,go(0,0,grid,n,m));
        return ans;
    }
};