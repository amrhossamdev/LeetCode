class Solution {
 public:
  int subsetXORSum(vector<int>& v) {
    int sum = 0;
    int n = v.size();
    for (int msk = 0; msk < (1 << n); ++msk) {
      int res = 0;
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          res ^= v[i];
        }
      }
      sum += res;
    }
    return sum;
  }
};