class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<pair<int,int>,int>mp;
        vector<int>deg(n,0);
        for(int i = 0;i<roads.size();++i){
            int u = roads[i][0], v = roads[i][1];
            mp[{u,v}]++;
            deg[u]++,deg[v]++;
        }
        int ans = 0;
        for(int i = 0;i<n - 1;++i){
            for(int j = i + 1;j<n;++j){
                int res = deg[i] + deg[j];
                res -= mp[{i,j}] + mp[{j,i}];
                ans = max(ans,res);
            }
        }
        return ans;
    }
};