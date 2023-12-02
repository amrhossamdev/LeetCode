class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      mp[nums[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (mp[k - nums[i]]) {
        if (k - nums[i] == nums[i] && mp[nums[i]] >= 2) {
          ++ans;
        } else if (k - nums[i] != nums[i] && mp[nums[i]]) {
          ++ans;
        } else {
          continue;
        }
        mp[k - nums[i]]--;
        mp[nums[i]]--;
      }
    }
    return ans;
  }
};