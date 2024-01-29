class Solution {
 public:
  vector<vector<int>> ans;

  void rec(int idx, int n, int sum, vector<int>& tmp, vector<int>& v,
           int target) {
    if (sum > target || idx >= n) {
      return;
    }
    if (sum == target) {
      ans.push_back(tmp);
      return;
    }
    tmp.push_back(v[idx]);
    rec(idx, n, sum + v[idx], tmp, v, target);
    tmp.pop_back();
    rec(idx + 1, n, sum, tmp, v, target);
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> tmp;
    int n = candidates.size();
    rec(0, n, 0, tmp, candidates, target);
    return ans;
  }
};