class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, 0});
    map<int, bool> vis;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (cur.first == y) {
        cout << cur.second << endl;
        return cur.second;
      }

      if (cur.first % 11 == 0 && !vis[cur.first / 11]) {
        vis[cur.first / 11] = 1;
        q.push({cur.first / 11, cur.second + 1});
      }
      if (cur.first % 5 == 0 && !vis[cur.first / 5]) {
        vis[cur.first / 5] = 1;
        q.push({cur.first / 5, cur.second + 1});
      }
        
      if (!vis[cur.first + 1]) {
        vis[cur.first + 1] = 1;
        q.push({cur.first + 1, cur.second + 1});
      }
      if (!vis[cur.first - 1]) {
        vis[cur.first - 1] = 1;
        q.push({cur.first - 1, cur.second + 1});
      }
    }
    return 0;
  }
};