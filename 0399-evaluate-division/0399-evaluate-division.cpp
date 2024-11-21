class Solution {
public:
    void dfs(string a,string b,map<string,vector<pair<string,double>>> &adj,map<string,bool>&vis, double temp, double &ans){
        vis[a] = true;
        if(a == b){
            ans = temp;
            return;
        }
        for(auto to : adj[a]){
            if(vis.find(to.first) == vis.end()){
                dfs(to.first,b,adj,vis,temp * to.second,ans);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        int n = equations.size();
        map<string,vector<pair<string,double>>> adj;
        map<string,bool>vis;
        for(int i = 0;i<n;++i){
            string u = equations[i][0], v = equations[i][1];
            long double cost = values[i];
            adj[u].push_back(make_pair(v,cost));
            adj[v].push_back(make_pair(u, 1.0 / cost));
        }
        
        for(int i = 0;i<queries.size();++i){
            string u = queries[i][0], v = queries[i][1];
            double res = -1;
            if(adj.find(u) != adj.end()){
              dfs(u,v,adj,vis,1.0,res);
            }
            ans.push_back(res);
            vis.clear();
        }
        return ans;
    }
};