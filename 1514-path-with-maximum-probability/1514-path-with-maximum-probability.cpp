class Solution {
public:
    double maxProbability(int n, vector <vector<int>> &g, vector<double> &succProb, int start, int end) {
        vector <pair<int, double>> adj[n];
        for (int i = 0; i < g.size(); ++i) {
            adj[g[i][0]].push_back({g[i][1], succProb[i]});
            adj[g[i][1]].push_back({g[i][0], succProb[i]});
        }
        vector<double> dist(n + 1, 0.0);
        dist[start] = 1.0;
        priority_queue <pair<double, int>> pq;
        pq.push({1.0, start});//<cost,start node>
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            // vis[node] = true;
            for (auto &v:adj[node]) {
                double cost = v.second;
                if (dist[node] * cost > dist[v.first]) {
                    dist[v.first] = dist[node] * cost;
                    pq.push({dist[v.first], v.first});
                }
            }
        }

        return dist[end];
    }
};