class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    set < vector<int>> st;
    for (int msk = 1; msk < (1 << n); ++msk) {
      vector<int> subset;
      bool check = true;
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          subset.push_back(nums[i]);
        }
      }
      if (subset.size() < 2) continue;
      for (int j = 1; j < subset.size(); ++j) {
        if (subset[j - 1] > subset[j]) {
          check = false;
          break;
        }
      }

      if (st.find(subset) == st.end()) {
        if (check) ans.push_back(subset);
        st.insert(subset);
      }
    }
    return ans;
  }
};