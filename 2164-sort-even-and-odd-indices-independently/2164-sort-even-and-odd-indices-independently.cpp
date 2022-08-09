class Solution {
 public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> e, o;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 != 0)
        o.push_back(nums[i]);
      else
        e.push_back(nums[i]);
    }
    sort(e.begin(), e.end());
    sort(o.rbegin(), o.rend());
    int n = min(e.size(), o.size());
    for (int i = 0; i < n; ++i) {
      ans.push_back(e[i]);
      ans.push_back(o[i]);
    }
    if (e.size() > o.size()) {
      ans.push_back(e[e.size() - 1]);
    } else if (o.size() > e.size()) {
      ans.push_back(o[o.size() - 1]);
    }

    return ans;
  }
};