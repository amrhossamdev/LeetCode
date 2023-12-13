class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>& graph,vector<set<int>>&child,int &ans){
        if(par!=-1 && child[node].find(par)==child[node].end()){
            ++ans;
        }
        for(auto to : graph[node]){
            if(to != par){
                dfs(to,node,graph,child,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& graph) {
        vector<set<int>>child(n+5);
        vector<vector<int>>adj(n+5);
        int m = graph.size();
        for(int i = 0;i<m;++i){
            child[graph[i][0]].insert(graph[i][1]);
            adj[graph[i][0]].push_back(graph[i][1]);
            adj[graph[i][1]].push_back(graph[i][0]);
        }
        int ans = 0;

        dfs(0,-1,adj,child,ans);
        
        return ans;
    }
};