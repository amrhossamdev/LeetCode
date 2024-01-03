class Solution {
public:
    
    void dfs(int node,vector<bool> &vis,vector<vector<int>>&adj){
        vis[node] = 1;;
        for(auto to:adj[node]){
            if(!vis[to]){
                dfs(to,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>>adj(n+1);
        vector<bool>vis(n+1,0);
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int ans =0;
        for(int i = 0;i<n;++i){
            if(!vis[i]){
                ++ans;
                dfs(i,vis,adj);
            }
        }
       return ans;        
        
        
    }
};