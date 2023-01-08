class Solution {
 public:
  int maxPoints(vector<vector<int>>& v) {
    int n = v.size();
    int m = 2;
    int ans = 0;

    double x1, y1, x2, y2;
    for (int i = 0; i < n - 1; ++i) {
      map<double, int> mp;
      int cnt = 0;
      for (int j = i + 1; j < n; ++j) {
        x1 = v[i][0], y1 = v[i][1];
        x2 = v[j][0], y2 = v[j][1];
        if (x1 - x2 != 0) {
          double slope = (y2 - y1) / (x2 - x1);
          mp[slope]++;
        } else {
          ++cnt;
        }
      }
      int mx = cnt;
      for (auto i : mp) {
        mx = max(mx, i.second);
      }
      ans = max(ans, mx);
    }
    return ans + 1;
  }
};