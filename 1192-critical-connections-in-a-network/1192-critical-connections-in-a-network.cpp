class Solution {
public:
    vector<bool> visited;
    vector<int> tin, low;
    int timer;
    vector <vector<int>> ans;
    vector <vector<int>> adj;

    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for (int to: adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v]) {
                    ans.push_back({v, to});
                }
            }
        }
    }

    vector <vector<int>> criticalConnections(int n, vector <vector<int>> &connections) {
        adj.resize(n);
        map<pair<int, int>, bool> vis;
        int m = connections.size();
        for (int i = 0; i < m; ++i) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        timer = 0;
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(i);
        }

        return ans;
    }
};