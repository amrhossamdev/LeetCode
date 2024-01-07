class Solution {
 public:
  int minOperations(vector<int>& v, int k) {
    int n = v.size();
    int ans = 0;
    for (int msk = 0; msk < 30; ++msk) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (v[i] & (1 << msk)) {
          ++cnt;
        }
      }
      if (k & (1 << msk)) {
        if (cnt % 2 == 0) ++ans;
      } else {
        if (cnt % 2 != 0) ++ans;
      }
    }
    return ans;
  }
};