class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& v) {
    int n = v.size();
    sort(v.begin(), v.end());
    auto prev = v[0];
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      if (v[i][0] > prev[1])
        ++ans, prev = v[i];
      else {
        prev[1] = min(prev[1], v[i][1]);
      }
    }

    return ans;
  }
};