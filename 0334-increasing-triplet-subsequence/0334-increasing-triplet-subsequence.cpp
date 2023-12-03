class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;
    int pre[n];
    int suff[n];
    pre[0] = nums[0];
    suff[n - 1] = nums[n - 1];
    for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
      pre[i] = min(pre[i - 1], nums[i]);
      suff[j] = max(suff[j + 1], nums[j]);
    }
    for (int i = 1; i < n - 1; ++i) {
      if (pre[i - 1] < nums[i] && nums[i] < suff[i + 1]) {
        return true;
      }
    }
    return false;
  }
};