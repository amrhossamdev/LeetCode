class Solution {
 public:
  int minSubArrayLen(int k, vector<int>& v) {
    int l = 0, r = 0;
    int n = v.size();
    int mn = INT_MAX;
    int sum = 0;
    while (l < n) {
      while (r < n && sum < k) {
        sum += v[r++];
      }
      // cout << "sum " << sum << endl;
      // cout << l << " " << r << endl;
      if (sum >= k) {
        mn = min(mn, r - l);
      }
      sum -= v[l++];
    }
    return (mn == INT_MAX ? 0 : mn);
  }
};