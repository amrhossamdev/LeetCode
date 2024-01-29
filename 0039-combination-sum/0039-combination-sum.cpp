class Solution {
 public:
  vector<vector<int>> ans;
  map<vector<int>, bool> mp;
  void rec(int idx, int n, int sum, vector<int> &tmp, vector<int>& v,
           int target) {
    if (sum > target) {
      return;
    }
    if (idx >= n) {
      if (sum == target) {
        if (!mp[tmp]) ans.push_back(tmp);
        mp[tmp] = 1;
      }
      return;
    }
    if (sum == target) {
      if (!mp[tmp]) ans.push_back(tmp);
      mp[tmp] = 1;
    }
    tmp.push_back(v[idx]);
    rec(idx, n, sum + v[idx], tmp, v, target);
    tmp.pop_back();

    rec(idx + 1, n, sum, tmp, v, target);
    if (idx + 1 < n) {
      tmp.push_back(v[idx]);
      rec(idx + 1, n, sum + v[idx], tmp, v, target);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> tmp;
    int n = candidates.size();
    rec(0, n, 0, tmp, candidates, target);
    return ans;
  }
};