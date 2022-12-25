class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end());
    int n = cost.size();
    int ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (cnt < 2) {
        ans += cost[i];
        ++cnt;
      } else {
        cnt = 0;
      }
    }
      return ans;
  }
};