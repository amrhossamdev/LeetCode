class Solution {
 public:
  unordered_map<int,bool>vis;
  vector<int> perm;
  vector<vector<int>> ans;
  void backtrack(vector<int>& v, int sz) {
    if (sz == v.size()) {
      ans.push_back(perm);
      return;
    }
    for (int i = 0; i < v.size(); ++i) {
      if (!vis[v[i]]) {
        perm.push_back(v[i]);
        vis[v[i]] = true;
        backtrack(v, sz + 1);
        perm.pop_back();
        vis[v[i]] = false;
      }
    }
  }
  vector<vector<int>> permute(vector<int>& v) {
    backtrack(v, 0);
    return ans;
  }
};