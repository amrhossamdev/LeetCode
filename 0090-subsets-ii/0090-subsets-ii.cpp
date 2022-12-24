class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> ans;
    map<vector<int>,bool>mp;
    for (int msk = 0; msk < 1 << n; ++msk) {
      vector<int> subset = {};
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          subset.push_back(v[i]);
        }
      }
      sort(subset.begin(),subset.end());
      if (!mp[subset]) ans.push_back(subset), mp[subset] = 1;
    }
    return ans;
  }
};